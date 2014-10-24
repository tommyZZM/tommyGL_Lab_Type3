#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output

/*
************************************************
* LabMsg中定义了Windows消息的响应函数
* CLabView类用于客户区内容的绘制
* CLabInteract类用于程序的交互
* 可以自行添加需要的类型
* 消息响应函数的映射表可以在MsgList找到!
************************************************
*/
#ifndef _LABMSG_H_
#define _LABMSG_H_
#pragma once
#include "Render/OpenGL/RenderGL.h"

//CLabView类用于客户区内容的绘制
class CLabView
{
public:
	HINSTANCE           hInstance;           // 当前实例
	HWND                m_hWnd;              // 窗口の句柄

public:
	CLabView(void);
	~CLabView(void);

//消息响应函数
public:
	int OnCreate(HWND);
	int OnPaint(HWND);
	int OnSize(HWND,int,int);
	int OnDestroy(HWND);//定时渲染函数

//绘制函数
	int OnDraw(HWND,HDC);//绘制函数
	int OnRender();//定时渲染函数

//测试函数
	void testDrawFun(HWND hWnd,HDC hdc);

public:
	//HANDLE Render3Dhand;
	CLabGL* WndRender3D; //Render3D
};
extern CLabView* MyView;//指针实例化

extern DWORD WINAPI Render3DThreadProc(LPVOID lpParameter);

/*CLabInteract类用于程序的交互*/
class CLabInteract
{
public:
	CLabInteract(void);
	~CLabInteract(void);

//消息响应函数
public:
	int OnGetMinMaxInfo(HWND,WPARAM,LPARAM);

};
extern CLabInteract* MyInteract;//指针实例化



#endif



