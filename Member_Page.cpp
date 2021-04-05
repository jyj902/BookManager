// Member_Page.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "Member_Page.h"
#include "afxdialogex.h"


extern int Member_Num;
extern Data_Base Bk;
// Member_Page 대화 상자

IMPLEMENT_DYNAMIC(Member_Page, CDialogEx)

Member_Page::Member_Page(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

Member_Page::~Member_Page()
{
}

void Member_Page::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, Member_Rental_List);
	DDX_Control(pDX, IDC_BUTTON1, Member_BookReturn_Button);
	DDX_Control(pDX, IDC_BUTTON2, Member_BookSearch_Button);
	DDX_Control(pDX, IDC_BUTTON3, Member_BookRental_Button);
	DDX_Control(pDX, IDC_EDIT1, Member_BookSearch_Edit);
	DDX_Control(pDX, IDC_BUTTON4, Member_BookRental_ing_Button);
	Member_Rental_List.InsertColumn(0, _T("바코드 넘버"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
	Member_Rental_List.InsertColumn(1, _T("책 이름"), LVCFMT_LEFT, 100);
	Member_Rental_List.InsertColumn(2, _T("저자"), LVCFMT_LEFT, 100);
	Member_Rental_List.InsertColumn(3, _T("출판사"), LVCFMT_LEFT, 100);
	Member_Rental_List.InsertColumn(4, _T("분류"), LVCFMT_LEFT, 100);
	Member_Rental_List.InsertColumn(5, _T("대여 가능 여부"), LVCFMT_LEFT, 100);
}


BEGIN_MESSAGE_MAP(Member_Page, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Member_Page::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Member_Page::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Member_Page::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Member_Page::OnBnClickedButton4)
END_MESSAGE_MAP()


// Member_Page 메시지 처리기


void Member_Page::OnBnClickedButton1() //반납
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	string text_string, Rental_Num, Stock, str;
	CString text;
	int text_int, Rental_Num_int, Stock_int;
	string str1, str2, str3;

	str1 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(0);
	str2 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(1);
	str3 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(2);

	pos = Member_Rental_List.GetFirstSelectedItemPosition();
	int index = Member_Rental_List.GetNextSelectedItem(pos);
	text = Member_Rental_List.GetItemText(index, 0);
	text_string = CT2CA(text.operator LPCWSTR());
	text_int = stoi(text_string);

	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if (Bk.BookList[i].Get_Book_Key() == text_int)
		{
			Rental_Num = Bk.BookList[i].Get_Book_Rental_Num();
			Rental_Num_int = stoi(Rental_Num) - 1;
			Rental_Num = to_string(Rental_Num_int);
			Bk.BookList[i].Set_Book_Rental_Num(Rental_Num);

			Stock = Bk.BookList[i].Get_Book_Stock();
			Stock_int = stoi(Stock) + 1;
			Stock = to_string(Stock_int);
			Bk.BookList[i].Set_Book_Stock(Stock);
			str = to_string(text_int);
			if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(0) == str) Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 0);
			else if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(1) == str) Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 1);
			else if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(2) == str) Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 2);
		}
	}
	if ( str1== text_string )
	{
		Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 0);
		Member_Rental_List.DeleteItem(index);
		Member_BookReturn_Button.MessageBox(_T("반납 완료"));
	}
	else if (str2 == text_string)
	{
		Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 1);
		Member_Rental_List.DeleteItem(index);
		Member_BookReturn_Button.MessageBox(_T("반납 완료"));
	}
	else if (str3 == text_string)
	{
		Bk.MemberList[Member_Num].Set_Member_Rental_Num("", 2);
		Member_Rental_List.DeleteItem(index);
		Member_BookReturn_Button.MessageBox(_T("반납 완료"));
	}
}


