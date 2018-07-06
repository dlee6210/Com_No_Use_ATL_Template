#include "stdafx.h"
#include "NsClassFactory.h"
#include"CNxBase.h"

CNsClassFactory::CNsClassFactory()
{
}


CNsClassFactory::~CNsClassFactory()
{
}

STDMETHODIMP CNsClassFactory::QueryInterface(REFIID in_rIID, void ** out_ppv)
{
	if (in_rIID == IID_IUnknown || in_rIID== IID_IClassFactory)
	{
		*out_ppv = static_cast<CNsClassFactory*>(this);

	}
	static_cast<IUnknown *>(*out_ppv)->AddRef();

	return E_NOTIMPL;
}

STDMETHODIMP_(unsigned long) CNsClassFactory::AddRef()
{
	return 0;
}

STDMETHODIMP_(unsigned long) CNsClassFactory::Release()
{
	return 0;
}
//通过类工场对象进行调用.创建一个类对象.用于接口调用
HRESULT CNsClassFactory::CreateInstance(IUnknown * pUnkOuter, REFIID riid, void ** ppvObject)
{
	CNxBase *base = new CNxBase();
	
	*ppvObject = base;

	base->AddRef();

	return NO_ERROR;
}

HRESULT CNsClassFactory::LockServer(BOOL fLock)
{
	return E_NOTIMPL;
}
