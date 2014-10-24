//CLabView������ʵ�ֿͻ������ݵĻ��Ƶķ���

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
	GetWindowRect(hWnd, &rect);//��ô��ڴ�С(rect��һ���������ڳߴ�(left\top\right\bottom)�Ĵ���ṹ)

	OnDraw(hWnd,hdc);
	//************  TODO: OnDraw  ************
	EndPaint(hWnd, &ps);
	return 0;
}

int CLabView::OnDraw(HWND hWnd,HDC hdc)
{
	// NOTE: ����
	WndRender3D->Render();
	// TODO: �ڴ���������ͼ�����_��...
	::SwapBuffers(hdc);
	//testDrawFun(hWnd,hdc);

	return 0;
}

int CLabView::OnSize(HWND hWnd, int height, int width)
{
	WndRender3D->Resize(height,width);
	return 0;
}

//��ʱ��Ⱦ����
int CLabView::OnRender()
{
	OnPaint(m_hWnd);
	return 0;
}

//�رմ����ͷŻ���
int CLabView::OnDestroy(HWND hWnd)
{
	HDC hdc;
	hdc=GetDC(hWnd);
	ReleaseDC(hWnd,hdc);

	WndRender3D->Destroy();

	return 0;
}

//���Ի��ƺ���
void CLabView::testDrawFun(HWND hWnd,HDC hdc)
{
	static char stime[] = "23:59:59";
	SYSTEMTIME tm;
	::GetLocalTime(&tm);
	sprintf(stime, "%.2d:%.2d:%.2d", tm.wHour, tm.wMinute, tm.wSecond);
	::TextOut(hdc, 10, 10,(LPCSTR)stime, strlen(stime));
}