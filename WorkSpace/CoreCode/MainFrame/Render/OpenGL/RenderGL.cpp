//OpenGL
#pragma once
#include "RenderGL.h"

CLabGL::CLabGL(void)
{

}


CLabGL::~CLabGL(void)
{
}

GLvoid CLabGL::Init(HWND hWnd,int bits)
{
	setGLpfd(hWnd,bits);
	glClearColor (0.23f, 0.23f, 0.23f, 0.0f);                    //设置背景颜色rgb
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//return TRUE;									         	// 初始化成功时返回True
}

GLvoid CLabGL::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(10,0,0,0,0,0,0.0,0.0,1.0);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glLineWidth(1.0);
	glutWireCube(3.0);//测试用方块
	glPopMatrix();

	//glFinish();
	//return TRUE;
}

GLvoid CLabGL::Resize(int width, int height)
{
	if (height==0){height=1;}							// 防止0坐标

	//glViewport(0,0,640,480);						// Reset The Current Viewport
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluPerspective(60.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
}

GLvoid CLabGL::Destroy()
{
	wglMakeCurrent(NULL,NULL);
	wglDeleteContext(hRC);
}

BOOL CLabGL::setGLpfd(HWND hWnd,int bits)
{
	HDC			        hDC;                        // 设备环境(GDI Device Context)
	GLuint              pixelformat;                // 像素格式

	PIXELFORMATDESCRIPTOR GLpfd=				    // 设置像素格式表
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// 像素格式描述符(Pixel Format Descriptor)大小
		1,											// 版本
		PFD_DRAW_TO_WINDOW |						// (格式)支持Window
		PFD_SUPPORT_OPENGL |						// (格式)支持OpenGL
		PFD_DOUBLEBUFFER,							// (格式)支持双缓冲技术(Double Buffering)
		PFD_TYPE_RGBA,								// RGBA
		bits,										// 色彩位深度
		0, 0, 0, 0, 0, 0,							// **Color Bits Ignored**                    NULL
		0,											// Alpha缓存(Alpha Buffer)                   NULL
		0,											// **Shift Bit Ignored**                     NULL
		0,											// 累积缓存(Accumulation Buffer)             NULL
		0, 0, 0, 0,									// **Accumulation Bits Ignored**             NULL
		16,											// 16位深度(Z)缓存 (Z-Buffer(Depth Buffer))  NULL
		0,											// 模板缓冲(Stencil Buffer)                  NULL
		0,											// 辅助缓冲器(Auxiliary Buffer)              NULL
		PFD_MAIN_PLANE,								// 主绘图层
		0,											// 保留..(Reserved)
		0, 0, 0										// 图层蒙版(Layer Masks)                     NULL 
	};

	hDC         = GetDC(hWnd);
	pixelformat = ChoosePixelFormat(hDC,&GLpfd);
	SetPixelFormat(hDC,pixelformat,&GLpfd);
	hRC         = wglCreateContext(hDC);

	if (wglMakeCurrent(hDC,hRC))
	{
		//MessageBox(NULL,"设置像素格式成功了哟!","对！",MB_OK|MB_ICONEXCLAMATION);
		return TRUE;
	} 
	else
	{
		MessageBox(NULL,"设置OpenGL像素格式失败!","错误",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
}

