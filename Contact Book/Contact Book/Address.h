#pragma once
#include <iostream>
#include <string>

class Address {
private:
	std::string house;
	std::string street;
	std::string city;
	std::string country;

public:
	void input();
	bool equals(const Address& address);
	void print_address();
	Address copy_address();
	void SetHouse(std::string h);
	void SetStreet(std::string s);
	void SetCity(std::string city);
	void SetCountry(std::string c);
	std::string GetHouse();
	std::string GetStreet();
	std::string GetCity();
	std::string GetCountry();
	Address(std::string house, std::string street, std::string city, std::string country);
	Address() {}
};
