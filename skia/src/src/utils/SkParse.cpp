/* libs/graphics/xml/SkParse.cpp
**
** Copyright 2006, The Android Open Source Project
**
** Licensed under the Apache License, Version 2.0 (the "License"); 
** you may not use this file except in compliance with the License. 
** You may obtain a copy of the License at 
**
**     http://www.apache.org/licenses/LICENSE-2.0 
**
** Unless required by applicable law or agreed to in writing, software 
** distributed under the License is distributed on an "AS IS" BASIS, 
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
** See the License for the specific language governing permissions and 
** limitations under the License.
*/

#include "SkParse.h"

static inline bool is_between(int c, int min, int max)
{
    return (unsigned)(c - min) <= (unsigned)(max - min);
}

static inline bool is_ws(int c)
{
    return is_between(c, 1, 32);
}

static inline bool is_digit(int c)
{
    return is_between(c, '0', '9');
}

static inline bool is_sep(int c)
{
    return is_ws(c) || c == ',' || c == ';';
}

static int to_hex(int c)
{
    if (is_digit(c))
        return c - '0';

    c |= 0x20;  // make us lower-case
    if (is_between(c, 'a', 'f'))
        return c + 10 - 'a';
    else
        return -1;
}

static inline bool is_hex(int c)
{
    return to_hex(c) >= 0;
}

static const char* skip_ws(const char str[])
{
    SkASSERT(str);
    while (is_ws(*str))
        str++;
    return str;
}

static const char* skip_sep(const char str[])
{
    SkASSERT(str);
    while (is_sep(*str))
        str++;
    return str;
}

int SkParse::Count(const char str[]) 
{
    char c;
    int count = 0;
    goto skipLeading;
    do {
        count++;
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (is_sep(c) == false);
skipLeading:
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (is_sep(c));
    } while (true);
goHome:
    return count;
}

int SkParse::Count(const char str[], char separator) 
{
    char c;
    int count = 0;
    goto skipLeading;
    do {
        count++;
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (c != separator);
skipLeading:
        do {
            if ((c = *str++) == '\0')
                goto goHome;
        } while (c == separator);
    } while (true);
goHome:
    return count;
}

const char* SkParse::FindHex(const char str[], uint32_t* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    if (!is_hex(*str))
        return NULL;

    uint32_t n = 0;
    int max_digits = 8;
    int digit;

    while ((digit = to_hex(*str)) >= 0)
    {
        if (--max_digits < 0)
            return NULL;
        n = (n << 4) | digit;
        str += 1;
    }

    if (*str == 0 || is_ws(*str))
    {
        if (value)
            *value = n;
        return str;
    }
    return false;
}

const char* SkParse::FindS32(const char str[], int32_t* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    int sign = 0;
    if (*str == '-')
    {
        sign = -1;
        str += 1;
    }

    if (!is_digit(*str))
        return NULL;

    int n = 0;
    while (is_digit(*str))
    {
        n = 10*n + *str - '0';
        str += 1;
    }
    if (value)
        *value = (n ^ sign) - sign;
    return str;
}

const char* SkParse::FindMSec(const char str[], SkMSec* value)
{
    SkASSERT(str);
    str = skip_ws(str);

    int sign = 0;
    if (*str == '-')
    {
        sign = -1;
        str += 1;
    }

    if (!is_digit(*str))
        return NULL;

    int n = 0;
    while (is_digit(*str))
    {
        n = 10*n + *str - '0';
        str += 1;
    }
    int remaining10s = 3;
    if (*str == '.') {
        str++;
        while (is_digit(*str))
        {
            n = 10*n + *str - '0';
            str += 1;
            if (--remaining10s == 0)
                break;
        }
    }
    while (--remaining10s >= 0)
        n *= 10;
    if (value)
        *value = (n ^ sign) - sign;
    return str;
}

const char* SkParse::FindScalar(const char str[], SkScalar* value) {
    SkASSERT(str);
    str = skip_ws(str);
#ifdef SK_SCALAR_IS_FLOAT
    char* stop;
    float v = ::strtof(str, &stop);
    if (str == stop) {
        return NULL;
    }
    if (value) {
        *value = v;
    }
    return stop;
#else
    int sign = 0;
    if (*str == '-')
    {
        sign = -1;
        str += 1;
    }

    if (!is_digit(*str) && *str != '.')
        return NULL;

    int n = 0;
    while (is_digit(*str))
    {
        n = 10*n + *str - '0';
        if (n > 0x7FFF)
            return NULL;
        str += 1;
    }
    n <<= 16;

    if (*str == '.')
    {
        static const int gFractions[] = { (1 << 24)  / 10, (1 << 24)  / 100, (1 << 24)  / 1000, 
            (1 << 24)  / 10000, (1 << 24)  / 100000 };
        str += 1;
        int d = 0;
        const int* fraction = gFractions;
        const int* end = &fraction[SK_ARRAY_COUNT(gFractions)];
        while (is_digit(*str) && fraction < end)
            d += (*str++ - '0') * *fraction++;
        d += 0x80; // round
        n += d >> 8;
    }
    while (is_digit(*str))
        str += 1;
    if (value)
    {
        n = (n ^ sign) - sign;  // apply the sign
        *value = SkFixedToScalar(n);
    }
#endif
    return str;
}

const char* SkParse::FindScalars(const char str[], SkScalar value[], int count)
{
    SkASSERT(count >= 0);

    if (count > 0)
    {
        for (;;)
        {
            str = SkParse::FindScalar(str, value);
            if (--count == 0 || str == NULL)
                break;

            // keep going
            str = skip_sep(str);
            if (value)
                value += 1;
        }
    }
    return str;
}

static bool lookup_str(const char str[], const char** table, int count)
{
    while (--count >= 0)
        if (!strcmp(str, table[count]))
            return true;
    return false;
}

bool SkParse::FindBool(const char str[], bool* value)
{
    static const char* gYes[] = { "yes", "1", "true" };
    static const char* gNo[] = { "no", "0", "false" };

    if (lookup_str(str, gYes, SK_ARRAY_COUNT(gYes)))
    {
        if (value) *value = true;
        return true;
    }
    else if (lookup_str(str, gNo, SK_ARRAY_COUNT(gNo)))
    {
        if (value) *value = false;
        return true;
    }
    return false;
}

int SkParse::FindList(const char target[], const char list[])
{
    size_t  len = strlen(target);
    int     index = 0;

    for (;;)
    {
        const char* end = strchr(list, ',');
        size_t      entryLen;

        if (end == NULL) // last entry
            entryLen = strlen(list);
        else
            entryLen = end - list;

        if (entryLen == len && memcmp(target, list, len) == 0)
            return index;
        if (end == NULL)
            break;

        list = end + 1; // skip the ','
        index += 1;
    }
    return -1;
}

#ifdef SK_SUPPORT_UNITTEST
void SkParse::UnitTest() 
{
    // !!! additional parse tests go here
    SkParse::TestColor();
}
#endif
