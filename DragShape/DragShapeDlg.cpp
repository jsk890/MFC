
// DragShapeDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "DragShape.h"
#include "DragShapeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDragShapeDlg 대화 상자



CDragShapeDlg::CDragShapeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DRAGSHAPE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_rect.SetRect(10, 10, 100, 100);
}

void CDragShapeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CDragShapeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


// CDragShapeDlg 메시지 처리기

BOOL CDragShapeDlg::OnInitDialog()
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

void CDragShapeDlg::OnPaint()
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
		dc.Rectangle(m_rect);



		//CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CDragShapeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 프로젝트 -> 클래스 마법사 -> 메세지탭에서
// mouse down, mouse up, mouse move와 관련된 함수 추가

//마우스를 클릭했을 때
void CDragShapeDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	//현재 사각형 영역을 마우스가 제대로 클릭했는지 확인
	/*
	if (point.x >= m_rect.left && point.x >= m_rect.top && 
		point.x <= m_rect.right && point.x <= m_rect.bottom)
	*/

	//point가 m_rect의 영역안에 있는지 반환
	if (m_rect.PtInRect(point))
	{
		m_is_clicked = 1;
		m_prev_pos = point;

		//마우스가 클라이언트 영역을 벗어나더라도 계속 마우스 메세지를 받음
		SetCapture();
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}

//마우스를 떼었을 때
void CDragShapeDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_is_clicked == 1) {
		m_is_clicked = 0;
		//마우스를 떼었을 때 마우스 메세지를 받지 않음
		ReleaseCapture();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}

//마우스를 드래그 할 때
void CDragShapeDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	if (m_is_clicked == 1) {
		CPoint move_pos = point - m_prev_pos;
		/*
		m_rect.left += move_pos.x;
		m_rect.top += move_pos.y;
		m_rect.right += move_pos.x;
		m_rect.bottom += move_pos.y;
		*/
		m_rect += move_pos;

		//다음 번 작업을 위해서 마우스를 뗀 위치를 저장
		m_prev_pos = point;

		//사각형이 OnPaint에 있으므로 Invalidate를 호출하면
		//WM_PAINT메세지가 발생하면서 OnPaint가 다시 호출되어 그리게 됨
		Invalidate();
	}
	CDialogEx::OnMouseMove(nFlags, point);
}
