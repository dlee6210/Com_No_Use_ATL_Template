/*
Com�ĵ���˳��:
1:�����ע��.����DllRegisterServer.
2:�ͻ��˵���CoCreateInstance.�ڲ�����˳��
	1:CoGetClassObject.ͨ��CLSID����ע���,�ҵ���ӦDLL.������.Ȼ�����DllGetClassObject.����һ���๤������
	2:ͨ�����๤���������ڲ�CreateInstance����.��ȡһ��Com����Ķ���
	3:ͨ����Com�������������ڲ���QuerInterface����.��ȡһ��Com�������ָ��.
	4:��������
3:ͨ�����ص����������з�������.
ע������:
1:def�ļ��ڲ��ĺ�������
2:����ڲ��ķ���������ʽ.
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