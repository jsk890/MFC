
// MFCWindowDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCWindow.h"
#include "MFCWindowDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCWindowDlg 대화 상자

CMFCWindowDlg::CMFCWindowDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCWINDOW_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCWindowDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCWindowDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCWindowDlg 메시지 처리기

BOOL CMFCWindowDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCWindowDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCWindowDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


LRESULT CMFCWindowDlg::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (message == WM_LBUTTONDOWN) {

		//Win32
		HDC h_dc = ::GetDC(m_hWnd);
		Rectangle(h_dc, 10, 10, 100, 100);
		::ReleaseDC(m_hWnd, h_dc);

		//MFC
		CDC* p_dc = GetDC();
		p_dc->Rectangle(10, 10, 100, 100);
		ReleaseDC(p_dc);

		//완화
		//이 대화상자에 그림을 그릴 수 있는 dc를 구성해서 클래스가 가지게 됨
		CClientDC dc(this);
		dc.Rectangle(10, 10, 100, 100);

		//컨트롤 키를 눌렸을 경우 사각형안에 내적하는 원 그리기
		if (wParam & MK_CONTROL)
			dc.Ellipse(10, 10, 100, 100);
	}


	return CDialogEx::WindowProc(message, wParam, lParam);
}
