// UnKnow.h : UnKnow DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CUnKnowApp
// �йش���ʵ�ֵ���Ϣ������� UnKnow.cpp
//

class CUnKnowApp : public CWinApp
{
public:
	CUnKnowApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
