// m_log.cpp: 구현 파일
//

#include "pch.h"
#include "BookManager07.h"
#include "m_log.h"
#include "afxdialogex.h"
#include <String>
#include "Manager_Page.h"
using namespace std;
string Manager_PassWord = "qwer1234";

// m_log 대화 상자

IMPLEMENT_DYNAMIC(m_log, CDialogEx)

m_log::m_log(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

m_log::~m_log()
{
}

void m_log::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, Manager_Login);
	DDX_Control(pDX, IDC_EDIT1, Manager_PassWord_Edit);
}


BEGIN_MESSAGE_MAP(m_log, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &m_log::OnBnClickedButton1)
END_MESSAGE_MAP()


// m_log 메시지 처리기


void m_log::OnBnClickedButton1()
{
	CString str;
	Manager_PassWord_Edit.GetWindowTextW(str);
	string str_Pass = CT2CA(str.operator LPCWSTR());
	if (str_Pass == Manager_PassWord)
	{
		Manager_Page dlg;
		dlg.DoModal();
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
