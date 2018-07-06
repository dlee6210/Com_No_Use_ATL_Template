#pragma once
/*
定一个CNsClassFactory.继续于IClassFactory.
需要实现CreateInstance.该方法里通过IID，创建一个
组件的实例.
*/
#include "Unknwn.h"
class CNsClassFactory :
	public IClassFactory
{
public:
	CNsClassFactory();
	~CNsClassFactory();
public:
	
	STDMETHODIMP QueryInterface(REFIID in_rIID,
		void **out_ppv);
	STDMETHODIMP_(unsigned long) AddRef();
	STDMETHODIMP_(unsigned long) Release();

	HRESULT STDMETHODCALLTYPE CreateInstance(
		/* [annotation][unique][in] */
		_In_opt_  IUnknown *pUnkOuter,
		/* [annotation][in] */
		_In_  REFIID riid,
		/* [annotation][iid_is][out] */
		_COM_Outptr_  void **ppvObject);
	
	HRESULT STDMETHODCALLTYPE LockServer(
		/* [in] */ BOOL fLock);
};

