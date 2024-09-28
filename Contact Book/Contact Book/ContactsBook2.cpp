#include <iostream>
#include <fstream>
#include "ContactsBook.h"
#include <string>
#include "SearchHistory.h"
#include "HistoryObject.h"
#include "Group.h"
#include <ctime>
#include <algorithm>
#include <vector>

ContactsBook::ContactsBook() {

}

void ContactsBook::add_contact(Contact *contact)
{
	if (full()) {
		resize_list();
	}
		contacts_list[contacts_count] = *contact;
		contacts_list[contacts_count].SetId(contacts_list[contacts_count].GetId());
		this->contacts_count++;
		//contact->SetId(contact->GetId());
		/*
			- Check if the list is full, if it is full call the resize function
			- If list is not full add the contact to the end of the array
			- (end means the place where last contact was inserted)
			- At start it will be 0th index as no contact has been inserted before so
			- count is zero (contacts_count member)
			- Increment the count
			- As inserted successfully, return 1
		*/

}



void ContactsBook::print_id() {
		std::cout << "Showing ID's of contacts added\n";
	for (int i=0; i < contacts_count; i++)
	{
		std::cout << "ID:" << contacts_list[i].GetId() << std::endl;
	}
}
void ContactsBook::UpdateContact(int i)
{
	std::cout << "Do you want to update this contact(Y/N) ";
	char ch; std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		std::string temp;
		std::cout << "Enter new mobile number: ";
		std::cin >> temp;
		contacts_list[i].SetMobileN(temp);
		std::cout << "Enter new Email Address: ";
		std::cin >> temp;
		contacts_list[i].SetEmail(temp);
		std::cout << "Enter new House number: ";
		std::cin >> temp;
		contacts_list[i].GetAddress()->SetHouse(temp);
		std::cout << "Enter new street number: ";
		std::cin >> temp;
		contacts_list[i].GetAddress()->SetStreet(temp);
		std::cout << "Enter new city name: ";
		std::cin >> temp;
		contacts_list[i].GetAddress()->SetCity(temp);
		std::cout << "Enter new country name: ";
		std::cin >> temp;
		contacts_list[i].GetAddress()->SetCountry(temp);
	}
}
void ContactsBook::DeleteContact(int j)
{
	std::cout << "Do you want to delete this contact(Y/N) ";
	char ch; std::cin >> ch;
	if (ch == 'y' || ch == 'Y')
	{
		int size = contacts_count;
		Contact* temp_array = new Contact[size];
		int k = 0;
		for (int i = 0; i < size; i++)
		{
			if (i != j)
			{
				temp_array[k] = contacts_list[i];
				k++;
			}
		}
		contacts_list = temp_array;
		contacts_count = --size;		//updating contacts_count
	}
}
void ContactsBook::StoreGroupToFile()
{
	ofstream file("group.txt");
	if (!file.is_open()) {
		cout << "Error file not opened!";
	}
	else 
	{
		file << group_size << endl;

		for (int i = 0; i < group_size; i++)
		{
			file << groups[i].get_grp_id() << "," << groups[i].get_group_name() << endl;
		}
	}
}
void ContactsBook::LoadGroupFromFile()
{
	ifstream infile("group.txt");
	int groupCount;
	infile >> groupCount;
	Group *temp = new Group[groupCount];
	for (int i = 0; i < groupCount; i++)
	{

		int id=0;
		string name;
		char a;
		infile >> id;
		infile >> a;
		getline(infile, name);
		temp[i].set_group_id(id);
		temp[i].set_group_name(name);
	}
	group_count = groupCount;
	group_size = groupCount * 2;

	temp->set_group_count(groupCount);
	groups = temp;
	temp = nullptr;

}
void ContactsBook::print()
{
	for (int i = 0; i < contacts_count; ++i)
	{
		std::cout << "  Contact #" << i + 1 << std::endl;
		std::cout << "  Name:     " << contacts_list[i].GetFirstN() << " " << contacts_list[i].GetLastN() << std::endl;
		std::cout << "  Email:    " << contacts_list[i].GetEmail() << std::endl;
		std::cout << "  Mobile:   " << contacts_list[i].GetMobileN() << std::endl;
		std::cout << "  Address:  " << std::endl;
		std::cout << "              House: " << contacts_list[i].GetAddress()->GetHouse() << std::endl;
		std::cout << "              Street: " << contacts_list[i].GetAddress()->GetStreet() << std::endl;
		std::cout << "              City: " << contacts_list[i].GetAddress()->GetCity() << std::endl;
		std::cout << "              Country: " << contacts_list[i].GetAddress()->GetCountry() << std::endl;
		std::cout << std::endl;
	}
}
void ContactsBook::AdvancedPrint()
{
	print_id();							//calling this function just to print IDs
	std::cout << "Enter ID of contact you want to print: ";
	int temp; std::cin >> temp;
	bool found = true;
	for (int i = 0; i < contacts_count; ++i) 
	{
		if (contacts_list[i].GetId() == temp)
		{
			std::cout << "  Contact #" << i + 1 << std::endl;
			std::cout << "  Name:     " << contacts_list[i].GetFirstN() << " " << contacts_list[i].GetLastN() << std::endl;
			std::cout << "  Email:    " << contacts_list[i].GetEmail() << std::endl;
			std::cout << "  Mobile:   " << contacts_list[i].GetMobileN() << std::endl;
			std::cout << "  Address:  " << std::endl;
			std::cout << "              House: " << contacts_list[i].GetAddress()->GetHouse() << std::endl;
			std::cout << "              Street: " << contacts_list[i].GetAddress()->GetStreet() << std::endl;
			std::cout << "              City: " << contacts_list[i].GetAddress()->GetCity() << std::endl;
			std::cout << "              Country: " << contacts_list[i].GetAddress()->GetCountry() << std::endl;
			std::cout << std::endl;
			found = true;
			UpdateContact(i);		//passing index to be deleted
			DeleteContact(i);
		}
	}
	if(!found)
		std::cout << "No contact found with this ID\n";
}

