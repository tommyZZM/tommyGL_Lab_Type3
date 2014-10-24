#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output

/*
************************************************
* LabMsg�ж�����Windows��Ϣ����Ӧ����
* CLabView�����ڿͻ������ݵĻ���
* CLabInteract�����ڳ���Ľ���
* �������������Ҫ������
* ��Ϣ��Ӧ������ӳ��������MsgList�ҵ�!
************************************************
*/
#ifndef _LABMSG_H_
#define _LABMSG_H_
#pragma once
#include "Render/OpenGL/RenderGL.h"

//CLabView�����ڿͻ������ݵĻ���
class CLabView
{
public:
	HINSTANCE           hInstance;           // ��ǰʵ��
	HWND                m_hWnd;              // ���ڤξ��

public:
	CLabView(void);
	~CLabView(void);

//��Ϣ��Ӧ����
public:
	int OnCreate(HWND);
	int OnPaint(HWND);
	int OnSize(HWND,int,int);
	int OnDestroy(HWND);//��ʱ��Ⱦ����

//���ƺ���
	int OnDraw(HWND,HDC);//���ƺ���
	int OnRender();//��ʱ��Ⱦ����

//���Ժ���
	void testDrawFun(HWND hWnd,HDC hdc);

public:
	//HANDLE Render3Dhand;
	CLabGL* WndRender3D; //Render3D
};
extern CLabView* MyView;//ָ��ʵ����

extern DWORD WINAPI Render3DThreadProc(LPVOID lpParameter);

/*CLabInteract�����ڳ���Ľ���*/
class CLabInteract
{
public:
	CLabInteract(void);
	~CLabInteract(void);

//��Ϣ��Ӧ����
public:
	int OnGetMinMaxInfo(HWND,WPARAM,LPARAM);

};
extern CLabInteract* MyInteract;//ָ��ʵ����



#endif



