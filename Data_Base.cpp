#include "pch.h"
#include "Data_Base.h"


Data_Base::Data_Base()
{}

void Data_Base::Load_Book_Data()
{
	ifstream Book_Data("Book_Data.csv");
	string line, cell, name, key;
	Book* str= new Book;
	int location = 0;
	BookList.clear();
	while (getline(Book_Data, line))
	{
		location = 0;
		stringstream lineStream(line);
		getline(lineStream, key,',');
		getline(lineStream, name, ',');
		str->Book_ID.clear();
		str->Set_Book_ID(atoi(key.c_str()), name);
		while (getline(lineStream, cell, ','))
		{
			if (location == 0) str->Set_Book_Writer(cell);
			else if (location == 1) str->Set_Book_Publisher(cell);
			else if (location == 2) str->Set_Book_Classification(cell);
			else if (location == 3) str->Set_Book_Rental(cell);
			else if (location == 4) str->Set_Book_Stock(cell);
			else if (location == 5) str->Set_Book_Rental_Num(cell);
			location++;
		}
		BookList.push_back(*str);
	}
}

void Data_Base::Load_Member_Data()
{
	ifstream Member_Data("Member_Data.csv");
	string line, cell, name, key;
	Member* str = new Member;
	int location = 0;
	MemberList.clear();
	while (getline(Member_Data, line))
	{
		location = 0;
		stringstream lineStream(line);
		getline(lineStream, key, ',');
		getline(lineStream, name, ',');
		str->Member_ID.clear();
		str->Set_Member_Key(key, name);
		while (getline(lineStream, cell, ','))
		{
			if (location == 0) str->Set_Member_PassWord(cell);
			else if (location == 1) str->Set_Member_Sex(cell);
			else if (location == 2) str->Set_Member_Age(cell);
			else if (location == 3) str->Set_Member_Address(cell);
			else if (location == 4) str->Set_Member_Number(cell);
			else if (location > 4) str->Set_Member_Rental_Num(cell, location-5);
			location++;
		}
		MemberList.push_back(*str);
	}
}