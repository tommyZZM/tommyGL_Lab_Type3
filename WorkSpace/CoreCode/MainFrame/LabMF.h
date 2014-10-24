/*
************************************************
* LabMF�ж����˳����ʼ��������,���ں�ע�ᴴ���ȷ���
* ����CLabWnd��,->LabWnd.cpp
* ����CLabApp��,->LabApp.cpp
************************************************
*/

#pragma once
#include "../../Win32Core.h"
#include "MsgList.h"

//HINSTANCE m_hInst;								                  // (backup)

//CLabWnd�����ڴ��ڵĴ����ͳ�ʼ��
class CLabWnd
{
//��������
public:
	HDC			        m_hDC;               // �豸����(GDI Device Context)
	HGLRC		        m_hRC;               // ��Ⱦ����(Rendering Context)
	WNDCLASSEX          wcex;   
	HINSTANCE           hInstance;           // ��ǰʵ��
	HWND                m_hWnd;              // ���ڤξ��

	int     win_posx;
	int     win_posy;
	int     win_width;
	int     win_height;
	char*   win_title;

//��������
public:
	BOOL RegWndEx();                      //ע�ᴰ����Ex
	BOOL CreateWndEx();                   //��������Ex
	BOOL ShowWindow();                    //��ʾ����
	BOOL UpdateWindow();                  //ͨ������һ��WM_PAINT��Ϣ������ָ�����ڵĿͻ���

	BOOL KillWindow();

	CLabWnd();
	~CLabWnd();

	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);   //��������Ϣ(�ص�)������

};

//CLabApp�����ڳ���ĳ�ʼ��������
class CLabApp
{
public:
	CLabWnd* m_MainWnd;

public:
	CLabApp();//void
	~CLabApp();

	BOOL InitInstance();
	void InitMsgClass();//��ʼ����Ϣ��Ӧ��ʵ��
	BOOL Run();//��Ϣѭ��(��׼��)
	BOOL Exit();//��Ϣѭ��(��׼��)

public:
	HANDLE m_phWait;
	DWORD m_dwRet;
	BOOL m_exit;
	BOOL intRunEx();
	BOOL RunEx(bool);//��Ϣѭ��(������)

};

