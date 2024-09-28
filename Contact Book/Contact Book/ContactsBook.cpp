//#include "ContactsBook.h"
//
//void ContactsBook::add_contact(const Contact& contact)
//{
//	/*
//		- Check if the list is full, if it is full call the resize function
//		- If list is not full add the contact to the end of the array
//		- (end means the place where last contact was inserted)
//		- At start it will be 0th index as no contact has been inserted before so
//		- count is zero (contacts_count member)
//		- Increment the count
//		- As inserted successfully, return 1
//	*/
//}
//
//int ContactsBook::total_contacts()
//{
//	/*
//	*	Return the total contacts currently stored
//	*/
//
//	/*
//	*	Remove this return -1; before writing your code
//	*/
//	return -1;
//}
//
//bool ContactsBook::full()
//{
//	/*
//	* Return true if list is full, false otherwise
//	*/
//
//	/*
//	*	Remove this return false; before writing your code
//	*/
//	return false;
//}
//
//void ContactsBook::resize_list()
//{
//	/*
//	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
//	*	You will allocate a temporary new array of double the current size and copy the contacts from
//	*       previous array to this array one by one, get the copy of each contact using copy_contact
//	*       function of Contact class
//	*	Delete the previous array
//	*	Assign the new temporary array to the contacts_list pointer
//	*	Updated the this->size_of_contacts with new size
//	*/
//}
//
//Contact* ContactsBook::search_contact(std::string first_name, std::string last_name)
//{
//	/*
//	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
//	*	Remove this return nullptr; before writing your code
//	*/
//	return nullptr;
//}
//
//Contact* ContactsBook::search_contact(std::string phone)
//{
//	/*
//	*	Remove this return nullptr; before writing your code
//	*/
//	return nullptr;
//}
//
//Contact* ContactsBook::search_contact(const Address& address)
//{
//	/*
//	*	Remove this return nullptr; before writing your code
//	*/
//	return nullptr;
//}
//
//ContactsBook::ContactsBook(int size_of_list)
//{
//	/*
//	*	Initialize the contacts_list array, also initialize the size and count members accordingly
//	*/
//}
//
//void ContactsBook::print_contacts_sorted(std::string choice)
//{
//	/*
//	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
//	*	Call the sort function sort_contacts_list to sort the newly created copy
//	*	This copy is created to avoid changing the original insertion order of contact list
//	*	Then print the contacts in following format:
//	*	[First Name] [Last Name] [Mobile] [Email]
//	*	Call the address print function to print address on next line
//	*/
//}
//
//void ContactsBook::sort_contacts_list(Contact* contacts_list, std::string choice)
//{
//	/*
//		You should not duplicate the code to sort based on choices
//		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
//		Sort by the fist letter of first name or last name as given in choice
//	*/
//}
//
//void ContactsBook::merge_duplicates()
//{
//	// Implement this function that finds and merges all the duplicates
//	// Duplicate means exact equal
//	// If there are three copies of a Contact, then only one should remain
//	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
//	// 9 contacts will be left; and the this->contacts_count of list will 9
//	// At the end display contacts merged, and count of merged contacts
//}
//
//
//void ContactsBook::load_from_file(std::string file_name)
//{
//	/*
//	*	Read contacts back from file in the same format
//	*	Read the contacts_count, and run a loop for this contacts_count and read the
//	*	contacts in the same format as you stored
//	*	Add them to contact book (this.add_contact function can be used)
//	*	Finally, close the file
//	*/
//}
//
//
//void ContactsBook::save_to_file(std::string file_name)
//{
//	/*
//	*	In this function you will store all the contacts to a file
//	*	On first line store contacts_count
//	*	On next lines store contacts in the following format:
//	*       2 lines for each contact
//	*       On oneline write contact attributes(except address) in comma separated format. On second line
//	*	store address atributes in the same format
//	*	first_name,last_name,mobile_number,email_address
//	*	house,street,city,country
//	*	Close the file
//	*/
//}
