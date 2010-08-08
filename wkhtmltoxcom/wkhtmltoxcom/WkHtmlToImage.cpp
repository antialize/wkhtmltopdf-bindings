// WkHtmlToImage.cpp : Implementation of CWkHtmlToImage

#include "stdafx.h"
#include "WkHtmlToImage.h"

#include <wkhtmltox/image.h>
#include "objman.h"
#include "mystr.h"
// CWkHtmlToImage


ObjMan<wkhtmltoimage_global_settings> gsm;
ObjMan2<wkhtmltoimage_converter, CWkHtmlToImage> csm;

void warning(wkhtmltoimage_converter * con, const char * msg) {
  int obj = csm.rev[con];
  CWkHtmlToImage * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->warning(obj, utf8_to_bstr(msg));
}

void error(wkhtmltoimage_converter * con, const char * msg) {
  int obj = csm.rev[con];
  CWkHtmlToImage * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->error(obj, utf8_to_bstr(msg));
}

void phase_changed(wkhtmltoimage_converter * con) {
  int obj = csm.rev[con];
  CWkHtmlToImage * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->phaseChanged(obj);
}

void progress_changed(wkhtmltoimage_converter * con, int progress) {
  int obj = csm.rev[con];
  CWkHtmlToImage * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->progressChanged(obj, progress);
}

void finished(wkhtmltoimage_converter * con, int ok) {
  int obj = csm.rev[con];
  CWkHtmlToImage * c = csm.get2(obj);
  if (!c->cb) return;
  c->cb->finished(obj, ok);
}

STDMETHODIMP CWkHtmlToImage::extendedQt(BOOL * ext) {
	*ext = wkhtmltoimage_extended_qt();
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::getVersion(BSTR * ret) {
	*ret = utf8_to_bstr(wkhtmltoimage_version());
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::createGlobalSettings(ULONG * gs) {
	*gs = gsm.set(wkhtmltoimage_create_global_settings());
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::setGlobalSetting(ULONG gs, BSTR name, BSTR value, BOOL * ok) {
	wkhtmltoimage_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	char * uvalue = bstr_to_utf8(value);
	*ok = wkhtmltoimage_set_global_setting(s, uname, uvalue);
	delete[] uname;
	delete[] uvalue;
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::getGlobalSetting(ULONG gs, BSTR name, BSTR * value) {
	wkhtmltoimage_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	char * uname = bstr_to_utf8(name);
	*value = NULL;
	char buff[10240];
	if (wkhtmltoimage_get_global_setting(s, uname, buff,10240))
		*value = utf8_to_bstr(buff);
	delete[] uname;
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::createConverter(ULONG gs, BSTR data, ULONG * con) {
	wkhtmltoimage_global_settings * s = gsm.get(gs);
	if (s == NULL) return ERROR_INVALID_HANDLE;
	
	char * d = data?bstr_to_utf8(data):0;
	wkhtmltoimage_converter * c = wkhtmltoimage_create_converter(s, d);
	if (d) delete[] d;

	*con = csm.set(c, this);
	gsm.unset(gs);

	wkhtmltoimage_set_warning_callback(c, warning);
	wkhtmltoimage_set_error_callback(c, error);
	wkhtmltoimage_set_phase_changed_callback(c, phase_changed);
	wkhtmltoimage_set_progress_changed_callback(c, progress_changed);
	wkhtmltoimage_set_finished_callback(c, finished);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::destroyConverter(ULONG con) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	wkhtmltoimage_destroy_converter(c);
	csm.unset(con);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::convert(ULONG con, ULONG * ok) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*ok = wkhtmltoimage_convert(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::currentPhase(ULONG con, ULONG * res) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = wkhtmltoimage_current_phase(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::phaseCount(ULONG con, ULONG * res) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = wkhtmltoimage_phase_count(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::phaseDescription(ULONG con, ULONG phase, BSTR * res) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = utf8_to_bstr(wkhtmltoimage_phase_description(c, phase));
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::progressString(ULONG con, BSTR * res) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;
	*res = utf8_to_bstr(wkhtmltoimage_progress_string(c));
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::httpErrorCode(ULONG con, ULONG * res) {
	wkhtmltoimage_converter * c = csm.get(con);
	if (c == NULL) return ERROR_INVALID_HANDLE;	
	*res = wkhtmltoimage_http_error_code(c);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::getOutput(ULONG con, SAFEARRAY ** res) {
	const char unsigned * data;
	long len = wkhtmltoimage_get_output(NULL, &data);
	*res = SafeArrayCreateVector(VT_UI1, 0, len);
	SafeArrayLock(*res);
	for (long i=0; i < len; ++i)
		SafeArrayPutElement(*res,&i, (void*)(data+i));
	SafeArrayUnlock(*res);
	return S_OK;
}

STDMETHODIMP CWkHtmlToImage::setCallBack(IWkHtmlToXCallBack * c) {
	if (cb != 0) cb->Release();
	if (c != 0) c->AddRef();
	cb = c;
	return S_OK;
}

CWkHtmlToImage::CWkHtmlToImage(): cb(0) {
	wkhtmltoimage_init(true);
}

CWkHtmlToImage::~CWkHtmlToImage() {
	setCallBack(0);
	wkhtmltoimage_deinit();
}

// CWkHtmlToImage

