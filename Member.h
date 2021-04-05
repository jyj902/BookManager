#pragma once
#include <string>
#include <map>
#include <vector>
using namespace std;
class Member
{
public:
	Member();

	string Get_Member_Key();
	string Get_Member_PassWord();
	string Get_Member_ID();
	string Get_Member_Sex();
	string Get_Member_Age();
	string Get_Member_Address();
	string Get_Member_Number();
	string Get_Member_Rental_Num(int i);

	void Set_Member_Key(string key, string value);
	void Set_Member_PassWord(string PassWord);
	void Set_Member_Sex(string Sex);
	void Set_Member_Age(string Age);
	void Set_Member_Address(string Address);
	void Set_Member_Number(string Number);
	void Set_Member_Rental_Num(string Rental_Num, int i);
	map <string, string>Member_ID;
	
private:
	string PassWord;
	string Sex;
	string Age;
	string Address;
	string Number;
	string Rental_Num[3];
};
