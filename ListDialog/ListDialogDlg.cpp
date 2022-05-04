
// ListDialogDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "ListDialog.h"
#include "ListDialogDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CListDialogDlg 대화 상자



CListDialogDlg::CListDialogDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTDIALOG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListDialogDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CListDialogDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SHOW_BTN, &CListDialogDlg::OnBnClickedShowBtn)
END_MESSAGE_MAP()


// CListDialogDlg 메시지 처리기

BOOL CListDialogDlg::OnInitDialog()
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

void CListDialogDlg::OnPaint()
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
HCURSOR CListDialogDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListDialogDlg::OnBnClickedShowBtn()
{
	/*
	int num[11], i;

	for (i = 0; i < 5; i++) {
		num[i] = GetDlgItemInt(IDC_EDIT2 + i);
	}

	CString str, total_str;
	CComboBox *p_combo;
	int index=0;
	for (i = 0 ; i < 6; i++) {
		p_combo = (CComboBox *)GetDlgItem(IDC_COMBO2 + i);
		//콤보박스의 위치를 얻어옴
		index = p_combo -> GetCurSel();
		if (index != CB_ERR) {
			//콤보박스의 문자열을 가져옴
			p_combo->GetLBText(index, str);
			num[5 + i] = _wtoi(str);
		}
		else {
			num[5 + i] = 0;
		}
	}

	*/

	int num[11], i;
	CString str, total_str;

	for (i = 0; i < 11; i++) {
		num[i] = GetDlgItemInt(IDC_EDIT2 + i);
	}

	for (i = 0; i < 11; i++) {
		str.Format(L"%d, ", num[i]);
		total_str += str;
	}
	
	SetDlgItemText(IDC_NUM_EDIT, total_str);

}