int ContactsBook::total_contacts()
{
	/*
	*	Return the total contacts currently stored
	*/

	/*
	*	Remove this return -1; before writing your code
	*/
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/

	/*
	*	Remove this return false; before writing your code
	*/
	if (contacts_count< size_of_contacts)
		return false;
	else return true;
}

void ContactsBook::resize_list()
{
	size_of_contacts = size_of_contacts * 2;
	Contact* temp_obj = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; ++i) 
	{
		temp_obj[i] = contacts_list[i];		//copying data of previous contact array
	}
	delete[] contacts_list;
	contacts_list = temp_obj;
	temp_obj = nullptr;
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
}

Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	bool found = false;
	for (int i = 0; i < contacts_count; ++i) 
	{
		if (contacts_list[i].GetFirstN() == first_name && contacts_list[i].GetLastN() == last_name)
		{
			Contact *obj_temp = contacts_list[i].copy_contact();
			obj_temp->SetAddress(contacts_list[i].GetAddress());
			found = true;
			return obj_temp;
		}
	}
	if (!found)
		return nullptr;
}

Contact* ContactsBook::search_contact(std::string phone)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	bool found = false;
	for (int i = 0; i < contacts_count; ++i) 
	{
		if (contacts_list[i].GetMobileN() == phone) 
		{
			Contact* obj_temp = contacts_list[i].copy_contact();
			obj_temp->SetAddress(contacts_list[i].GetAddress());
			found = true;
			return obj_temp;
		}
	}
	if (!found)
		return nullptr;
}

Contact* ContactsBook::search_contact(const Address address)
{
	/*
	*	Remove this return nullptr; before writing your code
	*/
	bool found = false;
		for (int i = 0; i < contacts_count; ++i)
		{
			if ((contacts_list[i].GetAddress()->equals(address)))
			{
				Contact* obj_temp = contacts_list[i].copy_contact();
				found = true;
				obj_temp->SetAddress(contacts_list[i].GetAddress());
				return obj_temp;
			}
		}
		if (!found)
			return nullptr;
}




