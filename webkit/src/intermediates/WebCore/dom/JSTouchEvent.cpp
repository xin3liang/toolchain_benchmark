/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"

#if ENABLE(TOUCH_EVENTS)

#include "JSTouchEvent.h"

#include "JSDOMWindow.h"
#include "JSTouchList.h"
#include "TouchEvent.h"
#include "TouchList.h"
#include <runtime/Error.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSTouchEvent);

/* Hash table */

static const HashTableValue JSTouchEventTableValues[5] =
{
    { "touches", DontDelete|ReadOnly, (intptr_t)jsTouchEventTouches, (intptr_t)0 },
    { "targetTouches", DontDelete|ReadOnly, (intptr_t)jsTouchEventTargetTouches, (intptr_t)0 },
    { "changedTouches", DontDelete|ReadOnly, (intptr_t)jsTouchEventChangedTouches, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsTouchEventConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTouchEventTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSTouchEventTableValues, 0 };
#else
    { 10, 7, JSTouchEventTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSTouchEventConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTouchEventConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSTouchEventConstructorTableValues, 0 };
#else
    { 1, 0, JSTouchEventConstructorTableValues, 0 };
#endif

class JSTouchEventConstructor : public DOMConstructorObject {
public:
    JSTouchEventConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSTouchEventConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSTouchEventPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSTouchEventConstructor::s_info = { "TouchEventConstructor", 0, &JSTouchEventConstructorTable, 0 };

bool JSTouchEventConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTouchEventConstructor, DOMObject>(exec, &JSTouchEventConstructorTable, this, propertyName, slot);
}

bool JSTouchEventConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSTouchEventConstructor, DOMObject>(exec, &JSTouchEventConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSTouchEventPrototypeTableValues[2] =
{
    { "initTouchEvent", DontDelete|Function, (intptr_t)jsTouchEventPrototypeFunctionInitTouchEvent, (intptr_t)9 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTouchEventPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSTouchEventPrototypeTableValues, 0 };
#else
    { 2, 1, JSTouchEventPrototypeTableValues, 0 };
#endif

const ClassInfo JSTouchEventPrototype::s_info = { "TouchEventPrototype", 0, &JSTouchEventPrototypeTable, 0 };

JSObject* JSTouchEventPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSTouchEvent>(exec, globalObject);
}

bool JSTouchEventPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSTouchEventPrototypeTable, this, propertyName, slot);
}

bool JSTouchEventPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSTouchEventPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSTouchEvent::s_info = { "TouchEvent", &JSUIEvent::s_info, &JSTouchEventTable, 0 };

JSTouchEvent::JSTouchEvent(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<TouchEvent> impl)
    : JSUIEvent(structure, globalObject, impl)
{
}

JSObject* JSTouchEvent::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSTouchEventPrototype(JSTouchEventPrototype::createStructure(JSUIEventPrototype::self(exec, globalObject)));
}

bool JSTouchEvent::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTouchEvent, Base>(exec, &JSTouchEventTable, this, propertyName, slot);
}

bool JSTouchEvent::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSTouchEvent, Base>(exec, &JSTouchEventTable, this, propertyName, descriptor);
}

JSValue jsTouchEventTouches(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSTouchEvent* castedThis = static_cast<JSTouchEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    TouchEvent* imp = static_cast<TouchEvent*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->touches()));
}

JSValue jsTouchEventTargetTouches(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSTouchEvent* castedThis = static_cast<JSTouchEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    TouchEvent* imp = static_cast<TouchEvent*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->targetTouches()));
}

JSValue jsTouchEventChangedTouches(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSTouchEvent* castedThis = static_cast<JSTouchEvent*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    TouchEvent* imp = static_cast<TouchEvent*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->changedTouches()));
}

JSValue jsTouchEventConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSTouchEvent* domObject = static_cast<JSTouchEvent*>(asObject(slot.slotBase()));
    return JSTouchEvent::getConstructor(exec, domObject->globalObject());
}
JSValue JSTouchEvent::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTouchEventConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsTouchEventPrototypeFunctionInitTouchEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSTouchEvent::s_info))
        return throwError(exec, TypeError);
    JSTouchEvent* castedThisObj = static_cast<JSTouchEvent*>(asObject(thisValue));
    TouchEvent* imp = static_cast<TouchEvent*>(castedThisObj->impl());
    TouchList* touches = toTouchList(args.at(0));
    TouchList* targetTouches = toTouchList(args.at(1));
    TouchList* changedTouches = toTouchList(args.at(2));
    const UString& type = args.at(3).toString(exec);
    DOMWindow* view = toDOMWindow(args.at(4));
    int screenX = args.at(5).toInt32(exec);
    int screenY = args.at(6).toInt32(exec);
    int clientX = args.at(7).toInt32(exec);
    int clientY = args.at(8).toInt32(exec);

    imp->initTouchEvent(touches, targetTouches, changedTouches, type, view, screenX, screenY, clientX, clientY);
    return jsUndefined();
}


}

#endif // ENABLE(TOUCH_EVENTS)
