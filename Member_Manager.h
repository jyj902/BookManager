#pragma once


// Member_Manager 대화 상자

class Member_Manager : public CDialogEx
{
	DECLARE_DYNAMIC(Member_Manager)

public:
	Member_Manager(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Member_Manager();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit Member_ID_Edit;
	CEdit Member_PassWord_Edit;
	CEdit Member_Name_Edit;
	CEdit Member_Sex_Edit;
	CEdit Member_Age_Edit;
	CEdit Member_Address_Edit;
	CEdit Member_Number_Edit;
	CButton Member_Add_Button;
	CButton Member_Delete_Button;
	CButton Member_Search_Button;
	CEdit Member_Search_Edit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	CListCtrl Member_Search_List;
};
