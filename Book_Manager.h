#pragma once


// Book_Manager 대화 상자

class Book_Manager : public CDialogEx
{
	DECLARE_DYNAMIC(Book_Manager)

public:
	Book_Manager(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Book_Manager();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit Book_Manager_Key_Edit;
	CEdit Book_Manager_Name_Edit;
	CEdit Book_Manager_Writer_Edit;
	CEdit Book_Manager_Classification_Edit;
	CEdit Book_Manager_Publisher_Edit;
	CEdit Book_Manager_Stock_Edit;
	CButton Book_Manager_Add_Button;
	CButton Book_Manager_Delete_Button;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	CListCtrl Book_Manager_List;
	CEdit Book_Add_Search_Edit;
	CButton Book_Add_Search_Button;
	afx_msg void OnBnClickedButton2();
};