ContactsBook::ContactsBook(int size_of_list)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	contacts_count = 0;
	size_of_contacts = size_of_list;
	contacts_list = new Contact[size_of_contacts];
}


void ContactsBook::print_contacts_sorted(std::string choice) {
	if (choice != "1" && choice != "2") 
	{
		std::cout << "invalid choice" << std::endl;
		return;
	}

	int size = contacts_count;
	Contact* temp_array = new Contact;
	temp_array = contacts_list;

	sort_contacts_list(temp_array, choice);

	std::cout << "Sorted contacts:\n";
	for (int i = 0; i < size; ++i) 
	{
		std::cout << "  Contact #" << i + 1 << std::endl;
		std::cout << "  Name:     " << temp_array[i].GetFirstN() << " " << temp_array[i].GetLastN() << std::endl;
		std::cout << "  Email:    " << temp_array[i].GetEmail() << std::endl;
		std::cout << "  Mobile:   " << temp_array[i].GetMobileN() << std::endl;
		std::cout << "  Address:  " << std::endl;
		std::cout << "              House: " << temp_array[i].GetAddress()->GetHouse() << std::endl;
		std::cout << "              Street: " << temp_array[i].GetAddress()->GetStreet() << std::endl;
		std::cout << "              City: " << temp_array[i].GetAddress()->GetCity() << std::endl;
		std::cout << "              Country: " << temp_array[i].GetAddress()->GetCountry() << std::endl;
		std::cout << std::endl;
	}

	delete[] temp_array;
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/

}
std::string toLower(const std::string& str)		//i have creating this function so that 'A' and 'a' are at same place
{
	std::string result;
	for (size_t i = 0; i < str.length(); i++)
	{
		char c = str[i];
		if (c >= 'A' && c <= 'Z')
		{
			//changing upper to lower
			result = result + static_cast<char>(c + 32);
		}
		else
		{
			result += c; //if it is not upper case storing as it is
		}
	}
	return result;
}
void ContactsBook:: swapContacts(Contact& contact1, Contact& contact2)
{
	
	string temp = contact1.GetFirstN();
	contact1.SetFirstN(contact2.GetFirstN());
	contact2.SetFirstN(temp);

	temp = contact1.GetLastN();
	contact1.SetLastN(contact2.GetLastN());
	contact2.SetLastN(temp);

	temp = contact1.GetMobileN();
	contact1.SetMobileN(contact2.GetMobileN());
	contact2.SetMobileN(temp);

	temp = contact1.GetEmail();
	contact1.SetEmail(contact2.GetEmail());
	contact2.SetEmail(temp);

	Address* address1 = contact1.GetAddress();
	Address* address2 = contact2.GetAddress();
	temp = address1->GetHouse();
	address1->SetHouse(address2->GetHouse());
	address2->SetHouse(temp);

	temp = address1->GetStreet();
	address1->SetStreet(address2->GetStreet());
	address2->SetStreet(temp);

	temp = address1->GetCity();
	address1->SetCity(address2->GetCity());
	address2->SetCity(temp);

	temp = address1->GetCountry();
	address1->SetCountry(address2->GetCountry());
	address2->SetCountry(temp);
}
void ContactsBook::sort_contacts_list(Contact* contacts_list,std::string choice) 
{
	int size = contacts_count;

	if (choice == "1") 
	{
		for (int i = 0; i < contacts_count - 1; i++)
		{
			for (int j = i + 1; j < contacts_count; j++)
			{
				char a= contacts_list[i].GetFirstN()[0], b=contacts_list[j].GetFirstN()[0];
				if (a > b)
				{
					swapContacts(contacts_list[i], contacts_list[j]);
				}
			}
		}

	}
	else if (choice == "2") 
	{
		for (int i = 0; i < contacts_count - 1; i++)
		{
			for (int j = i + 1; j < contacts_count; j++)
			{
				char a = contacts_list[i].GetLastN()[0], b = contacts_list[j].GetLastN()[0];
				if (a > b)
				{
					swapContacts(contacts_list[i], contacts_list[j]);
				}
			}
		}
	}
	else 
	{
		//already checked if choice is wrong
	}
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
}

