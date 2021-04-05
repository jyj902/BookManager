#pragma once


// m_log 대화 상자

class m_log : public CDialogEx
{
	DECLARE_DYNAMIC(m_log)

public:
	m_log(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~m_log();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CButton Manager_Login;
	CEdit Manager_PassWord_Edit;
	afx_msg void OnBnClickedButton1();
};
