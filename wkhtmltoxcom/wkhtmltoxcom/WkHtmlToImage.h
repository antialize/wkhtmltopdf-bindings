// WkHtmlToImage.h : Declaration of the CWkHtmlToImage

#pragma once
#include "wkhtmltoxcom_i.h"
#include "resource.h"       // main symbols
#include <comsvcs.h>



// CWkHtmlToImage

class ATL_NO_VTABLE CWkHtmlToImage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWkHtmlToImage, &CLSID_WkHtmlToImage>,
	public IDispatchImpl<IWkHtmlToImage, &IID_IWkHtmlToImage, &LIBID_wkhtmltoxcomLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CWkHtmlToImage();
	~CWkHtmlToImage();

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_WKHTMLTOIMAGE)

DECLARE_NOT_AGGREGATABLE(CWkHtmlToImage)

BEGIN_COM_MAP(CWkHtmlToImage)
	COM_INTERFACE_ENTRY(IWkHtmlToImage)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWkHtmlToImage
	STDMETHOD(extendedQt)(BOOL * ext);
	STDMETHOD(getVersion)(BSTR * ret);
	STDMETHOD(createGlobalSettings)(ULONG * gs);
	STDMETHOD(setGlobalSetting)(ULONG gs, BSTR name, BSTR value, BOOL * ok);
	STDMETHOD(getGlobalSetting)(ULONG gs, BSTR name, BSTR * value);
	STDMETHOD(createConverter)(ULONG gs, BSTR data, ULONG * con);
	STDMETHOD(destroyConverter)(ULONG cov);
	STDMETHOD(convert)(ULONG con, ULONG * ok);
	STDMETHOD(currentPhase)(ULONG con, ULONG * res);
	STDMETHOD(phaseCount)(ULONG con, ULONG * res);
	STDMETHOD(phaseDescription)(ULONG con, ULONG phase, BSTR * res);
	STDMETHOD(progressString)(ULONG con, BSTR * res);
	STDMETHOD(httpErrorCode)(ULONG con, ULONG * res);
	STDMETHOD(getOutput)(ULONG con, SAFEARRAY ** res);
	STDMETHOD(setCallBack)(IWkHtmlToXCallBack * cb);

	IWkHtmlToXCallBack * cb;


public:
};

OBJECT_ENTRY_AUTO(__uuidof(WkHtmlToImage), CWkHtmlToImage)
