#include "Address.h"

/*
*	Implement a constructor that initializes all the address parts
*
*/
Address::Address(std::string house, std::string street, std::string city, std::string country) {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}
void Address::SetHouse(std::string h) {
}



/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/



/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)
{
	/*
	* Todo
	*/
	return false;
}

void Address::print_address()
{
	/*
	*	Print address on one line as
	*	House, Street, City, Country
	*/
}

Address Address::copy_address()
{
	/*
		return a copy of this
	*/
}
