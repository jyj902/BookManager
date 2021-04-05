
// BookManager07Dlg.h: 헤더 파일
//

#pragma once


// CBookManager07Dlg 대화 상자
class CBookManager07Dlg : public CDialogEx
{
// 생성입니다.
public:
	CBookManager07Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	virtual ~CBookManager07Dlg();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOKMANAGER07_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CButton loginS;
	afx_msg void OnBnClickedButton1();
	CButton font;
	CButton Acc;
	CButton loginC;
	CListCtrl BookList;
	CButton Button_Search;
	CEdit Book_Search_Edit;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton6();
};
