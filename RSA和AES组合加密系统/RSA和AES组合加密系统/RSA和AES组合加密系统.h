
// RSA��AES��ϼ���ϵͳ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRSA��AES��ϼ���ϵͳApp:
// �йش����ʵ�֣������ RSA��AES��ϼ���ϵͳ.cpp
//

class CRSA��AES��ϼ���ϵͳApp : public CWinApp
{
public:
	CRSA��AES��ϼ���ϵͳApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRSA��AES��ϼ���ϵͳApp theApp;