#include"stdafx.h"
#include"CNxBase.h"
#include"NsClassFactory.h"

#define kNsCOMCharsInGuid 39
/*
组件注册时Regsvr32会调用DllRegisterServer.
*/
STDAPI DllRegisterServer()
{
	wchar_t wszTemp[MAX_PATH];

	wchar_t wszClsID[kNsCOMCharsInGuid];

	HRESULT hr = StringFromGUID2(GLSID_Base, wszClsID, kNsCOMCharsInGuid);

	wsprintfW(wszTemp, (L"CLSID\\%ls"), wszClsID);

	//Create Key
	HKEY hkey;
	LONG lReturn = RegCreateKeyW(HKEY_CLASSES_ROOT, wszTemp, &hkey);
	if (ERROR_SUCCESS != lReturn)
	{
		return HRESULT_FROM_WIN32(lReturn);
	}

	// set description string
	//
	wsprintfW(wszTemp, (L"%ls"), "UnKonw DLL");
	lReturn = RegSetValueW(hkey, (wchar_t *)NULL, REG_SZ, wszTemp, sizeof(wszTemp));
	if (ERROR_SUCCESS != lReturn)
	{
		RegCloseKey(hkey);
		return HRESULT_FROM_WIN32(lReturn);
	}
	// create CLSID\\{"CLSID"}\\"ServerType" key,
	// using key to CLSID\\{"CLSID"} passed back by
	// last call to RegCreateKey().
	//
	HKEY hsubkey;

	wsprintfW(wszTemp, (L"%ls"), L"InprocServer32");
	lReturn = RegCreateKeyW(hkey, wszTemp, &hsubkey);
	if (ERROR_SUCCESS != lReturn)
	{
		RegCloseKey(hkey);
		return HRESULT_FROM_WIN32(lReturn);
	}
	//
	// set Server string
	//
	wsprintfW(wszTemp, (L"%ls"), L"D:\\Git_Project\\C++11\\UnKnow\\Debug\\UnKnow.dll");
	lReturn = RegSetValueW(hsubkey, (LPCWSTR)NULL, REG_SZ, wszTemp, sizeof(wchar_t) * (lstrlenW(wszTemp) + 1));
	if (ERROR_SUCCESS != lReturn)
	{
		RegCloseKey(hkey);
		RegCloseKey(hsubkey);
		return HRESULT_FROM_WIN32(lReturn);
	}
	//Thread
	wsprintfW(wszTemp, (L"%ls"), L"Both");
	lReturn = RegSetValueExW(hsubkey,
		(L"ThreadingModel"),
		0L,
		REG_SZ,
		(CONST BYTE *)wszTemp,
		sizeof(wchar_t) * (lstrlenW(wszTemp) + 1));

	//
	// close hkeys
	//
	RegCloseKey(hkey);
	RegCloseKey(hsubkey);
	return S_OK;
}
STDAPI DllUnregisterServer()
{

	return S_OK;
}
STDAPI DllCanUnloadNow()
{

	return S_OK;
}
//第一步获取一个类工程对象
STDAPI DllGetClassObject(REFCLSID in_rsClsID,
	REFIID   in_rsIID,
	void   **out_ppv)
{
	HRESULT hr = NO_ERROR;

	if (in_rsClsID == GLSID_Base)
	{
		*out_ppv = (LPVOID)(LPUNKNOWN)new CNsClassFactory();
		
		if (*out_ppv == NULL)
			return E_OUTOFMEMORY;

		((LPUNKNOWN)*out_ppv)->AddRef();
	
		return NOERROR;
	}


	return hr;
}
CNxBase::CNxBase()
{

}
HRESULT CNxBase::Test()
{

	return 1;
}
HRESULT CNxBase::QueryInterface(REFIID riid, void ** ppvObject)
{
	if (riid == IID_Base)
	{
		*ppvObject = static_cast<CNxBase *>(this);
	}
	
	static_cast<IUnknown *>(*ppvObject)->AddRef();

	return S_OK;
}
ULONG CNxBase::AddRef(void)
{

	return 0;
}
ULONG CNxBase::Release(void)
{

	return 0;
}