void ContactsBook::merge_duplicates()
{
	int count = 0;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j])) {
				count++;
				contacts_list = resize_arr(contacts_list, j, contacts_count);
			}
		}
	}
	std::cout << count << " contacts merged\n";
	//}

	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts merged, and count of merged contacts
}

void ContactsBook::add_group()
{
	string g_name = "";
	string temp;
	do {
		cout << "Enter name of group: " << endl;
		trimmed(g_name);
		temp = g_name;
		//spaces(temp);
		if (temp == "")
			cout << "Invalid input\n";
	} while (temp == "");

	if (group_count >= group_size)
	{
		//double the group size if the current number of groups exceeds the capacity
		Group* temp = new Group[++group_size];

		for (int i = 0; i < group_count; i++)
		{
			temp[i] = groups[i];
		}
		for (int i = 0; i < group_size; i++)
		{
			temp[i].set_group_id(i + 1); //assigning unique IDs starting from 1
		}
		//delete[] groups;
		groups = new Group[group_size];
		for (int i = 0; i < group_count; i++)
		{
			groups[i] = temp[i];
		}
		groups[group_count].set_group_name(g_name);
		groups[group_count].set_group_id(group_count + 1); //assigning unique IDs starting from 1
	}
	else
	{
		groups[group_count+1].set_group_name(g_name);
		groups[group_count+1].set_group_id(group_count + 1); //assigning unique IDs starting from 1
	}
	group_count++;
	groups->set_group_count(group_count);


}

void ContactsBook::display_groups()
{
	if (group_count != 0)
	{
		for (int i = 0; i < group_count; i++) { 
			groups[i].display_group(); 
		}
	}
	else cout << "No group is present RN\n";

}

void ContactsBook::add_contact_to_group()
{
	string g_id;
	if (group_count != 0)
	{
		display_groups();
		do {
			cout << "Enter ID of group\n";
			cin >> g_id;
			if (stoi(g_id) < 1 || stoi(g_id) > group_count)
				cout << "Invalid input!!! Try again\n";
		} while (stoi(g_id) < 1 || stoi(g_id) > group_count);

		cin.ignore();
		if (contacts_count != 0)
		{
			string int_c_id = "";
			do {
				for (int i = 0; i < contacts_count; i++) { contacts_list[i].Print_Contact(); }
				cout << "Enter Contact ID to store in Group" << endl;
				while (1)
				{
					trimmed(int_c_id);
					spaces(int_c_id);
					if (int_c_id == "")
					{
						cout << "Invalid input!!! Try again\n";
						continue;
					}
					else
					{
						if (only_numbers(int_c_id))
						{
							break;
						}
						else
							cout << "Invalid input!!! Try again\n";
					}
				}
				if (stoi(int_c_id) < 1 || stoi(int_c_id) > contacts_count)
					cout << "Invalid Input!!! Try again\n";
			} while (stoi(int_c_id) < 1 || stoi(int_c_id) > contacts_count);

			groups[stoi(g_id) - 1].set_contact_id_to_group(stoi(int_c_id));
		}
		else cout << "No contact is present now\n";
	}
	else cout << "No group is present now\n";
}

void ContactsBook::search_contact_group()

