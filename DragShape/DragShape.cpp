﻿
// DragShape.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "DragShape.h"
#include "DragShapeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDragShapeApp

BEGIN_MESSAGE_MAP(CDragShapeApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CDragShapeApp 생성

CDragShapeApp::CDragShapeApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CDragShapeApp 개체입니다.

CDragShapeApp theApp;


// CDragShapeApp 초기화

BOOL CDragShapeApp::InitInstance()
{
	CWinApp::InitInstance();

	CDragShapeDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