void Member_Page::OnBnClickedButton2() //조회
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	CString code;
	Member_BookSearch_Edit.GetWindowTextW(str);
	Member_Rental_List.DeleteAllItems();
	string Search = CT2CA(str.operator LPCWSTR());

	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if ((Search == Bk.BookList[i].Get_Book_Name())|| (Bk.BookList[i].Get_Book_Name().find(Search) != string::npos))
		{
			code.Format(_T("%d"), Bk.BookList[i].Get_Book_Key());
			Member_Rental_List.InsertItem(0, code); // 표의 첫번째 인자
			Member_Rental_List.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			Member_Rental_List.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			Member_Rental_List.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			Member_Rental_List.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
			Member_Rental_List.SetItemText(0, 5, CA2CT(Bk.BookList[i].Get_Book_Rental().c_str()));
		}
	}
}


void Member_Page::OnBnClickedButton3()  //대여
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	CString text;
	int Cheak = 0, text_int, Rental_Num_int, Stock_int;
	string Rental_Num, Stock, text_string;

	pos = Member_Rental_List.GetFirstSelectedItemPosition();
	int index = Member_Rental_List.GetNextSelectedItem(pos);
	text = Member_Rental_List.GetItemText(index, 0);
	text_string = CT2CA(text.operator LPCWSTR());
	text_int = stoi(text_string);

	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if (Bk.BookList[i].Get_Book_Key() == text_int)
		{
			if (Bk.BookList[i].Get_Book_Rental() == "대여 불가")
			{
				Member_BookRental_Button.MessageBox(_T("제고 부족"));
				Cheak = 0;
				break;
			}
			Cheak = 1;
			Rental_Num = Bk.BookList[i].Get_Book_Rental_Num();
			Rental_Num_int = stoi(Rental_Num)+1;
			Rental_Num = to_string(Rental_Num_int);
			Bk.BookList[i].Set_Book_Rental_Num(Rental_Num);

			Stock = Bk.BookList[i].Get_Book_Stock();
			Stock_int = stoi(Stock) - 1;
			Stock = to_string(Stock_int);
			Bk.BookList[i].Set_Book_Stock(Stock);
			text_string = to_string(text_int);
			for (int k =0; k<3; k++)
			{
				if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(k) == text_string)
				{
					Member_BookRental_Button.MessageBox(_T("이미 대여중인 책입니다"));
					Cheak = 0;
					break;
				}
			}
			if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(0) == "") Bk.MemberList[Member_Num].Set_Member_Rental_Num(text_string, 0);
			else if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(1) == "") Bk.MemberList[Member_Num].Set_Member_Rental_Num(text_string, 1);
			else if (Bk.MemberList[Member_Num].Get_Member_Rental_Num(2) == "") Bk.MemberList[Member_Num].Set_Member_Rental_Num(text_string, 2);
			else
			{
				Member_BookRental_Button.MessageBox(_T("최대 대여 개수 초과"));
				Cheak = 0;
			}
		}
	}

	if(Cheak == 1) Member_BookRental_Button.MessageBox(_T("대여 완료"));
}


void Member_Page::OnBnClickedButton4() //대여중인 목록 조회
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	string str1, str2, str3;
	CString str1_CS, str2_CS, str3_CS;
	int num;
	Member_Rental_List.DeleteAllItems();
	str1 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(0);
	str2 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(1);
	str3 = Bk.MemberList[Member_Num].Get_Member_Rental_Num(2);
	int str1_int = atoi(str1.c_str());
	int str2_int = atoi(str2.c_str());
	int str3_int = atoi(str3.c_str());
	str1_CS = str1.c_str();
	str2_CS = str2.c_str();
	str3_CS = str3.c_str();
	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if (str1_int == Bk.BookList[i].Get_Book_Key())
		{
			Member_Rental_List.InsertItem(0, str1_CS);
			Member_Rental_List.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			Member_Rental_List.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			Member_Rental_List.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			Member_Rental_List.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
		}
		else if (str2_int == Bk.BookList[i].Get_Book_Key())
		{
			Member_Rental_List.InsertItem(0, str2_CS);
			Member_Rental_List.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			Member_Rental_List.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			Member_Rental_List.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			Member_Rental_List.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
		}
		else if (str3_int == Bk.BookList[i].Get_Book_Key())
		{
			Member_Rental_List.InsertItem(0, str3_CS);
			Member_Rental_List.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			Member_Rental_List.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			Member_Rental_List.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			Member_Rental_List.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
		}
	}
}
