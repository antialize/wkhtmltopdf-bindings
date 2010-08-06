#include "object.h"

CWkHtmlToImage::CWkHtmlToImage(): refCount(1) {
  InterlockedIncrement(&objCount);
  wkhtmltoimage_init(true);
}

CWkHtmlToImage::~CWkHtmlToImage() {
  wkhtmltoimage_deinit();
  InterlockedDecrement(&objCount);
}

ULONG __stdcall CWkHtmlToImage::AddRef() {
  return InterlockedIncrement(&refCount);
}

ULONG __stdcall CWkHtmlToImage::Release() {
  int c = InterlockedDecrement(&refCount);
  if (c == 0) delete this;
  return c;
}

HRESULT __stdcall CWkHtmlToImage::QueryInterface(REFIID iid, void ** v) {
  if (iid == IID_IUnknown || iid == IID_IWkHtmlToImage) {
    *v = static_cast<IWkHtmlToImage*>(this);
    AddRef();
    return S_OK;
  }
  *v = NULL;
  return E_NOINTERFACE;
}

HRESULT __stdcall CWkHtmlToImage::extendedQt(BOOL * res) {
  *res = wkhtmltoimage_extended_qt();
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::version(const unsigned char * * version) {
  *version = (const unsigned char*)wkhtmltoimage_version();
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::createGlobalSettings(int * object) {
  *object = gsm.set(wkhtmltoimage_create_global_settings());
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::setGlobalSetting(int settings, const unsigned char * name, const unsigned char * value) {
  wkhtmltoimage_global_settings * s = gsm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltoimage_set_global_setting(s, (const char *)name, (const char *)value)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToImage::getGlobalSetting(int settings, const unsigned char * name, unsigned char * value, int vs) {
  wkhtmltoimage_global_settings * s = gsm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltoimage_get_global_setting(s, (const char*)name, (char *)value, vs)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToImage::createConverter(int globalSettings, int * converter) {
  wkhtmltoimage_global_settings * s = gsm.get(globalSettings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  *converter = csm.set(wkhtmltoimage_create_converter(s));
  gsm.unset(globalSettings);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::destroyConverter(int converter) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  wkhtmltoimage_destroy_converter(c);
  csm.unset(converter);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::convert(int converter) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltoimage_convert(c)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToImage::currentPhase(int converter, int * currentPhase) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *currentPhase = wkhtmltoimage_current_phase(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::phaseCount(int converter, int * phaseCount) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *phaseCount = wkhtmltoimage_phase_count(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::phaseDescription(int converter, int phase, const unsigned char * * desc) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *desc = (const unsigned char*)wkhtmltoimage_phase_description(c, phase);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::progressString(int converter, const unsigned char * * str) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *str = (const unsigned char*)wkhtmltoimage_progress_string(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImage::httpErrorCode(int converter, int * errorCode) {
  wkhtmltoimage_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *errorCode = wkhtmltoimage_http_error_code(c);
  return S_OK;
}


