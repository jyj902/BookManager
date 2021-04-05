#pragma once


// Member_log 대화 상자

class Member_log : public CDialogEx
{
	DECLARE_DYNAMIC(Member_log)

public:
	Member_log(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Member_log();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit Member_Log_ID_Edit;
	CEdit Member_Log_PassWord_Edit;
	CButton Member_Log_Button;
	afx_msg void OnBnClickedButton1();
};
