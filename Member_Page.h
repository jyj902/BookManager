#pragma once


// Member_Page 대화 상자

class Member_Page : public CDialogEx
{
	DECLARE_DYNAMIC(Member_Page)

public:
	Member_Page(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Member_Page();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl Member_Rental_List;
	CButton Member_BookReturn_Button;
	CButton Member_BookSearch_Button;
	CButton Member_BookRental_Button;
	CEdit Member_BookSearch_Edit;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CButton Member_BookRental_ing_Button;
	afx_msg void OnBnClickedButton4();
};
