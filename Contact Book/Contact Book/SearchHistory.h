#pragma once
#include<iostream>
#include<string>
#include"historyObject.h"
//#include"List.h"
using namespace std;
class SearchHistory
{
	historyObject* history;
	int history_count;
	int history_size;
	int Count;
	int Size;
public:
	SearchHistory();
	~SearchHistory();
	SearchHistory(historyObject h[], int count, int size);
	SearchHistory(SearchHistory& h);
	SearchHistory& operator=(SearchHistory& h);
	void display_all_history();
	void set_SearchHistory_search(string str, string Time, string day, string Date);
	int get_history_count();
	void save_SearchHistory_file(string);
};