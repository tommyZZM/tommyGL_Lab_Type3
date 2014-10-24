/*
************************************************
* CLabApp类用于程序运行和初始化的方法(主方法)
************************************************
*/
#pragma once
#include "LabMF.h"
#include "LabMsg.h"

//Main函数主要内容
CLabApp::CLabApp(void)
{
	m_exit= FALSE;
	m_MainWnd = NULL;

	intRunEx();//初始化消息循环EX

	if (InitInstance())
	{
		//Run();
		RunEx(m_exit);
	}

	Exit();
}

CLabApp::~CLabApp(void){}

//初始化函数
BOOL CLabApp::InitInstance()
{
	InitMsgClass();

	m_MainWnd = new CLabWnd();

	m_MainWnd->RegWndEx();
	m_MainWnd->CreateWndEx();
	m_MainWnd->ShowWindow();
	return m_MainWnd->UpdateWindow();
}

//初始化类实例
CLabView* MyView;
CLabInteract* MyInteract;

void CLabApp::InitMsgClass()
{
	MyView = new CLabView();
	MyInteract = new CLabInteract();
}

//运行函数
//******************  消息循环(EX)  ************
BOOL CLabApp::intRunEx()
{
	LARGE_INTEGER liDueTime;
	m_phWait = CreateWaitableTimer(NULL,FALSE,NULL);
	liDueTime.QuadPart=-1i64;
	SetWaitableTimer(m_phWait,&liDueTime, 10, NULL, NULL, 0);
	//m_dwRet = 0;

	if (m_phWait == NULL)
	{
		MessageBox(NULL,"初始化失败!","错误",MB_OK|MB_ICONEXCLAMATION);
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
			{//渲染场景
				::MyView->OnRender();
				break;
			}
		case WAIT_OBJECT_0+1:
			{//处理消息
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
					break;//记住要break哦
			}
		default:
			break;
		}
	}
	return TRUE;
}

//******************  消息循环(标准型)  ************
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

//关闭函数(在此释放内存)
BOOL CLabApp::Exit()
{
	return TRUE;
}