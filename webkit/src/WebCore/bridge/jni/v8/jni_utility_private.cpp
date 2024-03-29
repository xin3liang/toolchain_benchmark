/*
 * Copyright 2009, The Android Open Source Project
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
#include "jni_utility_private.h"

#include "jni_runtime.h"
#include "jni_npobject.h"

namespace JSC {

namespace Bindings {

jvalue convertNPVariantToJValue(NPVariant value, JNIType jniType, const char* javaClassName)
{
    jvalue result;
    NPVariantType type = value.type;

    switch (jniType) {
    case array_type:
    case object_type:
        {
            result.l = (jobject)0;

            // First see if we have a Java instance.
            if (type == NPVariantType_Object) {
                NPObject* objectImp = NPVARIANT_TO_OBJECT(value);
                if (JavaInstance* instance = ExtractJavaInstance(objectImp))
                    result.l = instance->getLocalRef();
            }

            // Now convert value to a string if the target type is a java.lang.string, and we're not
            // converting from a Null.
            if (result.l == 0 && strcmp(javaClassName, "java.lang.String") == 0) {
#ifdef CONVERT_NULL_TO_EMPTY_STRING
                if (type == NPVariantType_Null) {
                    JNIEnv *env = getJNIEnv();
                    jchar buf[2];
                    jobject javaString = env->functions->NewString (env, buf, 0);
                    result.l = javaString;
                }
                else
#else
                if (type == NPVariantType_String) {
#endif
                    NPString src = NPVARIANT_TO_STRING(value);
                    JNIEnv *env = getJNIEnv();
                    jobject javaString = env->NewStringUTF(src.UTF8Characters);
                    result.l = javaString;
                }
            } else if (result.l == 0)
                bzero (&result, sizeof(jvalue)); // Handle it the same as a void case
        }
        break;

    case boolean_type:
        {
            if (type == NPVariantType_Bool)
                result.z = NPVARIANT_TO_BOOLEAN(value);
            else
                bzero(&result, sizeof(jvalue));  // as void case
        }
        break;

    case byte_type:
        {
            if (type == NPVariantType_Int32)
                result.b = (char)NPVARIANT_TO_INT32(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case char_type:
        {
            if (type == NPVariantType_Int32)
                result.c = (char)NPVARIANT_TO_INT32(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case short_type:
        {
            if (type == NPVariantType_Int32)
                result.s = (jshort)NPVARIANT_TO_INT32(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case int_type:
        {
            if (type == NPVariantType_Int32)
                result.i = (jint)NPVARIANT_TO_INT32(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case long_type:
        {
            if (type == NPVariantType_Int32)
                result.j = (jlong)NPVARIANT_TO_INT32(value);
            else if (type == NPVariantType_Double)
                result.j = (jlong)NPVARIANT_TO_DOUBLE(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case float_type:
        {
            if (type == NPVariantType_Int32)
                result.j = (jfloat)NPVARIANT_TO_INT32(value);
            else if (type == NPVariantType_Double)
                result.j = (jfloat)NPVARIANT_TO_DOUBLE(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

    case double_type:
        {
            if (type == NPVariantType_Int32)
                result.j = (jdouble)NPVARIANT_TO_INT32(value);
            else if (type == NPVariantType_Double)
                result.j = (jdouble)NPVARIANT_TO_DOUBLE(value);
            else
                bzero(&result, sizeof(jvalue));
        }
        break;

        break;

    case invalid_type:
    default:
    case void_type:
        {
            bzero(&result, sizeof(jvalue));
        }
        break;
    }
    return result;
}


void convertJValueToNPVariant(jvalue value, JNIType jniType, const char* javaTypeName, NPVariant* result)
{
    switch (jniType) {
    case void_type:
        {
            VOID_TO_NPVARIANT(*result);
        }
        break;

    case object_type:
        {
            if (value.l != 0) {
                if (strcmp(javaTypeName, "java.lang.String") == 0) {
                    const char* v = getCharactersFromJString((jstring)value.l);
                    // s is freed in NPN_ReleaseVariantValue (see npruntime.cpp)
                    const char* s = strdup(v);
                    releaseCharactersForJString((jstring)value.l, v);
                    STRINGZ_TO_NPVARIANT(s, *result);
                } else {
                    OBJECT_TO_NPVARIANT(JavaInstanceToNPObject(new JavaInstance(value.l)), *result);
                }
            }
            else {
                VOID_TO_NPVARIANT(*result);
            }
        }
        break;

    case boolean_type:
        {
            BOOLEAN_TO_NPVARIANT(value.z, *result);
        }
        break;

    case byte_type:
        {
            INT32_TO_NPVARIANT(value.b, *result);
        }
        break;

    case char_type:
        {
            INT32_TO_NPVARIANT(value.c, *result);
        }
        break;

    case short_type:
        {
            INT32_TO_NPVARIANT(value.s, *result);
        }
        break;

    case int_type:
        {
            INT32_TO_NPVARIANT(value.i, *result);
        }
        break;

        // TODO: Check if cast to double is needed.
    case long_type:
        {
            DOUBLE_TO_NPVARIANT(value.j, *result);
        }
        break;

    case float_type:
        {
            DOUBLE_TO_NPVARIANT(value.f, *result);
        }
        break;

    case double_type:
        {
            DOUBLE_TO_NPVARIANT(value.d, *result);
        }
        break;

    case invalid_type:
    default:
        {
            VOID_TO_NPVARIANT(*result);
        }
        break;
    }
}

}  // end of namespace Bindings

} // end of namespace JSC
