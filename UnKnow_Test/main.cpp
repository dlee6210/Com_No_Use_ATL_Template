/*
Com的调用顺序:
1:组件的注册.调用DllRegisterServer.
2:客户端调用CoCreateInstance.内部调用顺序
	1:CoGetClassObject.通过CLSID查找注册表,找到对应DLL.并加载.然后调用DllGetClassObject.创建一个类工厂对象
	2:通过该类工厂调用其内部CreateInstance方法.获取一个Com组件的对象
	3:通过该Com组件对象调用其内部的QuerInterface方法.获取一个Com组件对象指针.
	4:方法返回
3:通过返回的组件对象进行方法调用.
注意事项:
1:def文件内部的函数导出
2:组件内部的方法声明方式.
*/
#include<stdio.h>
#include"CNxBase.h"

int main(int argc, char*argv[])
{
	CNxBase *cBase=nullptr;
	
	HRESULT hr = CoInitialize(NULL);
	
	hr = CoCreateInstance(GLSID_Base, NULL, CLSCTX_INPROC_SERVER, IID_Base, (LPVOID*)&cBase);
	cBase->AddRef();
	
	int num = cBase->Test();
	
	printf("%d\n",num);

	system("Pause");

	return 0;
}