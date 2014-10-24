/*
************************************************
* CLabWnd类用于窗口的创建和初始化的方法
************************************************
*/

#pragma once
#include "LabMF.h"

//初始化变量值
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

//虚函数
CLabWnd::~CLabWnd(void){}

//注册窗口类函数
BOOL CLabWnd::RegWndEx()
{                               
	wcex.cbSize = sizeof(WNDCLASSEX);                                                       // 窗口类EX结构

	wcex.style			= CS_HREDRAW | CS_VREDRAW | CS_OWNDC;                               // 设定窗口样式
	wcex.lpfnWndProc	= (WNDPROC)WndProc;                                                 // 处理windows消息的指针指向WndProc函数
	wcex.cbClsExtra		= 0;                                                                // 没有额外的数据，不需要申请内存量
	wcex.cbWndExtra		= 0;                                                                // No Extra Window Data
	wcex.hInstance		= hInstance;                                                        // 设置实例 (Set The Instance)
	wcex.hIcon			= NULL;                                                             // 载入窗口图标 (Load The Default Icon)
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);                                      // 载入窗口指针 (Load The Arrow Pointer)
	wcex.hbrBackground	= NULL;                           // 背景         (OpenGL实验室不需要背景/(HBRUSH) GetStockObject (LTGRAY_BRUSH))
	wcex.lpszMenuName	= NULL;                                                             // 菜单         Default:(MAKEINTRESOURCE(IDC_SAMPLEWIN32);
	wcex.lpszClassName	= "tommyGLabMFWnd";                                                 // 描述窗口类名
	wcex.hIconSm		= NULL;                                                             // 载入图标(?)

	if (RegisterClassEx(&wcex)) // 返回注册窗口是否成功
	{
		return TRUE;
	} 
	else
	{
		MessageBox(NULL,"注册窗口类失败!","错误",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	 

}

//创建窗口(EX)函数
BOOL CLabWnd::CreateWndEx()
{
	RECT		        WindowRect;				                 // 窗口尺寸(left\top\right\bottom)参数包括该窗口的/左侧/顶部/右侧/底部坐标
	DWORD		        dwExStyle;				                 // 窗口扩展类型           (Window Extended Style)
	DWORD		        dwStyle;				                 // 窗口类型               (Window Style)
	 
	WindowRect.left=win_posx;		                             // 窗口左上角x坐标(CW_USEDEFAULT表示缺省默认)
	WindowRect.right=win_posx+(long)win_width;		                    // ...
	WindowRect.top=win_posy;				                     // 窗口左上角y坐标
	WindowRect.bottom=win_posy+(long)win_height;	                    // ...

	dwExStyle= WS_EX_WINDOWEDGE;			                     // 设置窗口扩展类型
	dwStyle=WS_OVERLAPPEDWINDOW;                                 // 设置窗口类型

	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);  // 设置窗口到所申请大小

	m_hWnd=CreateWindowEx(                                       // 获得窗口句柄
		dwExStyle,							                     // Extended Style For The Window
		"tommyGLabMFWnd",							             // 类名szWindowClass
		win_title,								                 // 窗口标题
		dwStyle |							                     // 定义窗口类型
		WS_CLIPSIBLINGS |					                     // 窗口类型
		WS_CLIPCHILDREN,					                     // 窗口类型
		CW_USEDEFAULT, CW_USEDEFAULT,				             // 窗口位置
		(long)win_width,	                                     // 计算窗口宽
		(long)win_height,	                                     // 计算窗口高
		NULL,								                     // 子窗口(NULL)
		NULL,								                     // 菜单(NULL)
		hInstance,							                     // 实例
		NULL);                                                   // 不发送消息到 WM_CREATE

	if (!m_hWnd)							         	
	{
		//KillGLWindow();								// 创建失败,关闭窗口
		MessageBox(NULL,"创建窗口失败!","错误",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;								    // Return FALSE (程序关闭)
	}
	else
		return TRUE;
}

//显示窗口函数
BOOL CLabWnd::ShowWindow()
{
	return ::ShowWindow(m_hWnd, SW_SHOWNORMAL);
}

//更新窗口函数
BOOL CLabWnd::UpdateWindow()
{
	return ::UpdateWindow(m_hWnd);
}

BOOL CLabWnd::KillWindow()
{
	return FALSE;
}
