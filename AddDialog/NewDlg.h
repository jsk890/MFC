#pragma once


// NewDlg 대화 상자

class NewDlg : public CDialogEx
{
private:
	int m_num;

	DECLARE_DYNAMIC(NewDlg)

public:
	NewDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~NewDlg();

	void SetNum(int a_num) {
		m_num = a_num;
	}

	int GetNum() {
		return m_num;
	}

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedExitBtn();
};
