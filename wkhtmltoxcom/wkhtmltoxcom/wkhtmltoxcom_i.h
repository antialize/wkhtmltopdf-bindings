

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Aug 11 00:44:44 2010
 */
/* Compiler settings for .\wkhtmltoxcom.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __wkhtmltoxcom_i_h__
#define __wkhtmltoxcom_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComponentRegistrar_FWD_DEFINED__
#define __IComponentRegistrar_FWD_DEFINED__
typedef interface IComponentRegistrar IComponentRegistrar;
#endif 	/* __IComponentRegistrar_FWD_DEFINED__ */


#ifndef __IWkHtmlToXCallBack_FWD_DEFINED__
#define __IWkHtmlToXCallBack_FWD_DEFINED__
typedef interface IWkHtmlToXCallBack IWkHtmlToXCallBack;
#endif 	/* __IWkHtmlToXCallBack_FWD_DEFINED__ */


#ifndef __IWkHtmlToPdf_FWD_DEFINED__
#define __IWkHtmlToPdf_FWD_DEFINED__
typedef interface IWkHtmlToPdf IWkHtmlToPdf;
#endif 	/* __IWkHtmlToPdf_FWD_DEFINED__ */


#ifndef __IWkHtmlToImage_FWD_DEFINED__
#define __IWkHtmlToImage_FWD_DEFINED__
typedef interface IWkHtmlToImage IWkHtmlToImage;
#endif 	/* __IWkHtmlToImage_FWD_DEFINED__ */


#ifndef __CompReg_FWD_DEFINED__
#define __CompReg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CompReg CompReg;
#else
typedef struct CompReg CompReg;
#endif /* __cplusplus */

#endif 	/* __CompReg_FWD_DEFINED__ */


#ifndef __WkHtmlToPdf_FWD_DEFINED__
#define __WkHtmlToPdf_FWD_DEFINED__

#ifdef __cplusplus
typedef class WkHtmlToPdf WkHtmlToPdf;
#else
typedef struct WkHtmlToPdf WkHtmlToPdf;
#endif /* __cplusplus */

#endif 	/* __WkHtmlToPdf_FWD_DEFINED__ */


#ifndef __WkHtmlToImage_FWD_DEFINED__
#define __WkHtmlToImage_FWD_DEFINED__

#ifdef __cplusplus
typedef class WkHtmlToImage WkHtmlToImage;
#else
typedef struct WkHtmlToImage WkHtmlToImage;
#endif /* __cplusplus */

#endif 	/* __WkHtmlToImage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IComponentRegistrar_INTERFACE_DEFINED__
#define __IComponentRegistrar_INTERFACE_DEFINED__

