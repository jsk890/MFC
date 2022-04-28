
// AddDialog.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "AddDialog.h"
#include "AddDialogDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAddDialogApp

BEGIN_MESSAGE_MAP(CAddDialogApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CAddDialogApp 생성

CAddDialogApp::CAddDialogApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CAddDialogApp 개체입니다.

CAddDialogApp theApp;


// CAddDialogApp 초기화

BOOL CAddDialogApp::InitInstance()
{
	CWinApp::InitInstance();

	CAddDialogDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

