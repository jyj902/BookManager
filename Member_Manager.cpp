// Member_Manager.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "Member_Manager.h"
#include "afxdialogex.h"
#include "Book.h"
#include "Member.h"
#include "Data_Base.h"

extern Data_Base Bk;


// Member_Manager 대화 상자

IMPLEMENT_DYNAMIC(Member_Manager, CDialogEx)

Member_Manager::Member_Manager(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

Member_Manager::~Member_Manager()
{
}

void Member_Manager::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, Member_ID_Edit);
	DDX_Control(pDX, IDC_EDIT2, Member_PassWord_Edit);
	DDX_Control(pDX, IDC_EDIT3, Member_Name_Edit);
	DDX_Control(pDX, IDC_EDIT4, Member_Sex_Edit);
	DDX_Control(pDX, IDC_EDIT5, Member_Age_Edit);
	DDX_Control(pDX, IDC_EDIT6, Member_Address_Edit);
	DDX_Control(pDX, IDC_EDIT8, Member_Number_Edit);
	DDX_Control(pDX, IDC_BUTTON1, Member_Add_Button);
	DDX_Control(pDX, IDC_BUTTON2, Member_Delete_Button);
	DDX_Control(pDX, IDC_BUTTON4, Member_Search_Button);
	DDX_Control(pDX, IDC_EDIT7, Member_Search_Edit);
	DDX_Control(pDX, IDC_LIST1, Member_Search_List);
	Member_Search_List.InsertColumn(0, _T("ID"), LVCFMT_LEFT, 100); // 표의 맨윗부분 
	Member_Search_List.InsertColumn(1, _T("PassWord"), LVCFMT_LEFT, 100);
	Member_Search_List.InsertColumn(2, _T("이름"), LVCFMT_LEFT, 100); 
	Member_Search_List.InsertColumn(3, _T("성별"), LVCFMT_LEFT, 100);
	Member_Search_List.InsertColumn(4, _T("나이"), LVCFMT_LEFT, 100);
	Member_Search_List.InsertColumn(5, _T("주소"), LVCFMT_LEFT, 100);
	Member_Search_List.InsertColumn(6, _T("핸드폰 번호"), LVCFMT_LEFT, 100);
}


BEGIN_MESSAGE_MAP(Member_Manager, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Member_Manager::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Member_Manager::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Member_Manager::OnBnClickedButton4)
END_MESSAGE_MAP()


// Member_Manager 메시지 처리기


void Member_Manager::OnBnClickedButton1() //등록 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString ID, Name, PassWord, Sex, Age, Address, Number;
	string temp, temp2, temp3;
	Member* str = new Member;
	int Cheak = 0;
	Member_ID_Edit.GetWindowTextW(ID);
	Member_Name_Edit.GetWindowTextW(Name);
	temp2 = CT2CA(ID.operator LPCWSTR());
	temp = CT2CA(Name.operator LPCWSTR());
	for (int i = 0; Bk.MemberList.size(); i++)
	{
		if (Bk.MemberList[i].Get_Member_Key() == temp2)
		{
			Member_Add_Button.MessageBox(_T("이미 있는 ID 입니다."));
			Cheak = 1;
			break;
		}
	}

	if (Cheak == 0)
	{
		str->Set_Member_Key(temp2, temp);

		Member_PassWord_Edit.GetWindowTextW(PassWord);
		Member_Sex_Edit.GetWindowTextW(Sex);
		temp2 = CT2CA(PassWord.operator LPCWSTR());
		temp = CT2CA(Sex.operator LPCWSTR());
		str->Set_Member_PassWord(temp2);
		str->Set_Member_Sex(temp);

		Member_Age_Edit.GetWindowTextW(Age);
		Member_Address_Edit.GetWindowTextW(Address);
		Member_Number_Edit.GetWindowTextW(Number);
		temp2 = CT2CA(Age.operator LPCWSTR());
		temp = CT2CA(Address.operator LPCWSTR());
		temp3 = CT2CA(Number.operator LPCWSTR());
		str->Set_Member_Age(temp2);
		str->Set_Member_Address(temp);
		str->Set_Member_Number(temp3);

		Member_Search_List.InsertItem(0, ID);
		Member_Search_List.SetItemText(0, 1, PassWord);
		Member_Search_List.SetItemText(0, 2, Name);
		Member_Search_List.SetItemText(0, 3, Sex);
		Member_Search_List.SetItemText(0, 4, Age);
		Member_Search_List.SetItemText(0, 5, Address);
		Member_Search_List.SetItemText(0, 6, Number);
		Bk.MemberList.push_back(*str);
		Member_Add_Button.MessageBox(_T("등록 완료"));
	}

}


void Member_Manager::OnBnClickedButton2() //삭제 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos;
	string text_Csring, ID;
	CString text;
	int Cheak = 0;
	pos = Member_Search_List.GetFirstSelectedItemPosition();
	int index = Member_Search_List.GetNextSelectedItem(pos);
	text = Member_Search_List.GetItemText(index, 0);
	text_Csring = CT2CA(text.operator LPCWSTR());

	for (int i = 0; Bk.MemberList.size(); i++)
	{
		if (Bk.MemberList[i].Get_Member_Key() == text_Csring)
		{
			Bk.MemberList.erase(Bk.MemberList.begin() + i);
			Member_Search_List.DeleteItem(index);
			Member_Delete_Button.MessageBox(_T("삭제 완료"));
			Cheak = 1;
			break;
		}
	}
	if (Cheak == 0) Member_Delete_Button.MessageBox(_T("일치하는 바코드가 없습니다."));
}


void Member_Manager::OnBnClickedButton4() // 조회버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	string temp;
	Member_Search_Edit.GetWindowTextW(str);
	temp = CT2CA(str.operator LPCWSTR());
	Member_Search_List.DeleteAllItems();
	for (int i = 0; i < Bk.MemberList.size(); i++)
	{
		if ((temp == Bk.MemberList[i].Get_Member_ID())|| (temp == Bk.MemberList[i].Get_Member_Key())||(Bk.MemberList[i].Get_Member_ID().find(temp) != string::npos) || (Bk.MemberList[i].Get_Member_Key().find(temp) != string::npos))
		{
			
			Member_Search_List.InsertItem(0, CA2CT(Bk.MemberList[i].Get_Member_Key().c_str())); // 표의 첫번째 인자
			Member_Search_List.SetItemText(0, 1, CA2CT(Bk.MemberList[i].Get_Member_PassWord().c_str())); // 첫번째 인자의 하위목록
			Member_Search_List.SetItemText(0, 2, CA2CT(Bk.MemberList[i].Get_Member_ID().c_str()));
			Member_Search_List.SetItemText(0, 3, CA2CT(Bk.MemberList[i].Get_Member_Sex().c_str()));
			Member_Search_List.SetItemText(0, 4, CA2CT(Bk.MemberList[i].Get_Member_Age().c_str()));
			Member_Search_List.SetItemText(0, 5, CA2CT(Bk.MemberList[i].Get_Member_Address().c_str()));
			Member_Search_List.SetItemText(0, 6, CA2CT(Bk.MemberList[i].Get_Member_Number().c_str()));
		}
	}
}
