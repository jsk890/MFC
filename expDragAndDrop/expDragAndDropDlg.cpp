
// expDragAndDropDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "expDragAndDrop.h"
#include "expDragAndDropDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexpDragAndDropDlg 대화 상자



CexpDragAndDropDlg::CexpDragAndDropDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EXPDRAGANDDROP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CexpDragAndDropDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DROP_LIST, m_drop_list);
}

BEGIN_MESSAGE_MAP(CexpDragAndDropDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CexpDragAndDropDlg 메시지 처리기

BOOL CexpDragAndDropDlg::OnInitDialog()
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

void CexpDragAndDropDlg::OnPaint()
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
HCURSOR CexpDragAndDropDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 드롭된 파일의 정보를 얻음
void CexpDragAndDropDlg::OnDropFiles(HDROP hDropInfo)
{
	// 리스트 박스의 내용을 모두 지움
	m_drop_list.ResetContent();
	// 현재 윈도우도 드래그된 파일이 드롭 되었는지 확인하여 갯수를 씀
	// 핸들, 인덱스(몇번째 파일을 사용하겠느냐 0xFFFFFFFF :-1, 파일의 경로 주소, 주소의 크기)
	// 아래 형태로 쓰면, 윈도우로 드래그앤 드롭 된 파일의 갯수가 반환이 됨
	int count = DragQueryFile(hDropInfo, 0xFFFFFFFF, NULL, 0);

	// MAX_PATH : 경로로 사용되는 문자열의 최대값 상수, 파일의 경로 추가
	wchar_t temp_path[MAX_PATH];
	for (int i = 0; i < count; i++)
	{
		DragQueryFile(hDropInfo, i, temp_path, MAX_PATH);
		// 갯수를 확인 했으므로 하나씩 불러와 추가
		m_drop_list.InsertString(i, temp_path);
	}


	CDialogEx::OnDropFiles(hDropInfo);
}
