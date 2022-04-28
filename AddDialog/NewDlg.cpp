// NewDlg.cpp: 구현 파일
//

#include "pch.h"
#include "AddDialog.h"
#include "NewDlg.h"
#include "afxdialogex.h"


// NewDlg 대화 상자

IMPLEMENT_DYNAMIC(NewDlg, CDialogEx)

NewDlg::NewDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NEW_DLG, pParent)
{

}

NewDlg::~NewDlg()
{
}

void NewDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(NewDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &NewDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &NewDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_EXIT_BTN, &NewDlg::OnBnClickedExitBtn)
END_MESSAGE_MAP()


// NewDlg 메시지 처리기

// 대화상자 및 컨트롤이 만들어 진 이후
// 초기 작업 세팅
BOOL NewDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetDlgItemInt(IDC_CHILD_NUM_EDIT, m_num);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void NewDlg::OnBnClickedOk()
{
	m_num = GetDlgItemInt(IDC_CHILD_NUM_EDIT);

	CDialogEx::OnOK();
}


void NewDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void NewDlg::OnBnClickedExitBtn()
{
	//대화상자를 직접적으로 닫게 함, 두모달 함수의 최종적 반환 값
	EndDialog(20);
}
