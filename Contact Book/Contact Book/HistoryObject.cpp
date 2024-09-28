#include<iostream>
#include"historyObject.h"
//#include"List.h"
#include<string>
using namespace std;

historyObject::~historyObject() {}

historyObject::historyObject() :search(""), time(""), date(""), day("") {}

historyObject::historyObject(string s, string t, string d, string da) :search(s), time(t), date(d), day(da) {}

historyObject& historyObject::operator=(historyObject& h)
{
	if (this != &h)
	{
		set_search(h.get_search());
		set_time(h.get_time());
		set_date(h.get_date());
		set_day(h.get_day());
	}
	return *this;
}

void historyObject::set_search(string s) { search = s; }

string historyObject::get_search() { return search; }

void historyObject::display_history()
{
	cout << "Search string: " << search << endl;
	cout << "Time: " << time << endl;
	cout << "Day: " << day << endl;
	cout << "Date: " << date << endl;
}

void historyObject::set_time(string t)
{
	time = t;
}
string historyObject::get_time()
{
	return time;
}

void historyObject::set_date(string d)
{
	date = d;
}

string historyObject::get_date()
{
	return date;
}

void historyObject::set_day(string d)
{
	day = d;
}

string historyObject::get_day()
{
	return day;
}