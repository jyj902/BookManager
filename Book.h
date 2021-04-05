#pragma once
#include <string>
#include <map>

using namespace std;

class Book
{
public:
	Book();

	int Get_Book_Key();
	string Get_Book_Name();
	string Get_Book_Writer();
	string Get_Book_Publisher();
	string Get_Book_Classification();
	string Get_Book_Rental();
	string Get_Book_Stock();
	string Get_Book_Rental_Num();

	void Set_Book_ID(int key, string value);
	void Set_Book_Writer(string Writer);
	void Set_Book_Publisher(string Publisher);
	void Set_Book_Classification(string Classification);
	void Set_Book_Rental(string Rental);
	void Set_Book_Stock(string Stock);
	void Set_Book_Rental_Num(string Rental_Num);
	map<int, string>Book_ID;

private:
	string Writer;
	string Publisher;
	string Classification;
	string Rental;
	string Stock;
	string Rental_Num;
};