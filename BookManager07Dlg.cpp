
// BookManager07Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "BookManager07.h"
#include "BookManager07Dlg.h"
#include "afxdialogex.h"
#include "m_log.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include "Data_Base.h"
#include "Manager_Page.h"
#include "Member.h"
#include <vector>
#include "Member_log.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

Data_Base Bk;

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};
CBookManager07Dlg::~CBookManager07Dlg()
{
	ofstream _BOOK("Book_Data.csv");
	ofstream _MEMBER("Member_Data.csv");
	if (_BOOK.is_open())
	{
		for (int i = 0; i < Bk.BookList.size(); i++)
		{
			_BOOK << Bk.BookList[i].Get_Book_Key()<<',';
			_BOOK << Bk.BookList[i].Get_Book_Name() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Writer() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Publisher() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Classification() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Rental() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Stock() << ',';
			_BOOK << Bk.BookList[i].Get_Book_Rental_Num() << endl;
		}
	}
	_BOOK.close();
	for (int i = 0; i < Bk.MemberList.size(); i++)
	{
		if (_MEMBER.is_open())
		{
			_MEMBER << Bk.MemberList[i].Get_Member_Key() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_ID() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_PassWord() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Sex() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Age() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Address() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Number() << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Rental_Num(0) << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Rental_Num(1) << ',';
			_MEMBER << Bk.MemberList[i].Get_Member_Rental_Num(2) << endl;
		}
	}
	_MEMBER.close();
}
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBookManager07Dlg 대화 상자



CBookManager07Dlg::CBookManager07Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BOOKMANAGER07_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookManager07Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, loginS);
	DDX_Control(pDX, IDCANCEL, font);

	DDX_Control(pDX, IDC_BUTTON6, loginC);
	DDX_Control(pDX, IDC_LIST2, BookList);
	DDX_Control(pDX, IDC_BUTTON2, Button_Search);
	DDX_Control(pDX, IDC_EDIT1, Book_Search_Edit);
}

BEGIN_MESSAGE_MAP(CBookManager07Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CBookManager07Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CBookManager07Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON6, &CBookManager07Dlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CBookManager07Dlg 메시지 처리기

BOOL CBookManager07Dlg::OnInitDialog()
{
	Bk.Load_Book_Data();
	Bk.Load_Member_Data();
	CDialogEx::OnInitDialog();
	CFont mFont3;
	//폰트 생성
	mFont3.CreateFontW(
		100,                            // 글자높이
		100,                            // 글자너비
		0,                            // 출력각도
		0,                            // 기준 선에서의각도
		FW_HEAVY,                    // 글자굵기
		FALSE,                        // Italic 적용여부
		FALSE,                        // 밑줄적용여부
		FALSE,                        // 취소선적용여부
		DEFAULT_CHARSET,            // 문자셋종류
		OUT_DEFAULT_PRECIS,            // 출력정밀도
		CLIP_CHARACTER_PRECIS,        // 클리핑정밀도
		PROOF_QUALITY,                // 출력문자품질
		DEFAULT_PITCH,                // 글꼴Pitch
		_T("돋움체")                // 글꼴
	);
	
	//컨트롤의 폰트를 변경한다.
	GetDlgItem(IDC_STATIC)->SetFont(&mFont3);
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	ShowWindow(SW_SHOW);

	ShowWindow(SW_SHOW);

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	BookList.InsertColumn(0, _T("바코드 넘버"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
	BookList.InsertColumn(1, _T("책 이름"), LVCFMT_LEFT, 100);
	BookList.InsertColumn(2, _T("저자"), LVCFMT_LEFT, 100);
	BookList.InsertColumn(3, _T("출판사"), LVCFMT_LEFT, 100);
	BookList.InsertColumn(4, _T("분류"), LVCFMT_LEFT, 100);
	BookList.InsertColumn(5, _T("대여가능여부"), LVCFMT_LEFT, 100);
	BookList.InsertColumn(6, _T("보유 수량"), LVCFMT_LEFT, 100);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CBookManager07Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CBookManager07Dlg::OnPaint()
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
HCURSOR CBookManager07Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CBookManager07Dlg::OnBnClickedButton1()
{

	m_log dlg;
	dlg.DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

}

void CBookManager07Dlg::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	CString code;
	Book_Search_Edit.GetWindowTextW(str);
	BookList.DeleteAllItems();
	string Search=CT2CA(str.operator LPCWSTR());
	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if (Search == Bk.BookList[i].Get_Book_Name()||(Bk.BookList[i].Get_Book_Name().find(Search) != string::npos))
		{
			code.Format(_T("%d"), Bk.BookList[i].Get_Book_Key());
			BookList.InsertItem(0, code); // 표의 첫번째 인자
			BookList.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			BookList.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			BookList.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			BookList.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
			BookList.SetItemText(0, 5, CA2CT(Bk.BookList[i].Get_Book_Rental().c_str()));
			BookList.SetItemText(0, 6, CA2CT(Bk.BookList[i].Get_Book_Stock().c_str()));
		}
	}
}


void CBookManager07Dlg::OnBnClickedButton6()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Member_log dlg;
	dlg.DoModal();
}
