//OpenGL
#pragma once
#include "../../../../Win32Core.h"

//ºÃ≥–CLabRender3D¿‡
class CLabGL
{
public:
	CLabGL();//void
	~CLabGL();

public:
	void Init(HWND,int);
	void Render();
	void Resize(int width, int height);
	void Destroy();

protected:
	HGLRC		        hRC;     // OpenGL‰÷»æª∑æ≥(Rendering Context)
	BOOL setGLpfd(HWND hWnd,int);// HDC hDC,HWND hWnd,HGLRC hRC
};