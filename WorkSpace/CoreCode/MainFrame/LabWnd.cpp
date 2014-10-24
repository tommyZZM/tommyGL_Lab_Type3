/*
************************************************
* CLabWnd�����ڴ��ڵĴ����ͳ�ʼ���ķ���
************************************************
*/

#pragma once
#include "LabMF.h"

//��ʼ������ֵ
CLabWnd::CLabWnd()
{
	m_hDC    = NULL;
	m_hRC     = NULL;
	m_hWnd    = NULL;
	hInstance = NULL;
	win_title = WINDOW_TITLE

	win_posx = 0;
	win_posy = 0;
	win_width= WINDOW_WIDTH0;
	win_height=WINDOW_HEIGHT0;
}

//�麯��
CLabWnd::~CLabWnd(void){}

//ע�ᴰ���ຯ��
BOOL CLabWnd::RegWndEx()
{                               
	wcex.cbSize = sizeof(WNDCLASSEX);                                                       // ������EX�ṹ

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                               // �趨������ʽ
	wcex.lpfnWndProc	= (WNDPROC)WndProc;                                                 // ����windows��Ϣ��ָ��ָ��WndProc����
	wcex.cbClsExtra		= 0;                                                                // û�ж�������ݣ�����Ҫ�����ڴ���
	wcex.cbWndExtra		= 0;                                                                // No Extra Window Data
	wcex.hInstance		= hInstance;                                                        // ����ʵ�� (Set The Instance)
	wcex.hIcon			= NULL;                                                             // ���봰��ͼ�� (Load The Default Icon)
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);                                      // ���봰��ָ�� (Load The Arrow Pointer)
	wcex.hbrBackground	= NULL;                           // ����         (OpenGLʵ���Ҳ���Ҫ����/(HBRUSH) GetStockObject (LTGRAY_BRUSH))
	wcex.lpszMenuName	= NULL;                                                             // �˵�         Default:(MAKEINTRESOURCE(IDC_SAMPLEWIN32);
	wcex.lpszClassName	= "tommyGLabMFWnd";                                                 // ������������
	wcex.hIconSm		= NULL;                                                             // ����ͼ��(?)

	if (RegisterClassEx(&wcex)) // ����ע�ᴰ���Ƿ�ɹ�
	{
		return TRUE;
	} 
	else
	{
		MessageBox(NULL,"ע�ᴰ����ʧ��!","����",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	 

}

//��������(EX)����
BOOL CLabWnd::CreateWndEx()
{
	RECT		        WindowRect;				                 // ���ڳߴ�(left\top\right\bottom)���������ô��ڵ�/���/����/�Ҳ�/�ײ�����
	DWORD		        dwExStyle;				                 // ������չ����           (Window Extended Style)
	DWORD		        dwStyle;				                 // ��������               (Window Style)
	 
	WindowRect.left=win_posx;		                             // �������Ͻ�x����(CW_USEDEFAULT��ʾȱʡĬ��)
	WindowRect.right=win_posx+(long)win_width;		                    // ...
	WindowRect.top=win_posy;				                     // �������Ͻ�y����
	WindowRect.bottom=win_posy+(long)win_height;	                    // ...

	dwExStyle= WS_EX_WINDOWEDGE;			                     // ���ô�����չ����
	dwStyle=WS_OVERLAPPEDWINDOW;                                 // ���ô�������

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);  // ���ô��ڵ��������С

	m_hWnd=CreateWindowEx(                                       // ��ô��ھ��
		dwExStyle,							                     // Extended Style For The Window
		"tommyGLabMFWnd",							             // ����szWindowClass
		win_title,								                 // ���ڱ���
		dwStyle |							                     // ���崰������
		WS_CLIPSIBLINGS |					                     // ��������
		WS_CLIPCHILDREN,					                     // ��������
		CW_USEDEFAULT, CW_USEDEFAULT,				             // ����λ��
		(long)win_width,	                                     // ���㴰�ڿ�
		(long)win_height,	                                     // ���㴰�ڸ�
		NULL,								                     // �Ӵ���(NULL)
		NULL,								                     // �˵�(NULL)
		hInstance,							                     // ʵ��
		NULL);                                                   // ��������Ϣ�� WM_CREATE

	if (!m_hWnd)							         	
	{
		//KillGLWindow();								// ����ʧ��,�رմ���
		MessageBox(NULL,"��������ʧ��!","����",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								    // Return FALSE (����ر�)
	}
	else
		return TRUE;
}

//��ʾ���ں���
BOOL CLabWnd::ShowWindow()
{
	return ::ShowWindow(m_hWnd, SW_SHOWNORMAL);
}

//���´��ں���
BOOL CLabWnd::UpdateWindow()
{
	return ::UpdateWindow(m_hWnd);
}

BOOL CLabWnd::KillWindow()
{
	return FALSE;
}
