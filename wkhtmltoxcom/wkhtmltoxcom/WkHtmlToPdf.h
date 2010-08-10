// WkHtmlToPdf.h : Declaration of the CWkHtmlToPdf

#pragma once
#include "wkhtmltoxcom_i.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>



// CWkHtmlToPdf

class ATL_NO_VTABLE CWkHtmlToPdf :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWkHtmlToPdf, &CLSID_WkHtmlToPdf>,
	public IDispatchImpl<IWkHtmlToPdf, &IID_IWkHtmlToPdf, &LIBID_wkhtmltoxcomLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CWkHtmlToPdf();
	~CWkHtmlToPdf();

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WKHTMLTOPDF)

DECLARE_NOT_AGGREGATABLE(CWkHtmlToPdf)

BEGIN_COM_MAP(CWkHtmlToPdf)
	COM_INTERFACE_ENTRY(IWkHtmlToPdf)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


// IWkHtmlToPdf
public:
	STDMETHOD(extendedQt)(BOOL * ext);
	STDMETHOD(getVersion)(BSTR * ret);
	STDMETHOD(createGlobalSettings)(ULONG * gs);
	STDMETHOD(createObjectSettings)(ULONG * os);
	STDMETHOD(setGlobalSetting)(ULONG gs, BSTR name, BSTR value, BOOL * ok);
	STDMETHOD(getGlobalSetting)(ULONG gs, BSTR name, BSTR * value);
	STDMETHOD(setObjectSetting)(ULONG os, BSTR name, BSTR value, BOOL * ok);
	STDMETHOD(getObjectSetting)(ULONG os, BSTR name, BSTR * value);
	STDMETHOD(createConverter)(ULONG gs, ULONG * con);
	STDMETHOD(destroyConverter)(ULONG cov);
	STDMETHOD(convert)(ULONG con, ULONG * ok);
	STDMETHOD(addObject)(ULONG con, ULONG os, BSTR data);
	STDMETHOD(currentPhase)(ULONG con, ULONG * res);
	STDMETHOD(phaseCount)(ULONG con, ULONG * res);
	STDMETHOD(phaseDescription)(ULONG con, ULONG phase, BSTR * res);
	STDMETHOD(progressString)(ULONG con, BSTR * res);
	STDMETHOD(httpErrorCode)(ULONG con, ULONG * res);
	STDMETHOD(getOutput)(ULONG con, SAFEARRAY ** res);
	STDMETHOD(setCallBack)(IWkHtmlToXCallBack * cb);

	IWkHtmlToXCallBack * cb;
};

OBJECT_ENTRY_AUTO(__uuidof(WkHtmlToPdf), CWkHtmlToPdf)
