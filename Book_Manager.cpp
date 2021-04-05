// Book_Manager.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "Book_Manager.h"
#include "afxdialogex.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "Member.h"
#include "Data_Base.h"
#include <string>


// Book_Manager 대화 상자
extern Data_Base Bk;
IMPLEMENT_DYNAMIC(Book_Manager, CDialogEx)

Book_Manager::Book_Manager(CWnd* pParent /*=nullptr*/)


	: CDialogEx(IDD_DIALOG3, pParent)
{
	
}

Book_Manager::~Book_Manager()
{
	
}

void Book_Manager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Book_Manager_Key_Edit);
	DDX_Control(pDX, IDC_EDIT2, Book_Manager_Name_Edit);
	DDX_Control(pDX, IDC_EDIT3, Book_Manager_Writer_Edit);
	DDX_Control(pDX, IDC_EDIT4, Book_Manager_Classification_Edit);
	DDX_Control(pDX, IDC_EDIT5, Book_Manager_Publisher_Edit);
	DDX_Control(pDX, IDC_EDIT6, Book_Manager_Stock_Edit);
	DDX_Control(pDX, IDC_BUTTON1, Book_Manager_Add_Button);
	DDX_Control(pDX, IDC_BUTTON4, Book_Manager_Delete_Button);
	DDX_Control(pDX, IDC_LIST1, Book_Manager_List);

	Book_Manager_List.InsertColumn(0, _T("바코드 넘버"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
	Book_Manager_List.InsertColumn(1, _T("책 이름"), LVCFMT_LEFT, 100);
	Book_Manager_List.InsertColumn(2, _T("저자"), LVCFMT_LEFT, 100);
	Book_Manager_List.InsertColumn(3, _T("출판사"), LVCFMT_LEFT, 100);
	Book_Manager_List.InsertColumn(4, _T("분류"), LVCFMT_LEFT, 100);
	Book_Manager_List.InsertColumn(5, _T("보유 수량"), LVCFMT_LEFT, 100);
	DDX_Control(pDX, IDC_EDIT7, Book_Add_Search_Edit);
	DDX_Control(pDX, IDC_BUTTON2, Book_Add_Search_Button);
}


BEGIN_MESSAGE_MAP(Book_Manager, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Book_Manager::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Book_Manager::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &Book_Manager::OnBnClickedButton2)
END_MESSAGE_MAP()


// Book_Manager 메시지 처리기


void Book_Manager::OnBnClickedButton1() //추가 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString Key, Name, Writer, Classification, Publisher, Stock;
	string temp, temp2, temp3, temp4;
	Book* str = new Book;
	int Cheak = 0;
	Book_Manager_Key_Edit.GetWindowTextW(Key);
	Book_Manager_Name_Edit.GetWindowTextW(Name);
	temp2 = CT2CA(Key.operator LPCWSTR());
	temp = CT2CA(Name.operator LPCWSTR());

	for (int i = 0; i < Bk.BookList.size(); i++)
	{
		if (Bk.BookList[i].Get_Book_Key() == atoi(temp2.c_str()))
		{
			Book_Manager_Add_Button.MessageBox(_T("이미 있는 바코드 입니다."));
			Cheak = 1;
			break;
		}
	}
	if (Cheak == 0)
	{
		str->Set_Book_ID(atoi(temp2.c_str()), temp);

		Book_Manager_Writer_Edit.GetWindowTextW(Writer);
		Book_Manager_Classification_Edit.GetWindowTextW(Publisher);
		temp2 = CT2CA(Writer.operator LPCWSTR());
		temp = CT2CA(Publisher.operator LPCWSTR());
		str->Set_Book_Writer(temp2);
		str->Set_Book_Publisher(temp);

		Book_Manager_Publisher_Edit.GetWindowTextW(Classification);
		Book_Manager_Stock_Edit.GetWindowTextW(Stock);
		temp2 = CT2CA(Classification.operator LPCWSTR());
		temp = CT2CA(Stock.operator LPCWSTR());
		str->Set_Book_Classification(temp2);
		str->Set_Book_Stock(temp);
		str->Set_Book_Rental("대여 가능");
		Book_Manager_List.InsertItem(0, Key);
		Book_Manager_List.SetItemText(0, 1, Name);
		Book_Manager_List.SetItemText(0, 2, Writer);
		Book_Manager_List.SetItemText(0, 3, Classification);
		Book_Manager_List.SetItemText(0, 4, Publisher);
		Book_Manager_List.SetItemText(0, 5, Stock);
		Bk.BookList.push_back(*str);
		Book_Manager_Add_Button.MessageBox(_T("등록 완료"));
	}
}


void Book_Manager::OnBnClickedButton4() // 삭제 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	string line, key;
	CString text;
	int Cheak = 0, text_int;
	ifstream Del_Data("Book_Data.csv");
	pos = Book_Manager_List.GetFirstSelectedItemPosition();
	int index = Book_Manager_List.GetNextSelectedItem(pos);
	text = Book_Manager_List.GetItemText(index,0);
	text_int = _ttoi(text);
	

	for(int i=0; Bk.BookList.size(); i++)
	{
		if (Bk.BookList[i].Get_Book_Key() == text_int)
		{
			Bk.BookList.erase(Bk.BookList.begin()+i);
			Book_Manager_List.DeleteItem(index);
			Book_Manager_Delete_Button.MessageBox(_T("삭제 완료"));
			Cheak = 1;
			break;
		}
	}
	if(Cheak == 0) Book_Manager_Add_Button.MessageBox(_T("일치하는 바코드가 없습니다."));
}

void Book_Manager::OnBnClickedButton2() //조회버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str, code;
	string temp;
	Book_Add_Search_Edit.GetWindowTextW(str);
	temp = CT2CA(str.operator LPCWSTR());
	Book_Manager_List.DeleteAllItems();
	for (int i=0; i < Bk.BookList.size(); i++)
	{
		if ((temp == Bk.BookList[i].Get_Book_Name())|| (Bk.BookList[i].Get_Book_Name().find(temp) != string::npos))
		{
			code.Format(_T("%d"), Bk.BookList[i].Get_Book_Key());
			Book_Manager_List.InsertItem(0, code); // 표의 첫번째 인자
			Book_Manager_List.SetItemText(0, 1, CA2CT(Bk.BookList[i].Get_Book_Name().c_str())); // 첫번째 인자의 하위목록
			Book_Manager_List.SetItemText(0, 2, CA2CT(Bk.BookList[i].Get_Book_Writer().c_str()));
			Book_Manager_List.SetItemText(0, 3, CA2CT(Bk.BookList[i].Get_Book_Publisher().c_str()));
			Book_Manager_List.SetItemText(0, 4, CA2CT(Bk.BookList[i].Get_Book_Classification().c_str()));
			Book_Manager_List.SetItemText(0, 5, CA2CT(Bk.BookList[i].Get_Book_Stock().c_str()));
		}
	}
}