
// AddDialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "AddDialog.h"
#include "AddDialogDlg.h"
#include "afxdialogex.h"
#include "NewDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAddDialogDlg 대화 상자



CAddDialogDlg::CAddDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ADDDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAddDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAddDialogDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_DLG_BTN, &CAddDialogDlg::OnBnClickedShowDlgBtn)
END_MESSAGE_MAP()


// CAddDialogDlg 메시지 처리기

BOOL CAddDialogDlg::OnInitDialog()
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

void CAddDialogDlg::OnPaint()
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
HCURSOR CAddDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CAddDialogDlg::OnBnClickedShowDlgBtn()
{
	int num = GetDlgItemInt(IDC_PARENT_NUM_EDIT);

	NewDlg ins_dlg;
	ins_dlg.SetNum(num);

	//정형 대화상자 실행, 대화상자가 종료되어야 DoModal을 빠져 나옴
	//idok 확인 버튼을 눌러서 닫은 경우
	int result = ins_dlg.DoModal();

	if (IDOK == result) {
		num = ins_dlg.GetNum();
		SetDlgItemInt(IDC_PARENT_NUM_EDIT, num);
	}
	else if (20 == result) {
		SetDlgItemInt(IDC_PARENT_NUM_EDIT, 0);
	}
}
