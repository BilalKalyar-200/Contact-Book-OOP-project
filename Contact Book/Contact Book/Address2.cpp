#include "Address.h"

/*
*	Implement a constructor that initializes all the address parts
*
*/
Address::Address(std::string house="", std::string street="", std::string city="", std::string country="") {
	this->house = house;
	this->street = street;
	this->city = city;
	this->country = country;
}



/*
*	Implement getter/setters for all the member variables of Address. Also declare them in the Address.h header file
*
*/
void Address::SetHouse(std::string h) {
	this->house = h;
}
void Address::SetStreet(std::string s) {
	this->street = s;
}
void Address::SetCity(std::string city) {
	this->city = city;
}
void Address::SetCountry(std::string c) {
	this->country = c;
}
std::string Address::GetHouse() {
	return house;
}
std::string Address::GetStreet() {
	return street;
}
std::string Address::GetCity() {
	return city;
}
std::string Address::GetCountry() {
	return country;
}



/*
*	Implement the equals function that takes an Address object and checks if it is equal to
*	current object refered by (this pointer)
*	Two addresses are equal if all the attributes of addresses are equal
*/
bool Address::equals(const Address& address)
{
	if (this->house == address.house && this->street == address.street && this->city == address.city && this->country == address.country) {
		return true;
	}
	else return false;
}

void Address::print_address()
{
	/*
	*	Print address on one line as
	*	House, Street, City, Country
	*/
	std::cout << "House: " << house << " Street: " << street << " City: " << city << " Country: " << country << std::endl;
}

Address Address::copy_address()
{
	/*
		return a copy of this
	*/
	Address temp_obj(this->house, this->street,this->city,this->country);		//creating new object and passing paramters
	return temp_obj;
}
void Address::input()
{
	std::cout << "Enter House no. ";
	std::cin >> house;
	std::cout << "Enter street no. ";
	std::cin >> street;
	std::cout<<"Enter name of city: ";
	std::cin >> city;
	std::cout << "Enter name of country: ";
	std::cin >> country;
}