{
	if (group_count != 0)
	{
		if (contacts_count != 0)
		{

			int c_id = 0;
			string id = "";
			do {
				for (int i = 0; i < contacts_count; i++)
				{
					contacts_list[i].Print_Contact();
				}
				cout << "Enter contact ID to search in groups\n";
				while (1)
				{
					trimmed(id);
					spaces(id);
					if (id == "")
					{
						cout << "Invalid input!!! Try again\n";
						continue;
					}
					else
					{
						if (only_numbers(id))
						{
							break;
						}
						else
							cout << "Invalid input!!! Try again\n";
					}
				}
				if (stoi(id) < 1 || stoi(id) > contacts_count)
					cout << "Invalid input!!! Try again\n";
			} while (stoi(id) < 1 || stoi(id) > contacts_count);

			c_id = stoi(id);
			bool isTrue = false;
			for (int i = 0; i < group_count; i++)
			{
				isTrue = true;
				if (groups[i].check_contact_id(c_id))
				{
					cout << "Contact found in group:\n";
					groups[i].display_group();
				}
				else cout << "No match Found!!!" << endl;
			}
			if (!isTrue)
				cout << "Given contact is not found in any group\n";
		}
		else
			cout << "No contact is present now!!!\n";
	}
	else
		cout << "No group is present now!!!\n";
}

void ContactsBook::remove_group()

{
	if (group_count != 0)
	{
		string id = "";
		int g_id = 0;

		do {
			display_groups();
			cout << "Enter ID of group\n";
			while (1)
			{
				trimmed(id);
				spaces(id);
				if (id == "")
				{
					cout << "Invalid input!!! Try again\n";
					continue;
				}
				else
				{
					if (only_numbers(id))
					{
						break;
					}
					else
						cout << "Invalid input!!! Try again\n";
				}
			}
			if (stoi(id) < 1 || stoi(id) > group_count)
				cout << "Invalid input!!! Try again\n";
		} while (stoi(id) < 1 || stoi(id) > group_count);
		g_id = stoi(id);
		groups[--g_id].remove_group_content();
		List<Group> groups_list(groups, group_count, group_size);
		groups_list.removeItem(g_id, group_count);
		groups = groups_list.getArray();
		for (int i = 0; i < group_count; i++) { groups[i].set_group_id(i + 1); }
		cout << "GROUP IS REMOVED SUCCESSFULLY...\n";
	}
	else cout << "No group created yet\n";
}


