// Member_log.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "Member_log.h"
#include "afxdialogex.h"
#include "Member_Page.h"
extern Data_Base Bk;

int Member_Num;
// Member_log 대화 상자

IMPLEMENT_DYNAMIC(Member_log, CDialogEx)

Member_log::Member_log(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

Member_log::~Member_log()
{
}

void Member_log::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, Member_Log_ID_Edit);
	DDX_Control(pDX, IDC_EDIT3, Member_Log_PassWord_Edit);
	DDX_Control(pDX, IDC_BUTTON1, Member_Log_Button);
}


BEGIN_MESSAGE_MAP(Member_log, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Member_log::OnBnClickedButton1)
END_MESSAGE_MAP()


// Member_log 메시지 처리기


void Member_log::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString ID, PassWord;
	int Cheak=0;
	Member_Log_ID_Edit.GetWindowTextW(ID);
	Member_Log_PassWord_Edit.GetWindowTextW(PassWord);
	string ID_Str = CT2CA(ID.operator LPCWSTR());
	string PassWord_Str = CT2CA(PassWord.operator LPCWSTR());
	for (Member_Num = 0; Member_Num < Bk.MemberList.size(); Member_Num++)
	{
		if (ID_Str == Bk.MemberList[Member_Num].Get_Member_Key())
			if (PassWord_Str == Bk.MemberList[Member_Num].Get_Member_PassWord())
			{
				Member_Page dlg;
				dlg.DoModal();
				Cheak = 1;
			}
	}
	if(Cheak == 0) MessageBox(_T("일치하는 회원이 없습니다 관리자에게 문의해 주세요"));
}
