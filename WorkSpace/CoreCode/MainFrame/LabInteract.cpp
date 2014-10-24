//CLabInteract类用于实现程序的交互的方法

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
	mminfo=(PMINMAXINFO)lParam;  //窗口尺寸最小值
	mminfo->ptMinTrackSize.x=320;  
	mminfo->ptMinTrackSize.y=240;  

	return 0;
}

