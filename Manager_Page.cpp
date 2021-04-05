// Manager_Page.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "Manager_Page.h"
#include "afxdialogex.h"
#include "Book.h"
#include "Member.h"
#include "Book_Manager.h"
#include "Member_Manager.h"
#include "Data_Base.h"
#include <vector>
extern Data_Base Bk;
using namespace std;
// Manager_Page 대화 상자

IMPLEMENT_DYNAMIC(Manager_Page, CDialogEx)

Manager_Page::Manager_Page(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Manager_Page::~Manager_Page()
{
}

void Manager_Page::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO3, Manager_Combox);
	DDX_Control(pDX, IDC_EDIT1, Manager_Search_Edit);
	Manager_Combox.AddString(_T("도서 검색"));
	Manager_Combox.AddString(_T("회원 검색"));
	DDX_Control(pDX, IDC_LIST7, Manager_CList);
	DDX_Control(pDX, IDC_BUTTON2, Book_Manager_Button);
	DDX_Control(pDX, IDC_BUTTON3, Member_Manager_Button);
}


BEGIN_MESSAGE_MAP(Manager_Page, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Manager_Page::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Manager_Page::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Manager_Page::OnBnClickedButton3)
END_MESSAGE_MAP()


// Manager_Page 메시지 처리기


void Manager_Page::OnBnClickedButton1()//도서, 회원 조회
{
	Manager_CList.DeleteAllItems();
	CString str;
	CString code;
	int index;
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Manager_Search_Edit.GetWindowTextW(str);
	index = Manager_Combox.GetCurSel();
	while (Manager_CList.GetHeaderCtrl()->GetItemCount() > 0) Manager_CList.DeleteColumn(0);
	if (index == 0)
	{
		Manager_CList.InsertColumn(0, _T("바코드 넘버"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
		Manager_CList.InsertColumn(1, _T("책 이름"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(2, _T("저자"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(3, _T("출판사"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(4, _T("분류"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(5, _T("대여중"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(6, _T("보유 수량"), LVCFMT_LEFT, 100);
		string Search = CT2CA(str.operator LPCWSTR());
		for (int i = 0; i < Bk.BookList.size(); i++)
		{
			if ((Search == Bk.BookList[i].Get_Book_Name())|| (Bk.BookList[i].Get_Book_Name().find(Search) != string::npos))
			{
				code.Format(_T("%d"), Bk.BookList[i].Get_Book_Key());
				Manager_CList.InsertItem(0, code); // 표의 첫번째 인자
				Manager_CList.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
				Manager_CList.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
				Manager_CList.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
				Manager_CList.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
				Manager_CList.SetItemText(0, 5, CA2CT(Bk.BookList[i].Get_Book_Rental_Num().c_str()));
				Manager_CList.SetItemText(0, 6, CA2CT( Bk.BookList[i].Get_Book_Stock().c_str()));
			}
		}
	}
	if (index == 1)
	{
		Manager_CList.InsertColumn(0, _T("회원 ID"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
		Manager_CList.InsertColumn(1, _T("회원 이름"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(2, _T("나이"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(3, _T("성별"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(4, _T("주소"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(5, _T("번호"), LVCFMT_LEFT, 100);
		Manager_CList.InsertColumn(6, _T("대여중"), LVCFMT_LEFT, 100);
		string Search = CT2CA(str.operator LPCWSTR());
		for (int i = 0; i < Bk.MemberList.size(); i++)
		{
			if ((Search == Bk.MemberList[i].Get_Member_ID())||(Search == Bk.MemberList[i].Get_Member_Key()) || (Bk.MemberList[i].Get_Member_ID().find(Search) != string::npos) || (Bk.MemberList[i].Get_Member_Key().find(Search) != string::npos))
			{
				Manager_CList.InsertItem(0, CA2CT(Bk.MemberList[i].Get_Member_Key().c_str())); // 표의 첫번째 인자
				Manager_CList.SetItemText(0, 1, CA2CT(Bk.MemberList[i].Get_Member_ID().c_str())); // 첫번째 인자의 하위목록
				Manager_CList.SetItemText(0, 2, CA2CT(Bk.MemberList[i].Get_Member_Age().c_str()));
				Manager_CList.SetItemText(0, 3, CA2CT(Bk.MemberList[i].Get_Member_Sex().c_str()));
				Manager_CList.SetItemText(0, 4, CA2CT(Bk.MemberList[i].Get_Member_Address().c_str()));
				Manager_CList.SetItemText(0, 5, CA2CT(Bk.MemberList[i].Get_Member_Number().c_str()));
				string str;
				for (int j = 0; j < 3; j++)
				{
					str += Bk.MemberList[i].Get_Member_Rental_Num(j);
					if (j == 2) break;
					str += ", ";
				}
				Manager_CList.SetItemText(0, 6, CA2CT(str.c_str()));

			}
		}
	}
}

void Manager_Page::OnBnClickedButton2()
{
	Book_Manager dlg;
	dlg.DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void Manager_Page::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Member_Manager dlg;
	dlg.DoModal();
}