/* interface IComponentRegistrar */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IComponentRegistrar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a817e7a2-43fa-11d0-9e44-00aa00b6770a")
    IComponentRegistrar : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ BSTR bstrPath) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetComponents( 
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UnregisterComponent( 
            /* [in] */ BSTR bstrCLSID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IComponentRegistrarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComponentRegistrar * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComponentRegistrar * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComponentRegistrar * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComponentRegistrar * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComponentRegistrar * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComponentRegistrar * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Attach )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrPath);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterAll )( 
            IComponentRegistrar * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *GetComponents )( 
            IComponentRegistrar * This,
            /* [out] */ SAFEARRAY * *pbstrCLSIDs,
            /* [out] */ SAFEARRAY * *pbstrDescriptions);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *RegisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UnregisterComponent )( 
            IComponentRegistrar * This,
            /* [in] */ BSTR bstrCLSID);
        
        END_INTERFACE
    } IComponentRegistrarVtbl;

    interface IComponentRegistrar
    {
        CONST_VTBL struct IComponentRegistrarVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComponentRegistrar_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComponentRegistrar_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComponentRegistrar_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComponentRegistrar_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComponentRegistrar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComponentRegistrar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComponentRegistrar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComponentRegistrar_Attach(This,bstrPath)	\
    ( (This)->lpVtbl -> Attach(This,bstrPath) ) 

#define IComponentRegistrar_RegisterAll(This)	\
    ( (This)->lpVtbl -> RegisterAll(This) ) 

#define IComponentRegistrar_UnregisterAll(This)	\
    ( (This)->lpVtbl -> UnregisterAll(This) ) 

#define IComponentRegistrar_GetComponents(This,pbstrCLSIDs,pbstrDescriptions)	\
    ( (This)->lpVtbl -> GetComponents(This,pbstrCLSIDs,pbstrDescriptions) ) 

#define IComponentRegistrar_RegisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> RegisterComponent(This,bstrCLSID) ) 

#define IComponentRegistrar_UnregisterComponent(This,bstrCLSID)	\
    ( (This)->lpVtbl -> UnregisterComponent(This,bstrCLSID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComponentRegistrar_INTERFACE_DEFINED__ */


#ifndef __IWkHtmlToXCallBack_INTERFACE_DEFINED__
#define __IWkHtmlToXCallBack_INTERFACE_DEFINED__

/* interface IWkHtmlToXCallBack */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWkHtmlToXCallBack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF9B8D22-6773-43AD-8EC5-74962D16FE2E")
    IWkHtmlToXCallBack : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE warning( 
            /* [in] */ ULONG converter,
            /* [in] */ BSTR message) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE error( 
            /* [in] */ ULONG converter,
            /* [in] */ BSTR message) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE phaseChanged( 
            /* [in] */ ULONG converter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE progressChanged( 
            /* [in] */ ULONG converter,
            /* [in] */ ULONG progress) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE finished( 
            /* [in] */ ULONG converter,
            /* [in] */ BOOL ok) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWkHtmlToXCallBackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWkHtmlToXCallBack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWkHtmlToXCallBack * This);
        
        HRESULT ( STDMETHODCALLTYPE *warning )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ ULONG converter,
            /* [in] */ BSTR message);
        
        HRESULT ( STDMETHODCALLTYPE *error )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ ULONG converter,
            /* [in] */ BSTR message);
        
        HRESULT ( STDMETHODCALLTYPE *phaseChanged )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ ULONG converter);
        
        HRESULT ( STDMETHODCALLTYPE *progressChanged )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ ULONG converter,
            /* [in] */ ULONG progress);
        
        HRESULT ( STDMETHODCALLTYPE *finished )( 
            IWkHtmlToXCallBack * This,
            /* [in] */ ULONG converter,
            /* [in] */ BOOL ok);
        
        END_INTERFACE
    } IWkHtmlToXCallBackVtbl;

    interface IWkHtmlToXCallBack
    {
        CONST_VTBL struct IWkHtmlToXCallBackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWkHtmlToXCallBack_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWkHtmlToXCallBack_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWkHtmlToXCallBack_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWkHtmlToXCallBack_warning(This,converter,message)	\
    ( (This)->lpVtbl -> warning(This,converter,message) ) 

#define IWkHtmlToXCallBack_error(This,converter,message)	\
    ( (This)->lpVtbl -> error(This,converter,message) ) 

#define IWkHtmlToXCallBack_phaseChanged(This,converter)	\
    ( (This)->lpVtbl -> phaseChanged(This,converter) ) 

#define IWkHtmlToXCallBack_progressChanged(This,converter,progress)	\
    ( (This)->lpVtbl -> progressChanged(This,converter,progress) ) 

#define IWkHtmlToXCallBack_finished(This,converter,ok)	\
    ( (This)->lpVtbl -> finished(This,converter,ok) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWkHtmlToXCallBack_INTERFACE_DEFINED__ */


#ifndef __IWkHtmlToPdf_INTERFACE_DEFINED__
#define __IWkHtmlToPdf_INTERFACE_DEFINED__

/* interface IWkHtmlToPdf */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWkHtmlToPdf;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DF4EF884-7B4F-445C-B012-02BB8B27589C")
    IWkHtmlToPdf : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE extendedQt( 
            /* [retval][out] */ BOOL *ext) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getVersion( 
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createGlobalSettings( 
            /* [retval][out] */ ULONG *gs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createObjectSettings( 
            /* [retval][out] */ ULONG *os) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setGlobalSetting( 
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getGlobalSetting( 
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setObjectSetting( 
            /* [in] */ ULONG os,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getObjectSetting( 
            /* [in] */ ULONG os,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createConverter( 
            /* [in] */ ULONG gs,
            /* [retval][out] */ ULONG *con) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE destroyConverter( 
            /* [in] */ ULONG cov) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE convert( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *ok) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE addObject( 
            /* [in] */ ULONG con,
            /* [in] */ ULONG os,
            /* [in] */ BSTR data) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE currentPhase( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE phaseCount( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE phaseDescription( 
            /* [in] */ ULONG con,
            /* [in] */ ULONG phase,
            /* [retval][out] */ BSTR *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE progressString( 
            /* [in] */ ULONG con,
            /* [retval][out] */ BSTR *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE httpErrorCode( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getOutput( 
            /* [in] */ ULONG con,
            /* [retval][out] */ SAFEARRAY * *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setCallBack( 
            /* [in] */ IWkHtmlToXCallBack *cb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWkHtmlToPdfVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWkHtmlToPdf * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWkHtmlToPdf * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWkHtmlToPdf * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWkHtmlToPdf * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWkHtmlToPdf * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWkHtmlToPdf * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWkHtmlToPdf * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *extendedQt )( 
            IWkHtmlToPdf * This,
            /* [retval][out] */ BOOL *ext);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getVersion )( 
            IWkHtmlToPdf * This,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createGlobalSettings )( 
            IWkHtmlToPdf * This,
            /* [retval][out] */ ULONG *gs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createObjectSettings )( 
            IWkHtmlToPdf * This,
            /* [retval][out] */ ULONG *os);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setGlobalSetting )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getGlobalSetting )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setObjectSetting )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG os,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getObjectSetting )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG os,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createConverter )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG gs,
            /* [retval][out] */ ULONG *con);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *destroyConverter )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG cov);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *convert )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *ok);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *addObject )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [in] */ ULONG os,
            /* [in] */ BSTR data);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *currentPhase )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *phaseCount )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *phaseDescription )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [in] */ ULONG phase,
            /* [retval][out] */ BSTR *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *progressString )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ BSTR *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *httpErrorCode )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getOutput )( 
            IWkHtmlToPdf * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ SAFEARRAY * *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setCallBack )( 
            IWkHtmlToPdf * This,
            /* [in] */ IWkHtmlToXCallBack *cb);
        
        END_INTERFACE
    } IWkHtmlToPdfVtbl;

    interface IWkHtmlToPdf
    {
        CONST_VTBL struct IWkHtmlToPdfVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWkHtmlToPdf_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWkHtmlToPdf_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWkHtmlToPdf_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWkHtmlToPdf_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWkHtmlToPdf_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWkHtmlToPdf_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWkHtmlToPdf_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWkHtmlToPdf_extendedQt(This,ext)	\
    ( (This)->lpVtbl -> extendedQt(This,ext) ) 

#define IWkHtmlToPdf_getVersion(This,ret)	\
    ( (This)->lpVtbl -> getVersion(This,ret) ) 

#define IWkHtmlToPdf_createGlobalSettings(This,gs)	\
    ( (This)->lpVtbl -> createGlobalSettings(This,gs) ) 

#define IWkHtmlToPdf_createObjectSettings(This,os)	\
    ( (This)->lpVtbl -> createObjectSettings(This,os) ) 

#define IWkHtmlToPdf_setGlobalSetting(This,gs,name,value,ok)	\
    ( (This)->lpVtbl -> setGlobalSetting(This,gs,name,value,ok) ) 

#define IWkHtmlToPdf_getGlobalSetting(This,gs,name,value)	\
    ( (This)->lpVtbl -> getGlobalSetting(This,gs,name,value) ) 

#define IWkHtmlToPdf_setObjectSetting(This,os,name,value,ok)	\
    ( (This)->lpVtbl -> setObjectSetting(This,os,name,value,ok) ) 

#define IWkHtmlToPdf_getObjectSetting(This,os,name,value)	\
    ( (This)->lpVtbl -> getObjectSetting(This,os,name,value) ) 

#define IWkHtmlToPdf_createConverter(This,gs,con)	\
    ( (This)->lpVtbl -> createConverter(This,gs,con) ) 

#define IWkHtmlToPdf_destroyConverter(This,cov)	\
    ( (This)->lpVtbl -> destroyConverter(This,cov) ) 

#define IWkHtmlToPdf_convert(This,con,ok)	\
    ( (This)->lpVtbl -> convert(This,con,ok) ) 

#define IWkHtmlToPdf_addObject(This,con,os,data)	\
    ( (This)->lpVtbl -> addObject(This,con,os,data) ) 

#define IWkHtmlToPdf_currentPhase(This,con,res)	\
    ( (This)->lpVtbl -> currentPhase(This,con,res) ) 

#define IWkHtmlToPdf_phaseCount(This,con,res)	\
    ( (This)->lpVtbl -> phaseCount(This,con,res) ) 

#define IWkHtmlToPdf_phaseDescription(This,con,phase,res)	\
    ( (This)->lpVtbl -> phaseDescription(This,con,phase,res) ) 

#define IWkHtmlToPdf_progressString(This,con,res)	\
    ( (This)->lpVtbl -> progressString(This,con,res) ) 

#define IWkHtmlToPdf_httpErrorCode(This,con,res)	\
    ( (This)->lpVtbl -> httpErrorCode(This,con,res) ) 

#define IWkHtmlToPdf_getOutput(This,con,res)	\
    ( (This)->lpVtbl -> getOutput(This,con,res) ) 

#define IWkHtmlToPdf_setCallBack(This,cb)	\
    ( (This)->lpVtbl -> setCallBack(This,cb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWkHtmlToPdf_INTERFACE_DEFINED__ */


#ifndef __IWkHtmlToImage_INTERFACE_DEFINED__
#define __IWkHtmlToImage_INTERFACE_DEFINED__

/* interface IWkHtmlToImage */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IWkHtmlToImage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39CD3CEE-D85C-492B-AC88-7C00A7F75A60")
    IWkHtmlToImage : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE extendedQt( 
            /* [retval][out] */ BOOL *ext) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getVersion( 
            /* [retval][out] */ BSTR *ret) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createGlobalSettings( 
            /* [retval][out] */ ULONG *gs) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setGlobalSetting( 
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getGlobalSetting( 
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE createConverter( 
            /* [in] */ ULONG gs,
            /* [in] */ BSTR data,
            /* [retval][out] */ ULONG *con) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE destroyConverter( 
            /* [in] */ ULONG cov) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE convert( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *ok) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE currentPhase( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE phaseCount( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE phaseDescription( 
            /* [in] */ ULONG con,
            /* [in] */ ULONG phase,
            /* [retval][out] */ BSTR *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE progressString( 
            /* [in] */ ULONG con,
            /* [retval][out] */ BSTR *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE httpErrorCode( 
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getOutput( 
            /* [in] */ ULONG con,
            /* [retval][out] */ SAFEARRAY * *res) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setCallBack( 
            /* [in] */ IWkHtmlToXCallBack *cb) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWkHtmlToImageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWkHtmlToImage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWkHtmlToImage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWkHtmlToImage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IWkHtmlToImage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IWkHtmlToImage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IWkHtmlToImage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IWkHtmlToImage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *extendedQt )( 
            IWkHtmlToImage * This,
            /* [retval][out] */ BOOL *ext);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getVersion )( 
            IWkHtmlToImage * This,
            /* [retval][out] */ BSTR *ret);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createGlobalSettings )( 
            IWkHtmlToImage * This,
            /* [retval][out] */ ULONG *gs);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setGlobalSetting )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [in] */ BSTR value,
            /* [retval][out] */ BOOL *ok);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getGlobalSetting )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG gs,
            /* [in] */ BSTR name,
            /* [retval][out] */ BSTR *value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *createConverter )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG gs,
            /* [in] */ BSTR data,
            /* [retval][out] */ ULONG *con);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *destroyConverter )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG cov);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *convert )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *ok);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *currentPhase )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *phaseCount )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *phaseDescription )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [in] */ ULONG phase,
            /* [retval][out] */ BSTR *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *progressString )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ BSTR *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *httpErrorCode )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ ULONG *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getOutput )( 
            IWkHtmlToImage * This,
            /* [in] */ ULONG con,
            /* [retval][out] */ SAFEARRAY * *res);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *setCallBack )( 
            IWkHtmlToImage * This,
            /* [in] */ IWkHtmlToXCallBack *cb);
        
        END_INTERFACE
    } IWkHtmlToImageVtbl;

    interface IWkHtmlToImage
    {
        CONST_VTBL struct IWkHtmlToImageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWkHtmlToImage_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IWkHtmlToImage_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IWkHtmlToImage_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IWkHtmlToImage_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IWkHtmlToImage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IWkHtmlToImage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IWkHtmlToImage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IWkHtmlToImage_extendedQt(This,ext)	\
    ( (This)->lpVtbl -> extendedQt(This,ext) ) 

#define IWkHtmlToImage_getVersion(This,ret)	\
    ( (This)->lpVtbl -> getVersion(This,ret) ) 

#define IWkHtmlToImage_createGlobalSettings(This,gs)	\
    ( (This)->lpVtbl -> createGlobalSettings(This,gs) ) 

#define IWkHtmlToImage_setGlobalSetting(This,gs,name,value,ok)	\
    ( (This)->lpVtbl -> setGlobalSetting(This,gs,name,value,ok) ) 

#define IWkHtmlToImage_getGlobalSetting(This,gs,name,value)	\
    ( (This)->lpVtbl -> getGlobalSetting(This,gs,name,value) ) 

#define IWkHtmlToImage_createConverter(This,gs,data,con)	\
    ( (This)->lpVtbl -> createConverter(This,gs,data,con) ) 

#define IWkHtmlToImage_destroyConverter(This,cov)	\
    ( (This)->lpVtbl -> destroyConverter(This,cov) ) 

#define IWkHtmlToImage_convert(This,con,ok)	\
    ( (This)->lpVtbl -> convert(This,con,ok) ) 

#define IWkHtmlToImage_currentPhase(This,con,res)	\
    ( (This)->lpVtbl -> currentPhase(This,con,res) ) 

#define IWkHtmlToImage_phaseCount(This,con,res)	\
    ( (This)->lpVtbl -> phaseCount(This,con,res) ) 

#define IWkHtmlToImage_phaseDescription(This,con,phase,res)	\
    ( (This)->lpVtbl -> phaseDescription(This,con,phase,res) ) 

#define IWkHtmlToImage_progressString(This,con,res)	\
    ( (This)->lpVtbl -> progressString(This,con,res) ) 

#define IWkHtmlToImage_httpErrorCode(This,con,res)	\
    ( (This)->lpVtbl -> httpErrorCode(This,con,res) ) 

#define IWkHtmlToImage_getOutput(This,con,res)	\
    ( (This)->lpVtbl -> getOutput(This,con,res) ) 

#define IWkHtmlToImage_setCallBack(This,cb)	\
    ( (This)->lpVtbl -> setCallBack(This,cb) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IWkHtmlToImage_INTERFACE_DEFINED__ */



#ifndef __wkhtmltoxcomLib_LIBRARY_DEFINED__
#define __wkhtmltoxcomLib_LIBRARY_DEFINED__

/* library wkhtmltoxcomLib */
/* [custom][helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_wkhtmltoxcomLib;

EXTERN_C const CLSID CLSID_CompReg;

#ifdef __cplusplus

class DECLSPEC_UUID("5D704535-1CCC-4936-A9A5-9B9013998107")
CompReg;
#endif

EXTERN_C const CLSID CLSID_WkHtmlToPdf;

#ifdef __cplusplus

class DECLSPEC_UUID("C156B9C6-7E0E-4FD7-B510-F6131F3A4A62")
WkHtmlToPdf;
#endif

EXTERN_C const CLSID CLSID_WkHtmlToImage;

#ifdef __cplusplus

class DECLSPEC_UUID("6F7A8025-AA5C-4B53-A764-B60CD93FA4CC")
WkHtmlToImage;
#endif
#endif /* __wkhtmltoxcomLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long *, unsigned long            , LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long *, unsigned char *, LPSAFEARRAY * ); 
unsigned char * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long *, unsigned char *, LPSAFEARRAY * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long *, LPSAFEARRAY * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


