#include "Contact.h"

/*
*	Implement a constructor that initializes all the Contact parts, including address. Call the setter to set values
*	as they have the logic to check correct input
*	Declaration is given in Contact.h
*/
Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address) {
	SetFirstN(first_name);
	SetLastN(last_name);
	SetMobileN(mobile_number);
	SetEmail(email_address);
	SetAddress(address);
}

/*
*	Implement getter/setters for all the member variables of Contact. Also declare them in the Contact.h header file
*	In each setter, do not set value if string is empty ("" 0 size).
*   Check in phone number setter, Phone number must be 11 digits
*/
void Contact::SetFirstN(std::string F_N) {
	this->first_name = F_N;
}
void Contact::SetLastN(std::string L_N) {
	this->last_name = L_N;
}
void Contact::SetMobileN(std::string M_N)
{
		this->mobile_number = M_N;
}
void Contact::SetEmail(std::string E_A) {
		this->email_address = E_A;
}
void Contact::SetAddress(Address* address)
{
	if (address != nullptr)
		this->address = address;
}
std::string Contact::GetFirstN() {
	return first_name;
}
std::string Contact::GetLastN() {
	return last_name;
}
std::string Contact::GetMobileN() {
	return mobile_number;
}
std::string Contact::GetEmail() {
	return email_address;
}
Address* Contact::GetAddress() {
	return address;
}

void Contact::SetId(int id_)
{
	id = id_;
	id++;
}
void Contact::SetId2(int id_)
{
	id = id_;
}
int Contact::GetId()
{
	return id;
}
Contact Contact::input()
{
	std::cout << "Enter first name: ";
	std::cin >> first_name;
	std::cout << "Enter last name: ";
	std::cin >> last_name;
	std::cout << "Enter mobile number: ";
	std::cin >> mobile_number;
	std::cout << "Enter email address: ";
	std::cin >> email_address;
	this->address->input();
	return Contact(first_name, last_name, mobile_number, email_address, address);
}
Contact::Contact() {

}
/*
*	Implement the equals function(as declared in header file) that takes a
*   Contact object and checks if it is equal to current object refered by (this pointer).
*   Compare all the attributes.
*   For comparing address of contact you can call the equals function of the Address object;
*   For example: this.address.equals
*/
bool Contact::equals(Contact contact) {
	if (this->first_name == contact.first_name && this->last_name == contact.last_name && this->mobile_number == contact.mobile_number && this->email_address == contact.email_address && this->address->equals(*(contact.address))) {
		//using * before contact.address beacuse we have address pointer and to send it as normal object we have to dereference it
		return true;
	}
	else return false;
}

Contact* Contact::copy_contact()
{
	/*
		Return a new object(deep copy of "this"[due to Address pointer, which should also be copied])
	*/
	Contact* temp = new Contact;


	temp->first_name = this->first_name;
	temp->last_name = this->last_name;
	temp->mobile_number = this->mobile_number;
	temp->email_address = this->email_address;
	Address* copied_address = new Address();
	temp->address = copied_address;

	return temp;
}
std::istream& operator>>(std::istream& input, Contact& contact) {
    std::string temp;

    std::cout << "Enter first name: ";
    input >> temp;
    while (temp == "") {
		throw std::string("Enter valid name: ");
        input >> temp;
    }
    contact.SetFirstN(temp);

	std::cout << "Enter last name: ";
    input >> temp;
    while (temp == "") {
		throw std::string("Enter valid name: ");
        input >> temp;
    }
    contact.SetLastN(temp);

	std::cout << "Enter mobile number: ";
    input >> temp;
    while (temp.length() != 11) {
		throw std::string("Enter 11 digits: ");
        input >> temp;
    }
    contact.SetMobileN(temp);

	std::cout << "Enter Email: ";
    input >> temp;
    while (temp == "") {
		throw std::string("Enter valid email: ");
        input >> temp;
    }
    contact.SetEmail(temp);

	std::cout << "Enter House number: ";
    input >> temp;
    contact.GetAddress()->SetHouse(temp);

	std::cout << "Enter street number: ";
    input >> temp;
    contact.GetAddress()->SetStreet(temp);

	std::cout << "Enter city name: ";
    input >> temp;
    contact.GetAddress()->SetCity(temp);

	std::cout << "Enter Country name: ";
    input >> temp;
    contact.GetAddress()->SetCountry(temp);

    return input;
}

void Contact::set_count_view(int count)
{
	count_view = count;
}

int Contact::get_count_view() const
{
	return count_view;
}

void Contact::Print_Contact() {
	std::cout << "  Contact ID: " << id << std::endl;
	std::cout << "  Name:     " << GetFirstN() << " " << GetLastN() << std::endl;
	std::cout << "  Email:    " << GetEmail() << std::endl;
	std::cout << "  Mobile:   " << GetMobileN() << std::endl;
	std::cout << "  Address:  " << std::endl;
	std::cout << "              House: " << GetAddress()->GetHouse() << std::endl;
	std::cout << "              Street: " << GetAddress()->GetStreet() << std::endl;
	std::cout << "              City: " << GetAddress()->GetCity() << std::endl;
	std::cout << "              Country: " << GetAddress()->GetCountry() << std::endl;
	std::cout << std::endl;
}