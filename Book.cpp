#include "pch.h"
#include "Book.h"
Book::Book()
{
}

string Book::Get_Book_Writer()
{
	return Writer;
}
string Book::Get_Book_Publisher()
{
	return Publisher;
}
string Book::Get_Book_Classification()
{
	return Classification;
}
string Book::Get_Book_Rental()
{
	if (stoi(Stock) <=0 ) return ("대여 불가");
	else return ("대여 가능");
}
string Book::Get_Book_Stock()
{
	return Stock;
}
string Book::Get_Book_Rental_Num()
{
	return Rental_Num;
}
string Book::Get_Book_Name()
{
	return Book_ID.rbegin()->second;
}

int Book::Get_Book_Key()
{
	return Book_ID.rbegin()->first;
}



void Book::Set_Book_ID(int key, string value)
{
	Book_ID.insert(pair<int, string>(key, value));
}
void Book::Set_Book_Writer(string Writer)
{
	this->Writer = Writer;
}
void Book::Set_Book_Publisher(string Publisher)
{
	this->Publisher = Publisher;
}
void Book::Set_Book_Classification(string Classification)
{
	this->Classification = Classification;
}
void Book::Set_Book_Rental(string Rental)
{
	this->Rental = Rental;
}
void Book::Set_Book_Stock(string Stock)
{
	this->Stock = Stock;
}
void Book::Set_Book_Rental_Num(string Rental_Num)
{
	this->Rental_Num = Rental_Num;
}