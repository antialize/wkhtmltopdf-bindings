#include <windows.h>
#include "wkhtmltoxcom.h"
#include <stdio.h>
#include <wkhtmltox/pdf.h>

static HMODULE module = NULL ; 


/**************************************> Class Factory Base <************************************/
typedef struct CWkHtmlToXFactory {
  IClassFactory cf;
  ULONG ref;
} CWkHtmlToXFactory;

HRESULT _stdcall factory_queryInterface(IClassFactory * f, REFIID iid, void **v) {
  if( IsEqualIID( iid, &IID_IUnknown) || IsEqualIID( iid, &IID_IClassFactory) ) {
    *v=f;
    ((CWkHtmlToXFactory*)f)->cf.lpVtbl->AddRef(f);
    return S_OK;
  } 
  *v=NULL;
  return E_NOINTERFACE;
}

ULONG _stdcall factory_addRef(IClassFactory * f) {
  return ++((CWkHtmlToXFactory*)f)->ref;
}

ULONG _stdcall factory_release(IClassFactory * f) {
  return --((CWkHtmlToXFactory*)f)->ref;
}

HRESULT _stdcall factory_lockServer(IClassFactory * f, BOOL l) {
  return S_OK;
}

/**************************************> Pdf <************************************/
typedef struct {
  IWkHtmlToPdf parent;
  ULONG ref;
} CWkHtmlToPdf;

HRESULT _stdcall pdf_queryInterface(struct IWkHtmlToPdf *s, REFIID iid, void **v)  {
  CWkHtmlToPdf * self = (CWkHtmlToPdf*)s;
  
  if (!IsEqualIID( iid, &IID_IUnknown) && !IsEqualIID( iid, &IID_IWkHtmlToPdf) ) {
    *v = NULL;
    return E_NOINTERFACE;
  }
  *v = &self->parent;
  ++self->ref;
  return S_OK;
}

ULONG _stdcall pdf_addRef(struct IWkHtmlToPdf * s) {
  return ++((CWkHtmlToPdf*)s)->ref;
}

ULONG _stdcall pdf_release(struct IWkHtmlToPdf * s) {
  CWkHtmlToPdf * self = (CWkHtmlToPdf*)s;
  --self->ref;
  if (self->ref > 0) return self->ref;
  free(self);
  return 0;
}

BOOL _stdcall pdf_extendedQt() {
  return wkhtmltopdf_extended_qt();
}

const char * _stdcall pdf_version() {
  return wkhtmltopdf_version();
}

void * _stdcall pdf_createGlobalSettings() {
  return wkhtmltopdf_create_global_settings();
}

void * _stdcall pdf_createObjectSettings() {
  return wkhtmltopdf_create_object_settings();
}

BOOL _stdcall pdf_setGlobalSetting(void * settings, const char * name, const char * value) {
  return wkhtmltopdf_set_global_setting(settings, name, value);
}

BOOL _stdcall pdf_getGlobalSetting(void * settings, const char * name, char * value, int vs) {
  return wkhtmltopdf_get_global_setting(settings, name, value, vs);
}

BOOL _stdcall pdf_setObjectSetting(void * settings, const char * name, const char * value) {
  return wkhtmltopdf_set_object_setting(settings, name, value);
}

BOOL _stdcall pdf_getObjectSetting(void * settings, const char * name, char * value, int vs) {
  return wkhtmltopdf_get_object_setting(settings, name, value, vs);
}

void * _stdcall pdf_createConverter(void * globalSettings) {
  return wkhtmltopdf_create_converter(globalSettings);
}

void _stdcall pdf_destroyConverter(void * converter) {
  wkhtmltopdf_destroy_converter(converter);
}

BOOL _stdcall pdf_convert(void * converter) {
  return wkhtmltopdf_convert(converter);
}

void * _stdcall pdf_addResource(void * converter, void * settings, const char * data) {
  //return wkhhtmltopdf_add_resource(converter, settings, data);
}

int _stdcall pdf_currentPhase(void * converter) {
  return wkhtmltopdf_current_phase(converter);
}

int _stdcall pdf_phaseCount(void * converter) {
  return wkhtmltopdf_phase_count(converter);
}

const char * _stdcall pdf_phaseDescription(void * converter, int phase) {
  return wkhtmltopdf_phase_description(converter, phase);
}

const char * _stdcall pdf_progressString(void * converter) {
  return wkhtmltopdf_progress_string(converter);
}

int _stdcall pdf_httpErrorCode(void * converter) {
  return wkhtmltopdf_http_error_code(converter);
}

IWkHtmlToPdfVtbl pdf_vtbl = {
  pdf_queryInterface,
  pdf_addRef, 
  pdf_release,
  pdf_extendedQt,
  pdf_version,
  pdf_createGlobalSettings,
  pdf_createObjectSettings,
  pdf_setGlobalSetting,
  pdf_getGlobalSetting,
  pdf_setObjectSetting,
  pdf_getObjectSetting,
  pdf_createConverter,
  pdf_destroyConverter,
  pdf_convert,
  pdf_addResource,
  pdf_currentPhase,
  pdf_phaseCount,
  pdf_phaseDescription,
  pdf_progressString,
  pdf_httpErrorCode
};

HRESULT _stdcall pdf_factory_createInstance(IClassFactory * f, IUnknown * o, const IID * iid, void ** v) {
  CWkHtmlToPdf * p;
  if (o != NULL ) return CLASS_E_NOAGGREGATION;
  p = (CWkHtmlToPdf*)malloc(sizeof(CWkHtmlToPdf));
  if (NULL == p) return E_OUTOFMEMORY;
  p->parent.vtbl = &pdf_vtbl;
  p->ref = 1;
  *v = p;
  return S_OK;
}