void ContactsBook::load_from_file(std::string file_name)
{
	std::ifstream in;
	in.open(file_name);
	if (in.is_open())
	{	
		in >> contacts_count;
		in.ignore();
		for (int i = 0; i < contacts_count; i++)
		{
			int Temp_id;
			std::string FN, LN, MN, EA;		//creating temporary strings to store contact class data taken from file 
			std::string house, street, city, country;	//creating temporary strings to store address class data taken from file 
			getline(in, FN, ',');
			getline(in, LN, ',');
			getline(in, MN, ',');
			getline(in, EA,',');				//here not using ',' bcz there is endl at end so we dont need to stop it to next , and also we want to move to next line for address
			in >> Temp_id;
			getline(in, house, ',');
			getline(in, street, ',');
			getline(in, city, ',');
			getline(in, country);
			contacts_list[i].SetFirstN(FN);
			contacts_list[i].SetLastN(LN);
			contacts_list[i].SetMobileN(MN);
			contacts_list[i].SetEmail(EA);
			contacts_list[i].SetId2(Temp_id);
			contacts_list[i].GetAddress()->SetHouse(house);
			contacts_list[i].GetAddress()->SetStreet(street);
			contacts_list[i].GetAddress()->SetCity(city);
			contacts_list[i].GetAddress()->SetCountry(country);
		}
		in.close();
	}
	else std::cout << "File not opened\n";
	/*
	*	Read contacts back from file in the same format
	*	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
}


void ContactsBook::save_to_file(std::string file_name)
{
	std::ofstream off;
	off.open(file_name, std::ios::out);
	if (off.is_open()) {
		off << contacts_count << std::endl;
		for (int i = 0; i < contacts_count; ++i)
		{
			off << contacts_list[i].GetFirstN() << "," << contacts_list[i].GetLastN() << ","
				<< contacts_list[i].GetMobileN() << "," << contacts_list[i].GetEmail() << ',' << contacts_list[i].GetId() << std::endl
				<< contacts_list[i].GetAddress()->GetHouse() << "," << contacts_list[i].GetAddress()->GetStreet() << "," <<
				contacts_list[i].GetAddress()->GetCity() << "," << contacts_list[i].GetAddress()->GetCountry() << std::endl;
		}
		off.close();
	}
	else {
		std::cout << "File cannot be opened\n";
	}


	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
}
ContactsBook::ContactsBook(const ContactsBook& other) {
	contacts_list = other.contacts_list; 
}
ContactsBook& ContactsBook::operator=(const ContactsBook& other) 
{
	if (this != &other) 
	{ 
		contacts_list = other.contacts_list;
	}
	return *this;
}
Contact* ContactsBook::resize_arr(Contact* contact_list, int dublicate_index, int& contacts_count)
{

	this->contacts_count--;
	Contact* temp = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; ++i)
	{
		if (i != dublicate_index)
		{
			temp[i] = contacts_list[i];
		}

	}
	return temp;
}
int ContactsBook::contacts_count=0;

// Functions Definition For Search History

void ContactsBook::search_string_contact()
{
	string str = "";
	string temp = "";
	do {
		cout << "Enter a keyword\n";
		getline(cin, str);
		temp = str;
		//spaces(temp);
		if (temp == "")
			cout << "Invalid input!!! Try again\n";
	} while (str == "");
	temp = str;
	Space(temp);
	bool isTrue = false;
	for (int i = 0; i < contacts_count; i++)
	{
		if (match_string_contact(contacts_list[i], temp))
		{
			isTrue = true;
			contacts_list[i].Print_Contact();
		}
	}
	if (!isTrue)
		cout << "No match found!!!\n";

	//Get current time and date
	std::time_t now = std::time(nullptr);
	std::tm currentTime;
	localtime_s(&currentTime, &now);

	//convert time to 12-hour format
	char timeStr[9]; // HH:MM:SS
	strftime(timeStr, sizeof(timeStr), "%I:%M %p", &currentTime);
	string Time(timeStr);

	//convert date to string
	char dateStr[11]; // DD/MM/YYYY
	strftime(dateStr, sizeof(dateStr), "%d/%m/%Y", &currentTime);
	string Date(dateStr);

	//Convert day of week to string
	char dayOfWeekStr[10]; // Day of Week
	strftime(dayOfWeekStr, sizeof(dayOfWeekStr), "%A", &currentTime);
	string DayOfWeek(dayOfWeekStr);

	search_history.set_SearchHistory_search(str, Time, DayOfWeek, Date);
	search_history.save_SearchHistory_file("Searchrecord.txt");	// is k andar jo bhi file ka name hoga whi jae ga
}
void ContactsBook::display_search_history()
{
	search_history.display_all_history();
}

void ContactsBook::display_frequent_five()
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
			//store the lines in reverse order.
			lines_in_reverse.insert(lines_in_reverse.begin(), line);
			str[count] = line;
			count++;
		}
		in.close();
	}
	else
		cout << "File not open..\n";
	for (int i = count - 1; i >= count - 21 && i >= 0; --i) {
		cout << str[i] << endl;
	}

}


bool ContactsBook::match_string_contact(Contact& contact, const string& str) {
	//Convert the provided string to lowercase for case-insensitive comparison
	string lowercaseStr = str;
	transform(lowercaseStr.begin(), lowercaseStr.end(), lowercaseStr.begin(), ::tolower);

	//concatenate all attributes into a single string for easier search
	string allAttributes = contact.GetFirstN() + " " +
		contact.GetLastN() + " " +
		contact.GetEmail() + " " +
		contact.GetMobileN() + " " +
		contact.GetAddress()->GetHouse() + " " +
		contact.GetAddress()->GetStreet() + " " +
		contact.GetAddress()->GetCity() + " " +
		contact.GetAddress()->GetCountry();
	transform(allAttributes.begin(), allAttributes.end(), allAttributes.begin(), ::tolower);

	
	lowercaseStr.erase(remove_if(lowercaseStr.begin(), lowercaseStr.end(), ::isspace), lowercaseStr.end());	//remove all spaces from the input string

	//check if the input string is substring of concatenated attributes
	if (allAttributes.find(lowercaseStr) != string::npos)   //Find function returns npos return false
		return true;

	return false;
}