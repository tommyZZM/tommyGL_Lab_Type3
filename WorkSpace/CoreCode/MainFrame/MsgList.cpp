/*
************************************************
* MegList�ж�����Windows��Ϣ����Ӧ������ӳ���
* ��������ӳ����в�����������Ӧ����Ϣ������
* ��ʽ:{ UINT Code,FXN Fxn, }
************************************************
*/

#pragma once
#include "LabMF.h"
#include "LabMsg.h"

//ӳ���
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
	// �����˵�ѡ��:
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



//CLabWnd��Ϣ�ص�����
LRESULT CALLBACK	CLabWnd::WndProc(HWND hWnd,         // ������Ϣ�Ĵ��ھ��
	UINT message,        // �����͹�������Ϣ
	WPARAM wParam,  // ��Ϣ��Ӧ���Ʋ���
	LPARAM lParam      // ��Ϣ��Ӧ���Ʋ���
	)     
{
	// 	int wmId, wmEvent;
	// 	PAINTSTRUCT ps;
	// 	HDC hdc;

	//��Ӧ��Ϣӳ����е���Ϣ
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

