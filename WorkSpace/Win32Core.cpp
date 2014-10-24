#pragma once
// Win32Core.cpp : 定义应用程序的入口点。

#include "stdafx.h"
#include "Win32Core.h"
#include "CoreCode/MainFrame/LabMF.h"

CLabApp theApp;


//WinMain是最主要的一个函数，该函数的功能是被系统调用，作为一个32位应用程序的入口点  
//**  APIENTRY类似WINAPI  //** WinMain前加上_t表示是unicode
int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	return 0;
}


INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}