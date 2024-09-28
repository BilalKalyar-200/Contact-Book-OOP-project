#pragma once

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB
#include"List.h"

#include "Address.h"


class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	int count_view;


public:
	int id;
	void SetId(int);
	void SetId2(int);
	int GetId();
	Address* address=new Address;
	bool equals(Contact contact);
	Contact* copy_contact();
	Contact input();
	friend std::istream& operator>>(std::istream& input, Contact& contact);
	Contact();
	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
	
	void set_count_view(int count);
	int get_count_view() const;
	void Print_Contact();

	void SetFirstN(std::string F_N);
	void SetLastN(std::string L_N);
	void SetMobileN(std::string M_N);
	void SetEmail(std::string E_A);
	void SetAddress(Address* address);
	std::string GetFirstN();
	std::string GetLastN();
	std::string GetMobileN();
	std::string GetEmail();
	Address* GetAddress();
	~Contact() {
		delete address;
	}
};
