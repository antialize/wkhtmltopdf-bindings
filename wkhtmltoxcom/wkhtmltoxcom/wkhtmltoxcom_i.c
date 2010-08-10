

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Aug 11 00:44:44 2010
 */
/* Compiler settings for .\wkhtmltoxcom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IComponentRegistrar,0xa817e7a2,0x43fa,0x11d0,0x9e,0x44,0x00,0xaa,0x00,0xb6,0x77,0x0a);


MIDL_DEFINE_GUID(IID, IID_IWkHtmlToXCallBack,0xAF9B8D22,0x6773,0x43AD,0x8E,0xC5,0x74,0x96,0x2D,0x16,0xFE,0x2E);


MIDL_DEFINE_GUID(IID, IID_IWkHtmlToPdf,0xDF4EF884,0x7B4F,0x445C,0xB0,0x12,0x02,0xBB,0x8B,0x27,0x58,0x9C);


MIDL_DEFINE_GUID(IID, IID_IWkHtmlToImage,0x39CD3CEE,0xD85C,0x492B,0xAC,0x88,0x7C,0x00,0xA7,0xF7,0x5A,0x60);


MIDL_DEFINE_GUID(IID, LIBID_wkhtmltoxcomLib,0x8CD61B55,0x9E0A,0x4D71,0x80,0xD4,0x43,0x8B,0x2E,0x9D,0x5A,0x45);


MIDL_DEFINE_GUID(CLSID, CLSID_CompReg,0x5D704535,0x1CCC,0x4936,0xA9,0xA5,0x9B,0x90,0x13,0x99,0x81,0x07);


MIDL_DEFINE_GUID(CLSID, CLSID_WkHtmlToPdf,0xC156B9C6,0x7E0E,0x4FD7,0xB5,0x10,0xF6,0x13,0x1F,0x3A,0x4A,0x62);


MIDL_DEFINE_GUID(CLSID, CLSID_WkHtmlToImage,0x6F7A8025,0xAA5C,0x4B53,0xA7,0x64,0xB6,0x0C,0xD9,0x3F,0xA4,0xCC);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



