#include "object.h"
#include "wkhtmltoxcom.h"

CWkHtmlToPdf::CWkHtmlToPdf(): refCount(1) {
  InterlockedIncrement(&objCount);
  wkhtmltopdf_init(false);
}

CWkHtmlToPdf::~CWkHtmlToPdf() {
  wkhtmltopdf_deinit();
  InterlockedDecrement(&objCount);
}

ULONG __stdcall CWkHtmlToPdf::AddRef() {
  return InterlockedIncrement(&refCount);
}

ULONG __stdcall CWkHtmlToPdf::Release() {
  int c = InterlockedDecrement(&refCount);
  if (c == 0) delete this;
  return c;
}

HRESULT __stdcall CWkHtmlToPdf::QueryInterface(REFIID iid, void ** v) {
  if (iid == IID_IUnknown || iid == IID_IWkHtmlToPdf) {
    *v = static_cast<IWkHtmlToPdf*>(this);
    AddRef();
    return S_OK;
  }
  *v = NULL;
  return E_NOINTERFACE;
}

HRESULT __stdcall CWkHtmlToPdf::extendedQt(BOOL * res) {
  *res = wkhtmltopdf_extended_qt();
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::version(const unsigned char * * version) {
  *version = (const unsigned char*)wkhtmltopdf_version();
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::createGlobalSettings(int * object) {
  *object = gsm.set(wkhtmltopdf_create_global_settings());
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::createObjectSettings(int * object) {
  *object = osm.set(wkhtmltopdf_create_object_settings());
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::setGlobalSetting(int settings, const unsigned char * name, const unsigned char * value) {
  wkhtmltopdf_global_settings * s = gsm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltopdf_set_global_setting(s, (const char *)name, (const char *)value)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToPdf::getGlobalSetting(int settings, const unsigned char * name, unsigned char * value, int vs) {
  wkhtmltopdf_global_settings * s = gsm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltopdf_get_global_setting(s, (const char*)name, (char *)value, vs)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToPdf::setObjectSetting(int settings, const unsigned char * name, const unsigned char * value) {
  wkhtmltopdf_object_settings * s = osm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltopdf_set_object_setting(s, (const char *)name, (const char *)value)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToPdf::getObjectSetting(int settings, const unsigned char * name, unsigned char * value, int vs) {
  wkhtmltopdf_object_settings * s = osm.get(settings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltopdf_get_object_setting(s, (const char*)name, (char *)value, vs)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToPdf::createConverter(int globalSettings, int * converter) {
  wkhtmltopdf_global_settings * s = gsm.get(globalSettings);
  if (s == NULL) return ERROR_INVALID_HANDLE;
  *converter = csm.set(wkhtmltopdf_create_converter(s));
  gsm.unset(globalSettings);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::destroyConverter(int converter) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  wkhtmltopdf_destroy_converter(c);
  csm.unset(converter);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::convert(int converter) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  return wkhtmltopdf_convert(c)?S_OK:S_FALSE;
}

HRESULT __stdcall CWkHtmlToPdf::addResource(int converter, int settings, const unsigned char * data) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  wkhtmltopdf_object_settings * o = osm.get(converter);
  if (o == NULL) return ERROR_INVALID_HANDLE;
  
  wkhtmltopdf_add_resource(c, o, (const char*)data);
  osm.unset(settings);

  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::currentPhase(int converter, int * currentPhase) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *currentPhase = wkhtmltopdf_current_phase(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::phaseCount(int converter, int * phaseCount) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *phaseCount = wkhtmltopdf_phase_count(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::phaseDescription(int converter, int phase, const unsigned char * * desc) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *desc = (const unsigned char*)wkhtmltopdf_phase_description(c, phase);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::progressString(int converter, const unsigned char * * str) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *str = (const unsigned char*)wkhtmltopdf_progress_string(c);
  return S_OK;
}

HRESULT __stdcall CWkHtmlToPdf::httpErrorCode(int converter, int * errorCode) {
  wkhtmltopdf_converter * c = csm.get(converter);
  if (c == NULL) return ERROR_INVALID_HANDLE;
  
  *errorCode = wkhtmltopdf_http_error_code(c);
  return S_OK;
}
