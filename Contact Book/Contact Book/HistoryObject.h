#pragma once
#include<iostream>
#include<string>
#include"List.h"

using namespace std;

class historyObject
{
	string search;
	string time;
	string date;
	string day;
public:
	~historyObject();
	historyObject();
	historyObject(string s, string t, string d, string da);
	//historyObject(historyObject& h);
	historyObject& operator=(historyObject& h);
	void set_search(string s);
	string get_search();
	void display_history();
	void set_time(string t);
	string get_time();
	void set_date(string d);
	string get_date();
	void set_day(string d);
	string get_day();
};