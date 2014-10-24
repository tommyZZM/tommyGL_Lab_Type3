//OpenGL
#pragma once
#include "../../../../Win32Core.h"

//ºÃ≥–CLabRender3D¿‡
class CLabD3D
{
public:
	CLabD3D();//void
	~CLabD3D();

public:
	void Init(HWND,int);
	void Render();
	void Resize(int width, int height);
	
};