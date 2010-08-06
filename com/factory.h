#ifndef __factory_h__
#define __factory_h__
#include <objbase.h>

class CWkHTmlToXFactory: public IClassFactory {
public:
  //IUnknown
  HRESULT __stdcall QueryInterface(REFIID iid, void ** v);
  ULONG __stdcall AddRef();
  ULONG __stdcall Release();
  
  //IClassFactory
  HRESULT __stdcall LockServer(BOOL lock);
  
  CWkHTmlToXFactory();
  virtual ~CWkHTmlToXFactory();
private:
  LONG volatile refCount;
};

class CWkHtmlToPdfFactory: public CWkHTmlToXFactory {
public:
  HRESULT __stdcall CreateInstance(IUnknown * o, const IID & iid, void ** v);
};

class CWkHtmlToImageFactory: public CWkHTmlToXFactory {
public:
  HRESULT __stdcall CreateInstance(IUnknown * o, const IID & iid, void ** v);
};

#endif // __factory_h__
