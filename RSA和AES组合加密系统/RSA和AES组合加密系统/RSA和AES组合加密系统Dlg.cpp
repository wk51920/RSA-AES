
// RSA��AES��ϼ���ϵͳDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RSA��AES��ϼ���ϵͳ.h"
#include "RSA��AES��ϼ���ϵͳDlg.h"
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CRSA��AES��ϼ���ϵͳDlg �Ի���



CRSA��AES��ϼ���ϵͳDlg::CRSA��AES��ϼ���ϵͳDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CRSA��AES��ϼ���ϵͳDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRSA��AES��ϼ���ϵͳDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRSA��AES��ϼ���ϵͳDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT2, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT4, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit6)
	ON_BN_CLICKED(IDC_BUTTON4, &CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// CRSA��AES��ϼ���ϵͳDlg ��Ϣ�������

BOOL CRSA��AES��ϼ���ϵͳDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CRSA��AES��ϼ���ϵͳDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CRSA��AES��ϼ���ϵͳDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CRSA��AES��ϼ���ϵͳDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString skey;
	GetDlgItemText(IDC_EDIT5,skey);
	char key[16]={0};
	for(int i=0;skey[i]!='\0';i++)
		key[i]=skey[i];
	CString FilePathName;
	ifstream icipher;
	ofstream ocipher;
    CFileDialog dlg(TRUE);//TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
		char str[200]={0};
		icipher.open(FilePathName);
		icipher.getline(str,100);
	    icipher.close();
		AES sys_aes;
		sys_aes.setkey(key);
		sys_aes.Cipher((void *)str);       //AES����
		ocipher.open(FilePathName);
		ocipher<<str;
		ocipher.close();
        CString captain=_T("��ʾ");
        CString message=_T("AES���ܳɹ���");
        MessageBox(message,captain,MB_OK);
	}
	else{
	}
}



void CRSA��AES��ϼ���ϵͳDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    CString skey;
	GetDlgItemText(IDC_EDIT6,skey);
	char key[16]={0};
	for(int i=0;skey[i]!='\0';i++)
		key[i]=skey[i];
	CString FilePathName;
	ifstream icipher;
	ofstream ocipher;
    CFileDialog dlg(TRUE);//TRUEΪOPEN�Ի���FALSEΪSAVE AS�Ի���
	if(dlg.DoModal()==IDOK)
	{
		FilePathName=dlg.GetPathName(); //�ļ�����������FilePathName��
		char str[200]={0};
		icipher.open(FilePathName);
		icipher.getline(str,100);
	    icipher.close();
		int num=0;
		for(int i=0;str[i]!='\0';i++)
			num++;
		AES sys_aes;
		sys_aes.setkey(key);
		sys_aes.InvCipher((void *)str,num+1);    //AES����
		ocipher.open(FilePathName);
		ocipher<<str;
		ocipher.close();
        CString captain=_T("��ʾ");
        CString message=_T("AES���ܳɹ���");
        MessageBox(message,captain,MB_OK);
	}
	else{
	}
}


void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}





void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CRSA��AES��ϼ���ϵͳDlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


