/*
************************************************
* CLabApp�����ڳ������кͳ�ʼ���ķ���(������)
************************************************
*/
#pragma once
#include "LabMF.h"
#include "LabMsg.h"

//Main������Ҫ����
CLabApp::CLabApp(void)
{
	m_exit= FALSE;
	m_MainWnd = NULL;

	intRunEx();//��ʼ����Ϣѭ��EX

	if (InitInstance())
	{
		//Run();
		RunEx(m_exit);
	}

	Exit();
}

CLabApp::~CLabApp(void){}

//��ʼ������
BOOL CLabApp::InitInstance()
{
	InitMsgClass();

	m_MainWnd = new CLabWnd();

	m_MainWnd->RegWndEx();
	m_MainWnd->CreateWndEx();
	m_MainWnd->ShowWindow();
	return m_MainWnd->UpdateWindow();
}

//��ʼ����ʵ��
CLabView* MyView;
CLabInteract* MyInteract;

void CLabApp::InitMsgClass()
{
	MyView = new CLabView();
	MyInteract = new CLabInteract();
}

//���к���
//******************  ��Ϣѭ��(EX)  ************
BOOL CLabApp::intRunEx()
{
	LARGE_INTEGER liDueTime;
	m_phWait = CreateWaitableTimer(NULL,FALSE,NULL);
	liDueTime.QuadPart=-1i64;
	SetWaitableTimer(m_phWait,&liDueTime, 10, NULL, NULL, 0);
	//m_dwRet = 0;

	if (m_phWait == NULL)
	{
		MessageBox(NULL,"��ʼ��ʧ��!","����",MB_OK|MB_ICONEXCLAMATION);
		RaiseException(EXCEPTION_INVALID_HANDLE, 0, 0, 0);
		return FALSE;
	} 
	else
	{
		return TRUE;
	}
}

BOOL CLabApp::RunEx(bool exit)
{
	MSG msg;
	//const HANDLE* phWait = &m_phWait;
	int i;

	while(!exit)
	{
		m_dwRet = ::MsgWaitForMultipleObjects(1,&m_phWait,FALSE,INFINITE,QS_ALLINPUT);
		i = m_dwRet;
		switch(m_dwRet)
		{
		case WAIT_OBJECT_0:
			{//��Ⱦ����
				::MyView->OnRender();
				break;
			}
		case WAIT_OBJECT_0+1:
			{//������Ϣ
				if(::PeekMessage(&msg,NULL,0,0,PM_REMOVE))
				{
					if(WM_QUIT!= msg.message)
					{
						::TranslateMessage(&msg);                                    
						::DispatchMessage(&msg);
					}
					else
					{
						exit = TRUE;
					}
				}
				else
					break;//��סҪbreakŶ
			}
		default:
			break;
		}
	}
	return TRUE;
}

//******************  ��Ϣѭ��(��׼��)  ************
BOOL CLabApp::Run()
{
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return TRUE;
}
//

//�رպ���(�ڴ��ͷ��ڴ�)
BOOL CLabApp::Exit()
{
	return TRUE;
}