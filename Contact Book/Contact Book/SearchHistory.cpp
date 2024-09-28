#include<iostream>
#include<string>
#include"List.h"
#include"historyObject.h"
#include"SearchHistory.h"
#include<fstream>
#include <vector>

using namespace std;



SearchHistory::SearchHistory() : history_count(0), history_size(0)
{
	history = nullptr;
}

SearchHistory::SearchHistory(historyObject h[], int count, int size) : history_count(count), history_size(size), history(nullptr)
{
	history = new historyObject[size];
	history = h;
	// yahan List wali implimentation krni again ye shi nhi h

}

SearchHistory::SearchHistory(SearchHistory& h)
{
	history_count = h.history_count;		// agar yahan error aye to history_count & hitory_size
	history_size = h.history_size;			// k getter/setter bana k use krne hn
	for (int i = 0; i < history_count; i++)
	{
		history[i] = h.history[i];
	}
}

SearchHistory& SearchHistory::operator = (SearchHistory& h)
{
	if (this != &h)
	{
		history_count = h.history_count;			// agar yahan error aye to history_count & hitory_size
		history_size = h.history_size;				// k getter/setter bana k use krne hn
		for (int i = 0; i < history_count; i++)
		{
			history[i] = h.history[i];
		}
	}

	return *this;
}

void SearchHistory::display_all_history()
{
	string str[100];
	int count = 0;
	std::ifstream in("Searchrecord.txt");

	if (in.is_open())
	{
		std::vector<std::string> lines_in_reverse;
		std::string line;
		while (std::getline(in, line))
		{
			// Store the lines in reverse order.
			lines_in_reverse.insert(lines_in_reverse.begin(), line);
			//cout << line << endl;
			str[count] = line;
			count++;
		}
		in.close();
	}
	else
		cout << "File not open..\n";
	for (int i = count - 1;i >= 0; --i) {
		cout << str[i] << endl;
	}

	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}

void SearchHistory::set_SearchHistory_search(string str, string Time, string day, string Date)
{
	/*List<historyObject> history_list(history, history_count, history_size);
	historyObject temp;
	temp.set_search(str);
	history_list.addItem(temp, history_count);
	history = history_list.getArray();	*/

	if (history_count == history_size)
	{
		historyObject* temp = new historyObject[++history_size];
		for (int i = 0; i < history_count; i++)
		{
			temp[i] = history[i];
		}
		delete[]history;
		history = new historyObject[history_size];
		for (int i = 0; i < history_count; i++)
		{
			history[i] = temp[i];
		}

		history[history_count].set_search(str);
		history[history_count].set_time(Time);
		history[history_count].set_date(Date);
		history[history_count].set_day(day);
	}
	else
	{
		history[history_count].set_search(str);
	}
	history_count++;
}

SearchHistory::~SearchHistory()
{
	delete[]history;
	//delete history;
	history = nullptr;
}

int SearchHistory::get_history_count()
{
	return history_count;
}

void SearchHistory::save_SearchHistory_file(string str) {

	ofstream file(str, ios::app);
	if (!file.is_open()) { cout << "Error file not opened!"; }
	else {
		file << "SEARCHED STRING: " << history->get_search() << "\nDATE: " << history->get_date() << "\nTIME: " << history->get_time() << endl << endl;

	}
}