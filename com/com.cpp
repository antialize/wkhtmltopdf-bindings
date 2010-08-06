#include <objbase.h>
#include <windows.h>
#include "wkhtmltoxcom.h"
#include <stdio.h>
#include <wkhtmltox/pdf.h>
#include "factory.h"

static HMODULE module = NULL ; 


// /**************************************> Pdf <************************************/

// class CWkHtmlToPdf: public IWkHtmlToPdf {
// private:
//   int refCount;
// public:
//   //IUnknown interface
//   HRESULT __stdcall QueryInterface(REFIID iid, void ** v) {}
//   ULONG __stdcall AddRef() {refCount++;}
//   ULONG __stdcall Release() {
//     refCount--;
//     if (refCount == 0) delete this;
//     return refCount;
//   }
  
//   HRESULT __stdcall extendedQt(BOOL * res) {
//     *res = wkhtmltopdf_extended_qt();
//     return S_OK;
//   }

//   HRESULT __stdcall version(const char * * version) {
//     *version = wkhtmltopdf_version();
//     return S_OK;
//   }

//   HRESULT __stdcall createGlobalSettings(int * object) {
//     //return wkhtmltopdf_create_global_settings();
//   }
  
//   HRESULT __stdcall createObjectSettings(int * object) {
//     //return wkhtmltopdf_create_object_settings();
//   }

//   HRESULT __stdcall setGlobalSetting(int settings, const char * name, const char * value);
//   HRESULT __stdcall getGlobalSetting(int settings, const char * name, char * value, int vs);
//   HRESULT __stdcall setObjectSetting(int settings, const char * name, const char * value);
//   HRESULT __stdcall getObjectSetting(int settings, const char * name, char * value, int vs);
  
//   HRESULT __stdcall createConverter(int globalSettings, int * converter);
//   HRESULT __stdcall destroyConverter(int converter);
  
//   HRESULT __stdcall convert(int converter);
//   HRESULT __stdcall addResource(int converter, int settings, const char * data);
//   HRESULT __stdcall currentPhase(int converter, int * currentPhase);
//   HRESULT __stdcall phaseCount(int converter, int * phaseCount);
//   HRESULT __stdcall phaseDescription(int converter, int phase, const char * *);
//   HRESULT __stdcall progressString(int converter, const char * * );
//   HRESULT __stdcall httpErrorCode(int converter, int * errorCode);

// // BOOL _stdcall pdf_setGlobalSetting(void * settings, const char * name, const char * value) {
// //   return wkhtmltopdf_set_global_setting(settings, name, value);
// // }

// // BOOL _stdcall pdf_getGlobalSetting(void * settings, const char * name, char * value, int vs) {
// //   return wkhtmltopdf_get_global_setting(settings, name, value, vs);
// // }

// // BOOL _stdcall pdf_setObjectSetting(void * settings, const char * name, const char * value) {
// //   return wkhtmltopdf_set_object_setting(settings, name, value);
// // }

// // BOOL _stdcall pdf_getObjectSetting(void * settings, const char * name, char * value, int vs) {
// //   return wkhtmltopdf_get_object_setting(settings, name, value, vs);
// // }

// // void * _stdcall pdf_createConverter(void * globalSettings) {
// //   return wkhtmltopdf_create_converter(globalSettings);
// // }

// // void _stdcall pdf_destroyConverter(void * converter) {
// //   wkhtmltopdf_destroy_converter(converter);
// // }

// // BOOL _stdcall pdf_convert(void * converter) {
// //   return wkhtmltopdf_convert(converter);
// // }

// // void * _stdcall pdf_addResource(void * converter, void * settings, const char * data) {
// //   //return wkhhtmltopdf_add_resource(converter, settings, data);
// // }

// // int _stdcall pdf_currentPhase(void * converter) {
// //   return wkhtmltopdf_current_phase(converter);
// // }

// // int _stdcall pdf_phaseCount(void * converter) {
// //   return wkhtmltopdf_phase_count(converter);
// // }

// // const char * _stdcall pdf_phaseDescription(void * converter, int phase) {
// //   return wkhtmltopdf_phase_description(converter, phase);
// // }

// // const char * _stdcall pdf_progressString(void * converter) {
// //   return wkhtmltopdf_progress_string(converter);
// // }

// // int _stdcall pdf_httpErrorCode(void * converter) {
// //   return wkhtmltopdf_http_error_code(converter);
// // }

// };

// HRESULT _stdcall pdf_queryInterface(struct IWkHtmlToPdf *s, REFIID iid, void **v)  {
//   CWkHtmlToPdf * self = (CWkHtmlToPdf*)s;
  
//   if (!IsEqualIID( iid, &IID_IUnknown) && !IsEqualIID( iid, &IID_IWkHtmlToPdf) ) {
//     *v = NULL;
//     return E_NOINTERFACE;
//   }
//   *v = &self->parent;
//   ++self->ref;
//   return S_OK;
// }


// ULONG _stdcall pdf_release(struct IWkHtmlToPdf * s) {
//   CWkHtmlToPdf * self = (CWkHtmlToPdf*)s;
//   --self->ref;
//   if (self->ref > 0) return self->ref;
//   free(self);
//   wkhtmltopdf_deinit();
//   return 0;
// }


