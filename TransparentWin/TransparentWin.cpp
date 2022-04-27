
// TransparentWin.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "TransparentWin.h"
#include "TransparentWinDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTransparentWinApp

BEGIN_MESSAGE_MAP(CTransparentWinApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTransparentWinApp 생성

CTransparentWinApp::CTransparentWinApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CTransparentWinApp 개체입니다.

CTransparentWinApp theApp;


// CTransparentWinApp 초기화

BOOL CTransparentWinApp::InitInstance()
{
	CWinApp::InitInstance();

	CTransparentWinDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;
}

