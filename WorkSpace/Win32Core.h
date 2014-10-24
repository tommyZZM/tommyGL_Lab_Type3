/*tommy's OpenGL Win32 Foundation Classes*/

#pragma once
#include "stdafx.h"
#include "resource.h"

#include <windows.h>		// Header File For Windows
#include <stdio.h>			// Header File For Standard Input/Output
#include <gl\glew.h>		// Header File For The Glew Library
#include <gl\gl.h>			// Header File For The OpenGL32 Library
#include <gl\glu.h>			// Header File For The GLu32 Library
#include <gl\glut.h>		    // Header File For The Glut Library
#include <gl\glaux.h>		// Header File For The Glaux Library

// 全局变量:
#define MAX_LOADSTRING 100
#define WINDOW_TITLE        "Tommy IncuBeta Lab"; 
#define APP_VERSION          "Type3 Alpha";
#define WINDOW_WIDTH0       640;
#define WINDOW_HEIGHT0      480;

DWORD WINAPI RenderThreadProc(LPVOID lpParameter);

INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);        //关于框

