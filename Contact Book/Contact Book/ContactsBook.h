#pragma once
#include "Address.h"
#include "Contact.h"
#include"SearchHistory.h"
#include"Group.h"
#include"List.h"


#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

	void Space(std::string& line);
	void trimmed(std::string& line);
	void spaces(std::string& str);
	bool only_numbers(const string& str);
class ContactsBook {
private:
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	static int contacts_count;     // total contacts currently stored, next contact will be 
	// stored at this count plus 1 index

	//SearchHistory Data Members 
	SearchHistory search_history;
	int frequent_five[5];
	int Id[50];
	int group_count;
	int group_size;
	Group* groups;

public:
	void swapContacts(Contact& contact1, Contact& contact2);
	void print();
	void AdvancedPrint();
	void print_id();
	void UpdateContact(int);
	void DeleteContact(int);
	void StoreGroupToFile();
	void LoadGroupFromFile();
	ContactsBook();
	void add_contact(Contact* contact);
	int total_contacts();
	Contact* resize_arr(Contact*, int, int&);
	Contact* search_contact(std::string first_name, std::string last_name);
	Contact* search_contact(std::string phone);
	Contact* search_contact(const Address address);
	//ContactsBook(const ContactsBook& other);
	ContactsBook(const ContactsBook& other);
	ContactsBook& operator=(const ContactsBook& other);
	ContactsBook(int size_of_list);

	// Functions For Search History Functinality
	void search_string_contact();
	bool match_string_contact(Contact& contact, const string& str);
	void display_search_history();
	void calculate_frequent_five();
	void display_frequent_five();
	void matchAttribute(string& s, string str, int& index, string& temp);
	void search_advance_view(int id);
	bool match_string(Contact& contact, const string& str);

	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if

	// Functions for Groups
	void add_group();
	void display_groups();
	void add_contact_to_group();
	void search_contact_group();
	void remove_group();

/*
*  This function loads contacts from the given file (see details in ContactsBook.cpp)
*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);
	~ContactsBook() {
		delete[] contacts_list;
	}
private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
};
