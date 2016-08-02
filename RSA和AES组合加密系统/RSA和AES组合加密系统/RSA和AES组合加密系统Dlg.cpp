
// RSA和AES组合加密系统Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "RSA和AES组合加密系统.h"
#include "RSA和AES组合加密系统Dlg.h"
#include "afxdialogex.h"
#include "RSA.h"
#include "AES.h"
#include "stdlib.h"
#include <cstdio>
#include <bitset>
#include <string>
#include <fstream>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRSA和AES组合加密系统Dlg 对话框



CRSA和AES组合加密系统Dlg::CRSA和AES组合加密系统Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRSA和AES组合加密系统Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSA和AES组合加密系统Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRSA和AES组合加密系统Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRSA和AES组合加密系统Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRSA和AES组合加密系统Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRSA和AES组合加密系统Dlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CRSA和AES组合加密系统Dlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON4, &CRSA和AES组合加密系统Dlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CRSA和AES组合加密系统Dlg 消息处理程序

BOOL CRSA和AES组合加密系统Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CRSA和AES组合加密系统Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CRSA和AES组合加密系统Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CRSA和AES组合加密系统Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRSA和AES组合加密系统Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1;
	GetDlgItemText(IDC_EDIT1,str1);
	rsa sys_rsa; 
	sys_rsa.creat_pqnfned();
	char input[16]={0};
	char output[1024];
	char *p =output;
	for(int i=0;str1[i]!='\0';i++)
		input[i]=str1[i];	
	bytes_to_big(16,input,sys_rsa.m); 
	sys_rsa.rsa_encrypt();
	cotstr(sys_rsa.c,p);
    CString str2(output);
	SetDlgItemText(IDC_EDIT2,str2);
	mirkill(sys_rsa.m);
	mirkill(sys_rsa.c);
	mirkill(sys_rsa.p);
	mirkill(sys_rsa.q);
	mirkill(sys_rsa.e);
	mirkill(sys_rsa.d);
	mirkill(sys_rsa.p1);
	mirkill(sys_rsa.q1);
	mirkill(sys_rsa.n);
	mirkill(sys_rsa.fn);
	mirexit();
}


void CRSA和AES组合加密系统Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
    CString str1;
	GetDlgItemText(IDC_EDIT3,str1);
	rsa sys_rsa; 
	sys_rsa.creat_pqnfned();
	char input[500]={0};
	char output[16];
	char *p=input;
	int i;
	for(i=0;str1[i]!='\0';i++)
		input[i]=str1[i];
	cinstr(sys_rsa.c,p);
	sys_rsa.rsa_decrypt();
    big_to_bytes(16,sys_rsa.m,output,FALSE);
    CString str2(output);
	CString str3=str2.Left(16);
	SetDlgItemText(IDC_EDIT4,str3);
	mirkill(sys_rsa.m);
	mirkill(sys_rsa.c);
	mirkill(sys_rsa.p);
	mirkill(sys_rsa.q);
	mirkill(sys_rsa.e);
	mirkill(sys_rsa.d);
	mirkill(sys_rsa.p1);
	mirkill(sys_rsa.q1);
	mirkill(sys_rsa.n);
	mirkill(sys_rsa.fn);
	mirexit();
}


void CRSA和AES组合加密系统Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString skey;
	GetDlgItemText(IDC_EDIT5,skey);
	char key[16]={0};
	for(int i=0;skey[i]!='\0';i++)
		key[i]=skey[i];
	CString FilePathName;
	ifstream icipher;
	ofstream ocipher;
    CFileDialog dlg(TRUE);//TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		char str[200]={0};
		icipher.open(FilePathName);
		icipher.getline(str,100);
	    icipher.close();
		AES sys_aes;
		sys_aes.setkey(key);
		sys_aes.Cipher((void *)str);       //AES加密
		ocipher.open(FilePathName);
		ocipher<<str;
		ocipher.close();
        CString captain=_T("提示");
        CString message=_T("AES加密成功！");
        MessageBox(message,captain,MB_OK);
	}
	else{
	}
}



void CRSA和AES组合加密系统Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
    CString skey;
	GetDlgItemText(IDC_EDIT6,skey);
	char key[16]={0};
	for(int i=0;skey[i]!='\0';i++)
		key[i]=skey[i];
	CString FilePathName;
	ifstream icipher;
	ofstream ocipher;
    CFileDialog dlg(TRUE);//TRUE为OPEN对话框，FALSE为SAVE AS对话框
	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //文件名保存在了FilePathName里
		char str[200]={0};
		icipher.open(FilePathName);
		icipher.getline(str,100);
	    icipher.close();
		int num=0;
		for(int i=0;str[i]!='\0';i++)
			num++;
		AES sys_aes;
		sys_aes.setkey(key);
		sys_aes.InvCipher((void *)str,num+1);    //AES解密
		ocipher.open(FilePathName);
		ocipher<<str;
		ocipher.close();
        CString captain=_T("提示");
        CString message=_T("AES解密成功！");
        MessageBox(message,captain,MB_OK);
	}
	else{
	}
}


void CRSA和AES组合加密系统Dlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}

void CRSA和AES组合加密系统Dlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}

void CRSA和AES组合加密系统Dlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}





void CRSA和AES组合加密系统Dlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void CRSA和AES组合加密系统Dlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void CRSA和AES组合加密系统Dlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


