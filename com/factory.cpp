#include "factory.h"
#include "object.h"

CWkHTmlToXFactory::CWkHTmlToXFactory(): refCount(1) {
  InterlockedIncrement(&objCount);
}

CWkHTmlToXFactory::~CWkHTmlToXFactory() {
  InterlockedDecrement(&objCount);
}

ULONG __stdcall CWkHTmlToXFactory::AddRef() {
  return InterlockedIncrement(&refCount);
}

ULONG __stdcall CWkHTmlToXFactory::Release() {
  int c = InterlockedDecrement(&refCount);
  if (c == 0) delete this;
  return c;
}

HRESULT __stdcall CWkHTmlToXFactory::QueryInterface(REFIID iid, void ** v) {
  if ( iid == IID_IUnknown || iid == IID_IClassFactory) {
    *v = static_cast<IClassFactory*>(this);
    AddRef();
    return S_OK;
  }
  *v = NULL;
  return E_NOINTERFACE;
}

HRESULT __stdcall CWkHTmlToXFactory::LockServer(BOOL lock) {
  return E_NOTIMPL;
}

HRESULT __stdcall CWkHtmlToPdfFactory::CreateInstance(IUnknown * o, const IID & iid, void ** v) {
  if (o != NULL ) return CLASS_E_NOAGGREGATION;
  MessageBox(NULL, "CreateInstanc2e", "FOO" , MB_OK);
  CWkHtmlToPdf * p = new CWkHtmlToPdf();
  MessageBox(NULL, "CreateInstanc3e", "FOO" , MB_OK);
  if (p == NULL) return E_OUTOFMEMORY;
  HRESULT r = p->QueryInterface(iid, v);
  p->Release();
  return S_OK;
}

HRESULT __stdcall CWkHtmlToImageFactory::CreateInstance(IUnknown * o, const IID & iid, void ** v) {
  if (o != NULL ) return CLASS_E_NOAGGREGATION;
  CWkHtmlToImage * p = new CWkHtmlToImage();
  if (p == NULL) return E_OUTOFMEMORY;
  *v = p;
  return S_OK;
}

