#ifndef __WKHTMLTOPDFCOM_H__
#define __WKHTMLTOPDFCOM_H__

/*#ifdef INIT*/
#include <initguid.h>
/*#endif  INIT */

#include <objbase.h>

// {74BA3F02-CA19-4B6A-810A-A132F5071C86}
DEFINE_GUID(CWkHtmlToPdf_CLSID,
0x74BA3F02, 0xCA19, 0x4B6A, 0x81, 0x0A, 0xA1, 0x32, 0xF5, 0x07, 0x1C, 0x86);

// {D4237C0E-3AB5-4155-B508-DB6523F06448}
DEFINE_GUID(IID_IWkHtmlToPdf,
0xd4237c0e, 0x3ab5, 0x4155, 0xb5, 0x8, 0xdb, 0x65, 0x23, 0xf0, 0x64, 0x48);

// {CCE1BCE0-94AF-4D0E-B691-3C63BB5CADD8}
DEFINE_GUID(CWkHtmlToImage_CLSID, 
0xcce1bce0, 0x94af, 0x4d0e, 0xb6, 0x91, 0x3c, 0x63, 0xbb, 0x5c, 0xad, 0xd8);

// {B5A47297-C545-4A8F-95D5-1356D90B866E}
DEFINE_GUID(IID_IWkHtmlToImage, 
0xb5a47297, 0xc545, 0x4a8f, 0x95, 0xd5, 0x13, 0x56, 0xd9, 0xb, 0x86, 0x6e);


typedef struct IWkHtmlToPdfVtbl IWkHtmlToPdfVtbl;

typedef struct {
  struct IWkHtmlToPdfVtbl * vtbl;
} IWkHtmlToPdf;

typedef struct IWkHtmlToPdfVtbl {
  /*IUnknown*/
  HRESULT (_stdcall * queryInterface)(struct IWkHtmlToPdf * self, REFIID iid, void **v);
  ULONG	(_stdcall * addRef)(struct IWkHtmlToPdf * self);
  ULONG	(_stdcall * release)(struct IWkHtmlToPdf * self);

  /*IWkHtmlToPdf */
  BOOL (_stdcall * extendedQt)();
  const char * (_stdcall * version)();
  void * (_stdcall * createGlobalSettings)();
  void * (_stdcall * createObjectSettings)();
  BOOL (_stdcall * setGlobalSetting)(void * settings, const char * name, const char * value);
  BOOL (_stdcall * getGlobalSetting)(void * settings, const char * name, char * value, int vs);
  BOOL (_stdcall * setObjectSetting)(void * settings, const char * name, const char * value);
  BOOL (_stdcall * getObjectSetting)(void * settings, const char * name, char * value, int vs);
  void * (_stdcall * createConverter)(void * globalSettings);
  void (_stdcall * destroyConverter)(void * converter);
  
  BOOL (_stdcall * convert)(void * converter);
  void * (_stdcall * addResource)(void * converter, void * settings, const char * data);
  int (_stdcall * currentPhase)(void * converter);
  int (_stdcall * phaseCount)(void * converter);
  const char * (_stdcall * phaseDescription)(void * converter, int phase);
  const char * (_stdcall * progressString)(void * converter);
  int (_stdcall * httpErrorCode)(void * converter);

  //TODO ADD CALL BACKS
} IWkHtmlToPdfVtbl;


typedef struct IWkHtmlToImageVtbl IWkHtmlToImageVtbl;

typedef struct {
  struct IWkHtmlToImageVtbl * vtbl;
} IWkHtmlToImage;

typedef struct IWkHtmlToImageVtbl {
  /*IUnknown*/
  HRESULT (_stdcall * queryInterface)(struct IWkHtmlToImage * self, REFIID iid, void **v);
  ULONG	(_stdcall * addRef)(struct IWkHtmlToImage * self);
  ULONG	(_stdcall * release)(struct IWkHtmlToImage * self);
} IWkHtmlToImageVtbl;


#endif /*__WKHTMLTOPDFCOM_H__*/
