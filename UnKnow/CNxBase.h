#pragma once
/*
定一个com组件CNxBase.该组件继承IUnknown.需要实现三个方法.
*/
#include<comdef.h>
#include <initguid.h>

DEFINE_GUID(IID_Base,
	0xbc1d7aac, 0x965a, 0x4cc1, 0xb6, 0x4c, 0xeb, 0xfd, 0x76, 0xdd, 0xf3, 0x7b);
DEFINE_GUID(GLSID_Base,
	0x79518928, 0x2968, 0x4368, 0xaa, 0x8f, 0x3f, 0x83, 0xc4, 0x26, 0xf8, 0x8b);

class CNxBase:public IUnknown 
{
public:
	virtual HRESULT STDMETHODCALLTYPE QueryInterface(
		/* [in] */ REFIID riid,
		/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR *__RPC_FAR *ppvObject);

	virtual ULONG STDMETHODCALLTYPE AddRef(void);

	virtual ULONG STDMETHODCALLTYPE Release(void);
public:
	CNxBase();
	//com 外部调用必须声明为virual __stdcall类型
	virtual HRESULT STDMETHODCALLTYPE  Test();
};