// IWkHtmlToPdfVtbl pdf_vtbl = {
//   pdf_queryInterface,
//   pdf_addRef, 
//   pdf_release,
//   pdf_extendedQt,
//   pdf_version,
//   pdf_createGlobalSettings,
//   pdf_createObjectSettings,
//   pdf_setGlobalSetting,
//   pdf_getGlobalSetting,
//   pdf_setObjectSetting,
//   pdf_getObjectSetting,
//   pdf_createConverter,
//   pdf_destroyConverter,
//   pdf_convert,
//   pdf_addResource,
//   pdf_currentPhase,
//   pdf_phaseCount,
//   pdf_phaseDescription,
//   pdf_progressString,
//   pdf_httpErrorCode
// };

// HRESULT _stdcall pdf_factory_createInstance(IClassFactory * f, IUnknown * o, const IID * iid, void ** v) {
//   CWkHtmlToPdf * p;
//   if (o != NULL ) return CLASS_E_NOAGGREGATION;
//   p = (CWkHtmlToPdf*)malloc(sizeof(CWkHtmlToPdf));
//   if (NULL == p) return E_OUTOFMEMORY;
//   p->parent.vtbl = &pdf_vtbl;
//   p->ref = 1;
//   *v = p;
//   wkhtmltopdf_init(1);
//   return S_OK;
// }

// struct IClassFactoryVtbl pdf_factory_vtbl = {
//   factory_queryInterface,
//   factory_addRef,
//   factory_release,
//   pdf_factory_createInstance,
//   factory_lockServer};

// CWkHtmlToXFactory pdf_factory = {
//   {&pdf_factory_vtbl},
//   1
// };

// /**************************************> Image <************************************/


// /**************************************> Dll Stuff <************************************/

#include "guid.h"
#include "factory.h"

STDAPI DllGetClassObject(const CLSID & clsid, const IID & iid, void ** v) {
  if (CLSID_CWkHtmlToPdf == clsid) {
    CWkHtmlToPdfFactory * fact = new CWkHtmlToPdfFactory();
    if (fact == NULL) return E_OUTOFMEMORY;
    return fact->QueryInterface(iid, v);
  }
  if (CLSID_CWkHtmlToImage == clsid) {
    CWkHtmlToImageFactory * fact = new CWkHtmlToImageFactory();
    if (fact == NULL) return E_OUTOFMEMORY;
    return fact->QueryInterface(iid, v);
  }
  return CLASS_E_CLASSNOTAVAILABLE;
}

LONG volatile objCount=0;

STDAPI DllCanUnloadNow() {
  return (objCount == 0)?S_OK:S_FALSE;
}

long RegisterServer(const CLSID & clsid, const char * name) {
  char buff[1024];
  char dllPath[1024];
  HKEY key=0;
  long err;
  WCHAR * foo;
 
  if (!GetModuleFileName(module, dllPath, 1024)) return ERROR_PRODUCT_VERSION;
  StringFromCLSID(clsid, &foo);
  wsprintf(buff, "CLSID\\%S", foo);

  err = RegCreateKey(HKEY_CLASSES_ROOT, buff, &key);
  if (err != ERROR_SUCCESS) return err;
  err = RegSetValue(key, 0, REG_SZ, name, 0);
  if (err != ERROR_SUCCESS) return err;
  err = RegSetValue(key, "InprocServer32" , REG_SZ, dllPath, 0);
  if (err != ERROR_SUCCESS) return err;

  RegCloseKey(key);
  return ERROR_SUCCESS;
}

long UnregisterServer(const CLSID & clsid) {
  HKEY key;
  long err;
  char buff[1024];
  char cls[1024];
  WCHAR * foo;
  StringFromCLSID(clsid, &foo);
  wsprintf(cls, "%S", foo);
  err = RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &key);
  if (err != ERROR_SUCCESS) return err;

  sprintf(buff, "%s\\InprocServer32", cls);
  err = RegDeleteKey(key, buff);
  if (err != ERROR_SUCCESS) return err;

  err = RegDeleteKey(key, cls);
  if (err != ERROR_SUCCESS) return err;
  
  RegCloseKey(key);
  return ERROR_SUCCESS;
}

STDAPI DllRegisterServer() {
  long err = RegisterServer(CLSID_CWkHtmlToPdf, "wkhtmltopdf");
  if (err != ERROR_SUCCESS) return err;
  return RegisterServer(CLSID_CWkHtmlToImage, "wkhtmltoimage");
}

STDAPI DllUnregisterServer() {
  long err = UnregisterServer(CLSID_CWkHtmlToPdf);
  if (err != ERROR_SUCCESS) return err;
  return UnregisterServer(CLSID_CWkHtmlToImage);
}

BOOL APIENTRY DllMain(HANDLE hModule,
 		      DWORD dwReason,
		      void* lpReserved)
{
  if (dwReason == DLL_PROCESS_ATTACH) module = (HMODULE) hModule;
  return TRUE;
}
