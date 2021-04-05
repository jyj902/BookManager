#pragma once
#include "Book.h"
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Member.h"
using namespace std;
class Data_Base : public Book, public Member
{
public:
	Data_Base();

	void Load_Book_Data();
	vector<Book> BookList;

	void Load_Member_Data();
	vector<Member> MemberList;

	//map<int, string>Book_id;
private:
	//map<int, string>Book_ID;
	//map<string, string>Member_ID;
};

