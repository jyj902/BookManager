#include "pch.h"
#include "Member.h"


Member::Member()
{}
string Member::Get_Member_PassWord()
{
	return PassWord;
}
string Member::Get_Member_Sex()
{
	return Sex;
}
string Member::Get_Member_Age()
{
	return Age;
}
string Member::Get_Member_Address()
{
	return Address;
}
string Member::Get_Member_Number()
{
	return Number;
}
string Member::Get_Member_Rental_Num(int i)

{
	return Rental_Num[i];
}

string Member::Get_Member_ID()
{
	return Member_ID.rbegin()->second;
}

string Member::Get_Member_Key()
{
	return Member_ID.rbegin()->first;
}

void Member::Set_Member_Key(string key, string value)
{
	Member_ID.insert(pair<string, string>(key, value));
}
void Member::Set_Member_PassWord(string PassWord)
{
	this->PassWord = PassWord;
}
void Member::Set_Member_Sex(string Sex)
{
	this->Sex = Sex;
}
void Member::Set_Member_Age(string Age)
{
	this->Age = Age;
}
void Member::Set_Member_Address(string Address)
{
	this->Address = Address;
}
void Member::Set_Member_Number(string Number)
{
	this->Number = Number;
}
void Member::Set_Member_Rental_Num(string Rental_Num, int i)
{
	this->Rental_Num[i] = Rental_Num;
}