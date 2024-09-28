#include<iostream>
#include<string>
#include"Group.h"
#include"Contact.h"
#include"Address.h"
#include"List.h"


using namespace std;

Group::Group() :name(""), count(0), size(0), contact_ids(nullptr)
{
	id = group_count++;
}

Group::~Group()
{
	if (count > 0 && contact_ids != nullptr)
	{
		delete[]contact_ids;
		contact_ids = nullptr;
		--group_count;
	}
}

Group::Group(string n, int* c_id, int c_count, int c_size) :name(n), count(c_count), size(c_size)
{
	contact_ids = new int[c_size];
	id = group_count++;
}


void Group::set_group_count(int c)
{
	group_count = c;
	count = c;
}

void Group::set_contact_id_to_group(int c_id)
{
	bool isEqual = false;
	for (int i = 0; i < count; i++)
	{
		if (contact_ids[i] == c_id)
		{
			isEqual = true;
			break;
		}
	}
	if (!isEqual)
	{
	    List<int> contact_ids_list(contact_ids, count, size);
	    contact_ids_list.addItem(c_id, count);
	    contact_ids = contact_ids_list.getArray();
	    set_group_count(contact_ids_list.get_list_count());
	}
	else
	{
		cout << "This contact is already stored in group:\n";
		display_group();
	}
}



bool Group::check_contact_id(int c_id)
{
	for (int i = 0; i < count; i++)
	{
		if (contact_ids[i] == c_id)
		{
			return true;
		}
	}
	return false;
}

void Group::display_group()
{
	cout << "Group ID:" << id << endl;
	cout << "Group Name: " << name << endl;
}

int Group::get_group_count()
{
	return count;
}

void Group::set_size(int s)
{
	size = s;
}

int Group::get_grp_id()
{
	return id;
}

int Group::get_group_size()
{
	return size;
}

string Group::get_group_name()
{
	return name;
}

void Group::set_group_name(string n)
{
	name = n;
}

Group& Group::operator=(Group& g)
{
	name = g.name;
	id = g.id;
	count = g.count;
	size = g.size;
	for (int i = 0; i < count; i++)
	{
		if (contact_ids != nullptr)
			contact_ids[i] = g.contact_ids[i];
	}
	return *this;
}

int Group::group_count = 0;

void Group::set_group_id(int i)
{
	id = i;
}

void Group::remove_contact_id_from_group(int c_id)
{
	if (contact_ids != nullptr)
	{
		for (int i = 0; i < count; i++)
		{
			if (c_id == contact_ids[i])
			{
				contact_ids[i] = 0;
				--count;
			}
		}
		int* temp = new int[count];
		for (int i = 0; i < count; i++)
		{
			if (contact_ids[i] != 0)
			{
				temp[i] = contact_ids[i];
			}
		}
		delete[]contact_ids;
		contact_ids = new int[count];

		for (int i = 0; i < count; i++)
		{
			if (contact_ids[i] != 0)
			{
				contact_ids[i] = temp[i];
			}
		}
		delete[]temp;
	}
	else
		cout << "No contact is stored in this group!!!\n";

}

void Group::remove_group_content()
{
	if (count != 0)
	{
		delete[]contact_ids;
		contact_ids = nullptr;
	}
}