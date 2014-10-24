#pragma once
//included by LabMF.h

//WM_��Ϣ��Ӧ����I����
LRESULT OnCreate(HWND, UINT, WPARAM, LPARAM);                          //View
LRESULT OnPaint(HWND, UINT, WPARAM, LPARAM);                           //View
LRESULT OnSize(HWND, UINT, WPARAM, LPARAM);                            //View

LRESULT OnActivate(HWND, UINT, WPARAM, LPARAM);                      //Prog_Interact
LRESULT OnCommand(HWND, UINT, WPARAM, LPARAM);                       //Prog_Interact
LRESULT OnGetMinMaxInfo(HWND, UINT, WPARAM, LPARAM);                 //Prog_Interact
LRESULT OnMove(HWND, UINT, WPARAM, LPARAM);                          //Prog_Interact
LRESULT OnTimer(HWND, UINT, WPARAM, LPARAM);                         //Prog_Interact
LRESULT OnDestroy(HWND, UINT, WPARAM, LPARAM);                       //Prog_Interact
LRESULT OnClose(HWND, UINT, WPARAM, LPARAM);                         //Prog_Interact

LRESULT OnKeyDown(HWND, UINT, WPARAM, LPARAM);                       //Interact
LRESULT OnKeyUp(HWND, UINT, WPARAM, LPARAM);                         //Interact


//��Ϣ��Ӧ����ͳһ��װ
#define dim(x)   (sizeof(x) / sizeof(x[0]))                    //(��)���ڷ���Ԫ�ظ���
typedef LRESULT (*FXN)( HWND, UINT, WPARAM, LPARAM);          //ͳһ����ָ��(��LRESULT OnCreate(HWND, UINT, WPARAM, LPARAM)�ṹ�ĺ���)

//����һ��ӳ���ṹ
struct tagMESSAGEMAP{
	UINT Code;	   //��Ϣ()
	FXN Fxn;	   //��Ӧ����
};

//ӳ�������
extern tagMESSAGEMAP MessageMaps [];
//��Ϣ������Ӧ����֮���ӳ���,�ṹ����(!������������������)
/*{WM_CREATE, 			     OnCreate, 
 WM_PAINT,			         OnPaint, }*/