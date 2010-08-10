// WkHtmlToPdf.cpp : Implementation of CWkHtmlToPdf

#include "stdafx.h"
#include "WkHtmlToPdf.h"
#include <wkhtmltox/pdf.h>
#include "objman.h"
#include "mystr.h"
// CWkHtmlToPdf


ObjMan<wkhtmltopdf_global_settings> gsm;
ObjMan<wkhtmltopdf_object_settings> osm;
ObjMan2<wkhtmltopdf_converter, CWkHtmlToPdf> csm;

void warning(wkhtmltopdf_converter * con, const char * msg) {
  int obj = csm.rev[con];
  CWkHtmlToPdf * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->warning(obj, utf8_to_bstr(msg));
}

void error(wkhtmltopdf_converter * con, const char * msg) {
  int obj = csm.rev[con];
  CWkHtmlToPdf * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->error(obj, utf8_to_bstr(msg));
}

void phase_changed(wkhtmltopdf_converter * con) {
  int obj = csm.rev[con];
  CWkHtmlToPdf * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->phaseChanged(obj);
}

void progress_changed(wkhtmltopdf_converter * con, int progress) {
  int obj = csm.rev[con];
  CWkHtmlToPdf * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->progressChanged(obj, progress);
}

void finished(wkhtmltopdf_converter * con, int ok) {
  int obj = csm.rev[con];
  CWkHtmlToPdf * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->finished(obj, ok);
}

STDMETHODIMP CWkHtmlToPdf::extendedQt(BOOL * ext) {
	*ext = wkhtmltopdf_extended_qt();
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::getVersion(BSTR * ret) {
	*ret = utf8_to_bstr(wkhtmltopdf_version());
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::createGlobalSettings(ULONG * gs) {
	*gs = gsm.set(wkhtmltopdf_create_global_settings());
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::createObjectSettings(ULONG * os) {
	*os = osm.set(wkhtmltopdf_create_object_settings());
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::setGlobalSetting(ULONG gs, BSTR name, BSTR value, BOOL * ok) {
	wkhtmltopdf_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	char * uvalue = bstr_to_utf8(value);
	*ok = wkhtmltopdf_set_global_setting(s, uname, uvalue);
	delete[] uname;
	delete[] uvalue;
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::getGlobalSetting(ULONG gs, BSTR name, BSTR * value) {
	wkhtmltopdf_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	*value = NULL;
	char buff[10240];
	if (wkhtmltopdf_get_global_setting(s, uname, buff,10240))
		*value = utf8_to_bstr(buff);
	delete[] uname;
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::setObjectSetting(ULONG os, BSTR name, BSTR value, BOOL * ok) {
	wkhtmltopdf_object_settings * s = osm.get(os);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	char * uvalue = bstr_to_utf8(value);
	*ok = wkhtmltopdf_set_object_setting(s, uname, uvalue);
	delete[] uname;
	delete[] uvalue;
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::getObjectSetting(ULONG os, BSTR name, BSTR * value) {
	wkhtmltopdf_object_settings * s = osm.get(os);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	*value = NULL;
	char buff[10240];
	if (wkhtmltopdf_get_object_setting(s, uname, buff,10240))
		*value = utf8_to_bstr(buff);
	delete[] uname;
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::createConverter(ULONG gs, ULONG * con) {
	wkhtmltopdf_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	wkhtmltopdf_converter * c = wkhtmltopdf_create_converter(s);
	*con = csm.set(c, this);
	gsm.unset(gs);

	wkhtmltopdf_set_warning_callback(c, warning);
	wkhtmltopdf_set_error_callback(c, error);
	wkhtmltopdf_set_phase_changed_callback(c, phase_changed);
	wkhtmltopdf_set_progress_changed_callback(c, progress_changed);
	wkhtmltopdf_set_finished_callback(c, finished);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::destroyConverter(ULONG con) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	wkhtmltopdf_destroy_converter(c);
	csm.unset(con);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::convert(ULONG con, ULONG * ok) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*ok = wkhtmltopdf_convert(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::addObject(ULONG con, ULONG os, BSTR data) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
  
	wkhtmltopdf_object_settings * o = osm.get(os);
	if (o == NULL) return ERROR_INVALID_HANDLE;
  
	char * d = data?bstr_to_utf8(data):0;
	wkhtmltopdf_add_object(c, o, d);
	if (d) delete[] d;
	osm.unset(os);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::currentPhase(ULONG con, ULONG * res) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = wkhtmltopdf_current_phase(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::phaseCount(ULONG con, ULONG * res) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = wkhtmltopdf_phase_count(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::phaseDescription(ULONG con, ULONG phase, BSTR * res) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = utf8_to_bstr(wkhtmltopdf_phase_description(c, phase));
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::progressString(ULONG con, BSTR * res) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = utf8_to_bstr(wkhtmltopdf_progress_string(c));
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::httpErrorCode(ULONG con, ULONG * res) {
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;	
	*res = wkhtmltopdf_http_error_code(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::getOutput(ULONG con, SAFEARRAY ** res) {
	const char unsigned * data;
	wkhtmltopdf_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;	
	long len = wkhtmltopdf_get_output(c, &data);
	*res = SafeArrayCreateVector(VT_UI1, 0, len);
	SafeArrayLock(*res);
	for (long i=0; i < len; ++i)
		SafeArrayPutElement(*res,&i, (void*)(data+i));
	SafeArrayUnlock(*res);
	return S_OK;
}

STDMETHODIMP CWkHtmlToPdf::setCallBack(IWkHtmlToXCallBack * c) {
	if (cb != 0) cb->Release();
	if (c != 0) c->AddRef();
	cb = c;
	return S_OK;
}

CWkHtmlToPdf::CWkHtmlToPdf(): cb(0) {
	wkhtmltopdf_init(true);
}

CWkHtmlToPdf::~CWkHtmlToPdf() {
	setCallBack(0);
	wkhtmltopdf_deinit();
}