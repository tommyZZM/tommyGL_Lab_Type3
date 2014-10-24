/*
************************************************
* MegList中定义了Windows消息到响应函数的映射表
* 请在下列映射表中插入或者添加相应的消息处理方法
* 格式:{ UINT Code,FXN Fxn, }
************************************************
*/

#pragma once
#include "LabMF.h"
#include "LabMsg.h"

//映射表
tagMESSAGEMAP MessageMaps []=
{
	WM_CREATE,OnCreate,
	WM_ACTIVATE,OnActivate,
	WM_COMMAND,OnCommand,
	WM_PAINT,OnPaint,
	WM_KEYDOWN,OnKeyDown,
	WM_KEYUP,OnKeyUp,
	WM_SIZE,OnSize,
	WM_GETMINMAXINFO,OnGetMinMaxInfo,
	WM_MOVE,OnMove,
	WM_DESTROY,OnDestroy,
	WM_DESTROY,OnClose,
};


/*************
*LabView
*************/
LRESULT OnCreate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MyView->OnCreate(hWnd);
	return 0;
}

LRESULT OnPaint(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MyView->OnPaint(hWnd);
	return 0;
}

LRESULT OnSize(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//LOWORD(lParam)=width;
	//HIWORD(lParam)=height;
	MyView->OnSize(hWnd,LOWORD(lParam),HIWORD(lParam));
	return 0;
}

LRESULT OnDestroy(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MyView->OnDestroy(hWnd);

	PostQuitMessage(0);
	return 0;
}


/*************
*LabInteract
*************/
LRESULT OnActivate(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT OnCommand(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;

	wmId    = LOWORD(wParam);
	wmEvent = HIWORD(wParam);
	// 分析菜单选择:
	switch (wmId)
	{
	case IDM_ABOUT:
		//DialogBox(hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
		break;
	case IDM_EXIT:
		DestroyWindow(hWnd);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

LRESULT OnGetMinMaxInfo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	MyInteract->OnGetMinMaxInfo(hWnd,wParam,lParam);
	return 0;
}

LRESULT OnMove(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT OnTimer(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT OnClose(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PostQuitMessage(0);
	return 0;
}

LRESULT OnKeyDown(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

LRESULT OnKeyUp(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	return 0;
}



//CLabWnd消息回调函数
LRESULT CALLBACK	CLabWnd::WndProc(HWND hWnd,         // 接收消息的窗口句柄
	UINT message,        // 被传送过来的消息
	WPARAM wParam,  // 消息响应机制参数
	LPARAM lParam      // 消息响应机制参数
	)     
{
	// 	int wmId, wmEvent;
	// 	PAINTSTRUCT ps;
	// 	HDC hdc;

	//响应消息映射表中的消息
	for (int i = 0; i < dim(MessageMaps); i++)
	{
		if (message == MessageMaps[i].Code)
		{
			FXN iFxn = MessageMaps[i].Fxn;
			LRESULT lResult = iFxn(hWnd, message, wParam, lParam);
			if (lResult == 0)
				return 0;
		}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}

