//CLabInteract������ʵ�ֳ���Ľ����ķ���

#pragma once
#include "LabMsg.h"


CLabInteract::CLabInteract(void)
{
}


CLabInteract::~CLabInteract(void)
{
}


int CLabInteract::OnGetMinMaxInfo(HWND hWnd,WPARAM wParam,LPARAM lParam)
{
	MINMAXINFO *mminfo;  
	mminfo=(PMINMAXINFO)lParam;  //���ڳߴ���Сֵ
	mminfo->ptMinTrackSize.x=320;  
	mminfo->ptMinTrackSize.y=240;  

	return 0;
}

