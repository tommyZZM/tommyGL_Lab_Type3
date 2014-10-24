//CLabView类用于实现客户区内容的绘制的方法

#pragma once
#include "LabMsg.h"

CLabView::CLabView(void)
{
	WndRender3D = new CLabGL();
}

CLabView::~CLabView(void)
{
}

int CLabView::OnCreate(HWND hWnd)
{
	m_hWnd = hWnd;
	WndRender3D->Init(hWnd,8);
	return 0;
}

int CLabView::OnPaint(HWND hWnd)
{
	RECT rect;
	PAINTSTRUCT ps;
	HDC hdc;

	hdc = BeginPaint(hWnd, &ps);
	//***************************************
	GetWindowRect(hWnd, &rect);//获得窗口大小(rect是一个包含窗口尺寸(left\top\right\bottom)的储存结构)

	OnDraw(hWnd,hdc);
	//************  TODO: OnDraw  ************
	EndPaint(hWnd, &ps);
	return 0;
}

int CLabView::OnDraw(HWND hWnd,HDC hdc)
{
	// NOTE: 绘制
	WndRender3D->Render();
	// TODO: 在此添加任意绘图代码∩_∩...
	::SwapBuffers(hdc);
	//testDrawFun(hWnd,hdc);

	return 0;
}

int CLabView::OnSize(HWND hWnd, int height, int width)
{
	WndRender3D->Resize(height,width);
	return 0;
}

//定时渲染函数
int CLabView::OnRender()
{
	OnPaint(m_hWnd);
	return 0;
}

//关闭窗口释放缓存
int CLabView::OnDestroy(HWND hWnd)
{
	HDC hdc;
	hdc=GetDC(hWnd);
	ReleaseDC(hWnd,hdc);

	WndRender3D->Destroy();

	return 0;
}

//测试绘制函数
void CLabView::testDrawFun(HWND hWnd,HDC hdc)
{
	static char stime[] = "23:59:59";
	SYSTEMTIME tm;
	::GetLocalTime(&tm);
	sprintf(stime, "%.2d:%.2d:%.2d", tm.wHour, tm.wMinute, tm.wSecond);
	::TextOut(hdc, 10, 10,(LPCSTR)stime, strlen(stime));
}