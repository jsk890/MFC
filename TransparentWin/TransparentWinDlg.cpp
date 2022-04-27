
// TransparentWinDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "TransparentWin.h"
#include "TransparentWinDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTransparentWinDlg 대화 상자



CTransparentWinDlg::CTransparentWinDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TRANSPARENTWIN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTransparentWinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTransparentWinDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CTransparentWinDlg 메시지 처리기

BOOL CTransparentWinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	//일부 영역만 투명화, 계층화 (layered) 속성을 true로 설정하여야 함
	// RGB(255, 1, 7)의 색상이 칠해진 부분만 완전 투명하게 처리
	// LWA_COLORKEY : 특정 색상을 투명화 시킴
	//SetLayeredWindowAttributes(RGB(255, 2, 7), 0 , LWA_COLORKEY);

	//윈도우 전체 영역에서 불투명하게 적용, 계층화 (layered) 속성을 true로 설정하여야 함
	//SetLayeredWindowAttributes(0, 50, LWA_ALPHA);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CTransparentWinDlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	if (IsIconic())
	{

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
		dc.FillSolidRect(10, 10, 200, 200, RGB(255, 2, 7));
		//CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CTransparentWinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTransparentWinDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	// 계층화 속성을 True로 설정하였을 경우
	//dc.FillSolidRect(point.x - 20, point.y - 20, 40, 40, RGB(255, 2, 7));


	// 계층화 속성을 False로 설정되어 있지만 OnLButtonDown이 활성화 됐을 때 투명화 적용
	// 현재 윈도우의 layered 속성값을 받아온다
	// :: : API함수를 사용했음을 구분
	int wnd_style = ::GetWindowLong(m_hWnd, GWL_EXSTYLE);
	//현재 기존 속성에서 layered 속성이 없을 경우
	if (!(wnd_style & WS_EX_LAYERED)) {
		//layered속성을 wnd_style의 기존 스타일을 유지하면서 WS_EX_LAYERED의 속성을 지정시킴
		::SetWindowLong(m_hWnd, GWL_EXSTYLE, wnd_style | WS_EX_LAYERED);
		dc.SetBkColor(RGB(200, 200, 200));
		dc.TextOutW(300, 50, _T("Layered 속성 : True "));
	}
	else {
		//WS_EX_LAYERED 속성을 false로 변경
		::SetWindowLong(m_hWnd, GWL_EXSTYLE, wnd_style & 0x00000000);
		dc.FillSolidRect(10, 10, 200, 200, RGB(255, 2, 7));
		dc.SetBkColor(RGB(200, 200, 200));
		dc.TextOutW(300, 50, _T("Layered 속성 : False"));
	}

	SetLayeredWindowAttributes(RGB(255, 2, 7), 0, LWA_COLORKEY);


	CDialogEx::OnLButtonDown(nFlags, point);
}
