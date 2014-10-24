#pragma once
//included by LabMF.h

//WM_消息响应函数I声明
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


//消息响应函数统一封装
#define dim(x)   (sizeof(x) / sizeof(x[0]))                    //(宏)用于返回元素个数
typedef LRESULT (*FXN)( HWND, UINT, WPARAM, LPARAM);          //统一定义指针(如LRESULT OnCreate(HWND, UINT, WPARAM, LPARAM)结构的函数)

//定义一个映射表结构
struct tagMESSAGEMAP{
	UINT Code;	   //消息()
	FXN Fxn;	   //响应函数
};

//映射表声明
extern tagMESSAGEMAP MessageMaps [];
//消息到其相应函数之间的映射表,结构如下(!别忘记声明函数本身)
/*{WM_CREATE, 			     OnCreate, 
 WM_PAINT,			         OnPaint, }*/