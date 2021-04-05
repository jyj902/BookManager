#pragma once


// Manager_Page 대화 상자

class Manager_Page : public CDialogEx
{
	DECLARE_DYNAMIC(Manager_Page)

public:
	Manager_Page(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Manager_Page();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Manager_Combox;
	CEdit Manager_Search_Edit;
	afx_msg void OnBnClickedButton1();
	CListCtrl Manager_CList;
	CButton Book_Manager_Button;
	afx_msg void OnBnClickedButton2();
	CButton Member_Manager_Button;
	afx_msg void OnBnClickedButton3();
};
