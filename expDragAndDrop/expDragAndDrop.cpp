
// expDragAndDrop.cpp: 애플리케이션에 대한 클래스 동작을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "expDragAndDrop.h"
#include "expDragAndDropDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexpDragAndDropApp

BEGIN_MESSAGE_MAP(CexpDragAndDropApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CexpDragAndDropApp 생성

CexpDragAndDropApp::CexpDragAndDropApp()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	// InitInstance에 모든 중요한 초기화 작업을 배치합니다.
}


// 유일한 CexpDragAndDropApp 개체입니다.

CexpDragAndDropApp theApp;


// CexpDragAndDropApp 초기화

BOOL CexpDragAndDropApp::InitInstance()
{
	CWinApp::InitInstance();

	CexpDragAndDropDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();
	
	return FALSE;
}

