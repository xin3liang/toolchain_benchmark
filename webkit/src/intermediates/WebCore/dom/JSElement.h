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

#ifndef JSElement_h
#define JSElement_h

#include "Element.h"
#include "JSNode.h"
#include <runtime/Lookup.h>
#include <wtf/AlwaysInline.h>

namespace WebCore {

class Element;

class JSElement : public JSNode {
    typedef JSNode Base;
public:
    JSElement(NonNullPassRefPtr<JSC::Structure>, JSDOMGlobalObject*, PassRefPtr<Element>);
    static JSC::JSObject* createPrototype(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::PropertyDescriptor&);
    virtual void put(JSC::ExecState*, const JSC::Identifier& propertyName, JSC::JSValue, JSC::PutPropertySlot&);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;

    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags));
    }

    virtual void markChildren(JSC::MarkStack&);

    static JSC::JSValue getConstructor(JSC::ExecState*, JSC::JSGlobalObject*);

    // Custom functions
    JSC::JSValue setAttribute(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue setAttributeNode(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue setAttributeNS(JSC::ExecState*, const JSC::ArgList&);
    JSC::JSValue setAttributeNodeNS(JSC::ExecState*, const JSC::ArgList&);
    Element* impl() const
    {
        return static_cast<Element*>(Base::impl());
    }
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

ALWAYS_INLINE bool JSElement::getOwnPropertySlot(JSC::ExecState* exec, const JSC::Identifier& propertyName, JSC::PropertySlot& slot)
{
    return JSC::getStaticValueSlot<JSElement, Base>(exec, s_info.staticPropHashTable, this, propertyName, slot);
}

ALWAYS_INLINE bool JSElement::getOwnPropertyDescriptor(JSC::ExecState* exec, const JSC::Identifier& propertyName, JSC::PropertyDescriptor& descriptor)
{
    return JSC::getStaticValueDescriptor<JSElement, Base>(exec, s_info.staticPropHashTable, this, propertyName, descriptor);
}

Element* toElement(JSC::JSValue);
JSC::JSValue toJSNewlyCreated(JSC::ExecState*, JSDOMGlobalObject*, Element*);

class JSElementPrototype : public JSC::JSObject {
    typedef JSC::JSObject Base;
public:
    static JSC::JSObject* self(JSC::ExecState*, JSC::JSGlobalObject*);
    virtual const JSC::ClassInfo* classInfo() const { return &s_info; }
    static const JSC::ClassInfo s_info;
    virtual bool getOwnPropertySlot(JSC::ExecState*, const JSC::Identifier&, JSC::PropertySlot&);
    virtual bool getOwnPropertyDescriptor(JSC::ExecState*, const JSC::Identifier&, JSC::PropertyDescriptor&);
    static PassRefPtr<JSC::Structure> createStructure(JSC::JSValue prototype)
    {
        return JSC::Structure::create(prototype, JSC::TypeInfo(JSC::ObjectType, StructureFlags));
    }
    JSElementPrototype(NonNullPassRefPtr<JSC::Structure> structure) : JSC::JSObject(structure) { }
protected:
    static const unsigned StructureFlags = JSC::OverridesMarkChildren | JSC::OverridesGetOwnPropertySlot | Base::StructureFlags;
};

// Functions

JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetAttribute(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionSetAttribute(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionRemoveAttribute(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetAttributeNode(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionSetAttributeNode(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionRemoveAttributeNode(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetElementsByTagName(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetAttributeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionSetAttributeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionRemoveAttributeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetElementsByTagNameNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetAttributeNodeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionSetAttributeNodeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionHasAttribute(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionHasAttributeNS(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionFocus(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionBlur(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionScrollIntoView(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionContains(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionScrollIntoViewIfNeeded(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionScrollByLines(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionScrollByPages(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetElementsByClassName(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionQuerySelector(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionQuerySelectorAll(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionWebkitMatchesSelector(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetClientRects(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
JSC::JSValue JSC_HOST_CALL jsElementPrototypeFunctionGetBoundingClientRect(JSC::ExecState*, JSC::JSObject*, JSC::JSValue, const JSC::ArgList&);
// Attributes

JSC::JSValue jsElementTagName(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementStyle(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOffsetLeft(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOffsetTop(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOffsetWidth(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOffsetHeight(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOffsetParent(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementClientLeft(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementClientTop(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementClientWidth(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementClientHeight(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementScrollLeft(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementScrollLeft(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementScrollTop(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementScrollTop(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementScrollWidth(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementScrollHeight(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementFirstElementChild(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementLastElementChild(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementPreviousElementSibling(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementNextElementSibling(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementChildElementCount(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
JSC::JSValue jsElementOnabort(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnabort(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnblur(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnblur(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnchange(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnchange(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnclick(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnclick(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOncontextmenu(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOncontextmenu(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndblclick(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndblclick(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndrag(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndrag(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndragend(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndragend(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndragenter(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndragenter(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndragleave(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndragleave(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndragover(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndragover(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndragstart(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndragstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOndrop(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOndrop(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnerror(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnerror(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnfocus(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnfocus(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOninput(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOninput(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOninvalid(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOninvalid(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnkeydown(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnkeydown(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnkeypress(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnkeypress(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnkeyup(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnkeyup(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnload(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnload(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmousedown(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmousedown(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmousemove(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmousemove(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmouseout(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmouseout(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmouseover(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmouseover(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmouseup(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmouseup(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnmousewheel(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnmousewheel(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnscroll(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnscroll(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnselect(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnselect(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnsubmit(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnsubmit(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOntouchstart(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOntouchstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOntouchend(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOntouchend(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOntouchmove(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOntouchmove(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOntouchcancel(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOntouchcancel(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnbeforecut(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnbeforecut(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOncut(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOncut(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnbeforecopy(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnbeforecopy(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOncopy(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOncopy(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnbeforepaste(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnbeforepaste(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnpaste(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnpaste(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnreset(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnreset(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnsearch(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnsearch(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementOnselectstart(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);
void setJSElementOnselectstart(JSC::ExecState*, JSC::JSObject*, JSC::JSValue);
JSC::JSValue jsElementConstructor(JSC::ExecState*, const JSC::Identifier&, const JSC::PropertySlot&);

} // namespace WebCore

#endif
