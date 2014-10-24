/*
************************************************
* LabMF中定义了程序初始化和运行,窗口和注册创建等方法
* 包含CLabWnd类,->LabWnd.cpp
* 包含CLabApp类,->LabApp.cpp
************************************************
*/

#pragma once
#include "../../Win32Core.h"
#include "MsgList.h"

//HINSTANCE m_hInst;								                  // (backup)

//CLabWnd类用于窗口的创建和初始化
class CLabWnd
{
//公共变量
public:
	HDC			        m_hDC;               // 设备环境(GDI Device Context)
	HGLRC		        m_hRC;               // 渲染环境(Rendering Context)
	WNDCLASSEX          wcex;   
	HINSTANCE           hInstance;           // 当前实例
	HWND                m_hWnd;              // 窗口の句柄

	int     win_posx;
	int     win_posy;
	int     win_width;
	int     win_height;
	char*   win_title;

//公共函数
public:
	BOOL RegWndEx();                      //注册窗口类Ex
	BOOL CreateWndEx();                   //创建窗口Ex
	BOOL ShowWindow();                    //显示窗口
	BOOL UpdateWindow();                  //通过发送一个WM_PAINT消息来更新指定窗口的客户区

	BOOL KillWindow();

	CLabWnd();
	~CLabWnd();

	static LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);   //主窗口消息(回调)处理函数

};

//CLabApp类用于程序的初始化和运行
class CLabApp
{
public:
	CLabWnd* m_MainWnd;

public:
	CLabApp();//void
	~CLabApp();

	BOOL InitInstance();
	void InitMsgClass();//初始化消息响应类实例
	BOOL Run();//消息循环(标准型)
	BOOL Exit();//消息循环(标准型)

public:
	HANDLE m_phWait;
	DWORD m_dwRet;
	BOOL m_exit;
	BOOL intRunEx();
	BOOL RunEx(bool);//消息循环(复合型)

};

