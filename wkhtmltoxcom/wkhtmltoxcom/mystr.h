#ifndef __mystr_h__
#define __mystr_h__
#include <windows.h>

BSTR utf8_to_bstr(const char * str);
char * bstr_to_utf8(const BSTR str); 
#endif //__mystr_h__