struct IClassFactoryVtbl pdf_factory_vtbl = {
  factory_queryInterface,
  factory_addRef,
  factory_release,
  pdf_factory_createInstance,
  factory_lockServer};

CWkHtmlToXFactory pdf_factory = {
  {&pdf_factory_vtbl},
  1
};

/**************************************> Image <************************************/

typedef struct {
  IWkHtmlToImage parent;
  ULONG ref;
} CWkHtmlToImage;

HRESULT _stdcall image_queryInterface(struct IWkHtmlToImage *s, REFIID iid, void **v)  {
  CWkHtmlToImage * self = (CWkHtmlToImage*)s;
  
  if (!IsEqualIID( iid, &IID_IUnknown) && !IsEqualIID( iid, &IID_IWkHtmlToImage) ) {
    *v = NULL;
    return E_NOINTERFACE;
  }
  *v = &self->parent;
  ++self->ref;
  return S_OK;
}

ULONG _stdcall image_addRef(struct IWkHtmlToImage * s) {
  return ++((CWkHtmlToImage*)s)->ref;
}

ULONG _stdcall image_release(struct IWkHtmlToImage * s) {
  CWkHtmlToImage * self = (CWkHtmlToImage*)s;
  --self->ref;
  if (self->ref > 0) return self->ref;
  free(self);
  return 0;
}


IWkHtmlToImageVtbl image_vtbl = {
  image_queryInterface,
  image_addRef, 
  image_release};

HRESULT _stdcall image_factory_createInstance(IClassFactory * f, IUnknown * o, const IID * iid, void ** v) {
  CWkHtmlToImage * p;
  if (o != NULL ) return CLASS_E_NOAGGREGATION;
  p = (CWkHtmlToImage*)malloc(sizeof(CWkHtmlToImage));
  if (NULL == p) return E_OUTOFMEMORY;
  p->parent.vtbl = &image_vtbl;
  p->ref = 1;
  *v = p;
  return S_OK;
}

struct IClassFactoryVtbl imeg_factory_vtbl = {
  factory_queryInterface,
  factory_addRef,
  factory_release,
  image_factory_createInstance,
  factory_lockServer};

CWkHtmlToXFactory image_factory = {
  {&pdf_factory_vtbl},
  1
};

/**************************************> Dll Stuff <************************************/

STDAPI DllGetClassObject( REFCLSID clsid, REFIID iid, LPVOID * v) {
  if (IsEqualCLSID( &CWkHtmlToPdf_CLSID, clsid ) ) {
      if (!IsEqualIID(iid, &IID_IUnknown) && !IsEqualIID(iid, &IID_IClassFactory))
	return E_NOINTERFACE;
      ++pdf_factory.ref;
      *v = &pdf_factory;
      return S_OK;
  } 
  if (IsEqualCLSID( &CWkHtmlToImage_CLSID, clsid ) ) {
    if (!IsEqualIID(iid, &IID_IUnknown) && !IsEqualIID(iid, &IID_IClassFactory))
      return E_NOINTERFACE;
    ++image_factory.ref;
    *v = &image_factory;
    return S_OK;
  }
  return CLASS_E_CLASSNOTAVAILABLE;
}


STDAPI DllCanUnloadNow() {
  return S_OK;
}


long RegisterServer(const char * clsid, const char * name) {
  char buff[1024];
  char dllPath[1024];
  HKEY key=0;
  long err;
  
  if (!GetModuleFileName(module, dllPath, 1024)) return ERROR_PRODUCT_VERSION;
  
  sprintf(buff, "CLSID\\%s", clsid);
  err = RegCreateKey(HKEY_CLASSES_ROOT, buff, &key);
  if (err != ERROR_SUCCESS) return err;
  err = RegSetValue(key, 0, REG_SZ, name, 0);
  if (err != ERROR_SUCCESS) return err;
  err = RegSetValue(key, "InprocServer32" , REG_SZ, dllPath, 0);
  if (err != ERROR_SUCCESS) return err;

  RegCloseKey(key);
  return ERROR_SUCCESS;
}

long UnregisterServer(const char * clsid) {
  HKEY key;
  long err;
  char buff[1024];

  err = RegOpenKey(HKEY_CLASSES_ROOT, "CLSID", &key);
  if (err != ERROR_SUCCESS) return err;

  sprintf(buff, "%s\\InprocServer32", clsid);
  err = RegDeleteKey(key, buff);
  if (err != ERROR_SUCCESS) return err;

  err = RegDeleteKey(key, clsid);
  if (err != ERROR_SUCCESS) return err;
  
  RegCloseKey(key);
  return ERROR_SUCCESS;
}

STDAPI DllRegisterServer() {
  long err = RegisterServer("{74BA3F02-CA19-4B6A-810A-A132F5071C86}", "wkhtmltopdf");
  if (err != ERROR_SUCCESS) return err;
  return RegisterServer("{CCE1BCE0-94AF-4D0E-B691-3C63BB5CADD8}", "wkhtmltoimage");
}

STDAPI DllUnregisterServer() {
  long err = UnregisterServer("{74BA3F02-CA19-4B6A-810A-A132F5071C86}");
  if (err != ERROR_SUCCESS) return err;
  return UnregisterServer("{CCE1BCE0-94AF-4D0E-B691-3C63BB5CADD8}");
}

BOOL APIENTRY DllMain(HANDLE hModule,
 		      DWORD dwReason,
		      void* lpReserved)
{
  if (dwReason == DLL_PROCESS_ATTACH) module = (HMODULE) hModule;
  return TRUE;
}
