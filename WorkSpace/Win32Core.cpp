#pragma once
// Win32Core.cpp : ����Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include "Win32Core.h"
#include "CoreCode/MainFrame/LabMF.h"

CLabApp theApp;


//WinMain������Ҫ��һ���������ú����Ĺ����Ǳ�ϵͳ���ã���Ϊһ��32λӦ�ó������ڵ�  
//**  APIENTRY����WINAPI  //** WinMainǰ����_t��ʾ��unicode
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