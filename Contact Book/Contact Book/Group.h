#pragma once
#include<iostream>
#include<string>
#include"Contact.h"
#include"Address.h"
#include"List.h"


using namespace std;

class Group
{
	string name;
	int id;
	int* contact_ids;
	int count;
	int size;
public:
	static int group_count;
	Group();
	~Group();
	Group(string n, int* c_id, int c_count, int c_size);
	void set_contact_id_to_group(int c_id);
	bool check_contact_id(int c_id);
	void display_group();
	int get_group_count();
	void set_size(int);
	int get_grp_id();
	void set_group_count(int c);
	int get_group_size();
	string get_group_name();
	void set_group_name(string n);
	void set_group_id(int i);
	Group& operator=(Group& g);
	void remove_contact_id_from_group(int c_id);
	void remove_group_content();
};