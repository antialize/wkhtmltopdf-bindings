#include "stdafx.h"
#include "mystr.h"

BSTR utf8_to_bstr(const char * str) {
	int size=MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	wchar_t * buff = new wchar_t[size];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, buff, size);
	BSTR res = SysAllocString(buff);
	delete[] buff;	
	return res;
}

char * bstr_to_utf8(const BSTR str) {
	//WC_DEFAULTCHAR
	int size=WideCharToMultiByte(CP_UTF8, 0, str, -1, 0, NULL, NULL, NULL);
	char * buff = new char[size];
	WideCharToMultiByte(CP_UTF8, 0, str, -1, buff, size, NULL, NULL);
	return buff;
}