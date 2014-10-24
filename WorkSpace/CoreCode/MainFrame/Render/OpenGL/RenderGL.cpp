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
	glClearColor (0.23f, 0.23f, 0.23f, 0.0f);                    //���ñ�����ɫrgb
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	//return TRUE;									         	// ��ʼ���ɹ�ʱ����True
}

GLvoid CLabGL::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(10,0,0,0,0,0,0.0,0.0,1.0);
	glPushMatrix();
	glColor3f(1.0,1.0,1.0);
	glLineWidth(1.0);
	glutWireCube(3.0);//�����÷���
	glPopMatrix();

	//glFinish();
	//return TRUE;
}

GLvoid CLabGL::Resize(int width, int height)
{
	if (height==0){height=1;}							// ��ֹ0����

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
	HDC			        hDC;                        // �豸����(GDI Device Context)
	GLuint              pixelformat;                // ���ظ�ʽ

	PIXELFORMATDESCRIPTOR GLpfd=				    // �������ظ�ʽ��
	{
		sizeof(PIXELFORMATDESCRIPTOR),				// ���ظ�ʽ������(Pixel Format Descriptor)��С
		1,											// �汾
		PFD_DRAW_TO_WINDOW |						// (��ʽ)֧��Window
		PFD_SUPPORT_OPENGL |						// (��ʽ)֧��OpenGL
		PFD_DOUBLEBUFFER,							// (��ʽ)֧��˫���弼��(Double Buffering)
		PFD_TYPE_RGBA,								// RGBA
		bits,										// ɫ��λ���
		0, 0, 0, 0, 0, 0,							// **Color Bits Ignored**                    NULL
		0,											// Alpha����(Alpha Buffer)                   NULL
		0,											// **Shift Bit Ignored**                     NULL
		0,											// �ۻ�����(Accumulation Buffer)             NULL
		0, 0, 0, 0,									// **Accumulation Bits Ignored**             NULL
		16,											// 16λ���(Z)���� (Z-Buffer(Depth Buffer))  NULL
		0,											// ģ�建��(Stencil Buffer)                  NULL
		0,											// ����������(Auxiliary Buffer)              NULL
		PFD_MAIN_PLANE,								// ����ͼ��
		0,											// ����..(Reserved)
		0, 0, 0										// ͼ���ɰ�(Layer Masks)                     NULL 
	};

	hDC         = GetDC(hWnd);
	pixelformat = ChoosePixelFormat(hDC,&GLpfd);
	SetPixelFormat(hDC,pixelformat,&GLpfd);
	hRC         = wglCreateContext(hDC);

	if (wglMakeCurrent(hDC,hRC))
	{
		//MessageBox(NULL,"�������ظ�ʽ�ɹ���Ӵ!","�ԣ�",MB_OK|MB_ICONEXCLAMATION);
		return TRUE;
	} 
	else
	{
		MessageBox(NULL,"����OpenGL���ظ�ʽʧ��!","����",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
}

