// ============================================================================
//
// = LIBRARY
//    ULib - c++ library
//
// = FILENAME
//    usp_macro.h
//
// = AUTHOR
//    Stefano Casazza
//
// ============================================================================

#ifndef U_USP_MACRO_H
#define U_USP_MACRO_H 1

#include <ulib/all.h>

#define USP_PUTS_BUFFER           (void)UClientImage_Base::wbuffer->append(usp_buffer,usp_sz)
#define USP_PUTS_CHAR(c)          (void)UClientImage_Base::wbuffer->push_back((c))
#define USP_PUTS_STRING(string)   (void)UClientImage_Base::wbuffer->append((string))
#define USP_PUTS_CONSTANT(string) (void)UClientImage_Base::wbuffer->append(U_CONSTANT_TO_PARAM(string))

#define USP_PRINTF(fmt,args...)     (UClientImage_Base::_buffer->snprintf(U_CONSTANT_TO_PARAM(fmt) , ##args),USP_PUTS_STRING(*UClientImage_Base::_buffer))
#define USP_PRINTF_ADD(fmt,args...)  UClientImage_Base::wbuffer->snprintf_add(U_CONSTANT_TO_PARAM(fmt) , ##args)

#define USP_JSON_REQUEST_PARSE(obj) JSON_parse(*UHTTP::body,(obj))
#define USP_JFIND_REQUEST(type,str) UValue::jfind(*UHTTP::body,#type,U_CONSTANT_SIZE(#type),(str))

#define USP_OBJ_JSON_stringify(obj) JSON_OBJ_stringify(*UClientImage_Base::wbuffer,(obj))

#define USP_SERIALIZE_OBJECT(class,obj) UFlatBuffer::toObject<class>(*UHTTP::body,(obj))

#define USP_XML_PUTS(string) \
   ((void)UClientImage_Base::_encoded->reserve((string).size() * 4), \
    UXMLEscape::encode((string),*UClientImage_Base::_encoded), \
    USP_PUTS_STRING(*UClientImage_Base::_encoded))

#define USP_XML_PRINTF(fmt,args...) \
   (UClientImage_Base::_buffer->snprintf(U_CONSTANT_TO_PARAM(fmt) , ##args), \
    USP_XML_PUTS(*UClientImage_Base::_buffer))

#define USP_FORM_NAME(n)               (UHTTP::getFormValue(*UClientImage_Base::_value,(0+(n*2))),                *UClientImage_Base::_value)
#define USP_FORM_VALUE(n)              (UHTTP::getFormValue(*UClientImage_Base::_value,(1+(n*2))),                *UClientImage_Base::_value)
#define USP_FORM_VALUE_FROM_NAME(name) (UHTTP::getFormValue(*UClientImage_Base::_value,U_CONSTANT_TO_PARAM(name)),*UClientImage_Base::_value)
#endif
