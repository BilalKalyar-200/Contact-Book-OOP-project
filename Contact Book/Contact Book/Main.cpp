#include<iostream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include"ContactsBook.h"
//#include "Address.h"
//#include "Contact.h"
//#include "ContactsBook.h"
using namespace std;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void menu() {
    string menu_option1 = "1.Create a contacts list with given size (input size from user)";
    string menu_option2 = "2.Add New Contact";
    string menu_option3 = "3.Merge Duplicates";
    string menu_option4 = "4.Store To File (input file name)";
    string menu_option5 = "5.Load From File (input file name)";
    string menu_option6 = "6.Print Contacts Sorted (first_name or last_name)";
    string menu_option7 = "7.Print Contacts";
    string menu_option8 = "8.Search Contacts (by first name, last name, or phone number)";
    string menu_option9 = "9.Display Count of Contacts";
    string menu_option10 = "10.Use Advanced functions";
    string menu_option11 = "11.Exit";
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
    string wall = "  ==============================";

    cout << wall << endl;
    cout << "||                             ||" << endl;
    cout << "|| Welcome to My Contact Book  ||" << endl;
    cout << "||                             ||" << endl;
    cout << wall << endl;
    cout << "|| " << left << setw(38) << menu_option1 << " ||" << endl;
    cout << "|| " << left << setw(38) << menu_option2 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option3 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option4 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option5 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option6 << "               ||" << endl;
    cout << "|| " << left << setw(38) << menu_option7 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option8 << "   ||" << endl;
    cout << "|| " << left << setw(38) << menu_option9 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option10 << "                          ||" << endl;
    cout << "|| " << left << setw(38) << menu_option11 << "                          ||" << endl;
    cout << wall<<wall << endl;
    SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_BLUE);
}
void AdvancedMenu()
{
    SetConsoleTextAttribute(h, 8);
    cout << "These functions are added for extended project\n";
    cout << "1. Advanced Print\n";
    cout << "2. Search By a Keyword\n";
    cout << "3. Display Search History\n";
    cout << "4. Display Frequent Five\n";
    cout << "5. Add Group\n";
    cout << "6. Remove Group\n";
    cout << "7. Add Contact to Group\n";
    cout << "8. Search contact Group\n";
    cout << "9. Display Group\n";
    cout << "10. Store group data to file\n";
    cout << "11. Load group from file\n";
    SetConsoleTextAttribute(h, 8);
}
void print_searched(Contact* search)
{
    cout << "Contact Found\n";
    cout << "First Name: " << search->GetFirstN() << endl;
    cout << "Last Name: " << search->GetLastN() << endl;
    cout << "Mobile Number: " << search->GetMobileN() << endl;
    cout << "Email Address: " << search->GetEmail() << endl;
    cout << "House no: " << search->GetAddress()->GetHouse() << endl;
    cout << "Street no: " << search->GetAddress()->GetStreet() << endl;
    cout << "City Name: " << search->GetAddress()->GetCity() << endl;
    cout << "Country Name: " << search->GetAddress()->GetCountry() << endl;
}
void trimmed(std::string& line) {
    std::getline(cin, line);

    // Trim leading whitespace
    line.erase(line.begin(), std::find_if(line.begin(), line.end(), [](unsigned char ch) {
        return !std::isspace(ch);
        }));
    // Trim trailing whitespace
    line.erase(std::find_if(line.rbegin(), line.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
        }).base(), line.end());
}
void spaces(string& str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}
bool only_numbers(const string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false; // Found a non-digit character
        }
    }
    return true; // All characters are digits
}

void Space(std::string& line) {
    // Remove all spaces using erase-remove idiom
    line.erase(std::remove_if(line.begin(), line.end(), [](unsigned char ch) {
        return std::isspace(ch);
        }), line.end());
}
int main() {
    int size;
    int ch;
    string file_name, search_by;

    ContactsBook* contactBook = new ContactsBook;
   
    cout << "Enter size of the contacts list: ";
    cin >> size;
    try {
        do {
            menu();
            cout << "Your choice: ";
            cin >> ch;

            if (ch == 1) {
                contactBook = new ContactsBook(size);
            }
            else if (ch == 2)
            {
                Contact* contact = new Contact;
                cin >> *contact;
                contactBook->add_contact(contact);
                contact = NULL;
                delete contact;
            }
            else if (ch == 3)
            {
                contactBook->merge_duplicates();
            }
            else if (ch == 4)
            {
                cout << "Enter file name to store contacts: ";
                cin >> file_name;
                contactBook->save_to_file(file_name);
            }
            else if (ch == 5) {
                cout << "Enter file name to load contacts: ";
                cin >> file_name;
                contactBook->load_from_file(file_name);
            }
            else if (ch == 6) {
                string choice;
                cout << "Enter sorting ch (first_name(1) or last_name(2)): ";
                cin >> choice;
                contactBook->print_contacts_sorted(choice);
            }
            else if (ch == 7) {
                contactBook->print();
            }
            else if (ch == 8)
            {
                SetConsoleTextAttribute(h, 9);
                cout << "1.By First Name and Last Name\n"
                    << "2,By Phone Number\n"
                    << "3.By Address\n"
                    << "How would you like to search: ";
                SetConsoleTextAttribute(h, 9);
                char ch1; cin >> ch1;
                if (ch1 == '1')
                {
                    cout << "Enter First name: ";
                    string temp; cin >> temp;
                    cout << "Enter Last name: ";
                    string temp2; cin >> temp2;
                    Contact* search = contactBook->search_contact(temp, temp2);
                    if (search != nullptr)
                    {
                        print_searched(search);
                    }
                    else cout << "Contact not found with given name\n";
                }
                else if (ch1 == '2')
                {
                    cout << "Enter phone number: ";
                    string temp; cin >> temp;
                    Contact* search = contactBook->search_contact(temp);
                    if (search != nullptr)
                    {
                        print_searched(search);
                    }
                    else cout << "Contact not found with given phone number\n";
                }
                else if (ch1 == '3')
                {
                    SetConsoleTextAttribute(h, 11);
                    string temp1, temp2, temp3, temp4;
                    cout << "Enter house no: ";
                    cin >> temp1;
                    cout << "Enter street no: ";
                    cin >> temp2;
                    cout << "Enter city name: ";
                    cin >> temp3;
                    cout << "Enter country name: ";
                    cin >> temp4;
                    Address add(temp1, temp2, temp3, temp4);
                    Contact* search = contactBook->search_contact(add);
                    if (search != nullptr)
                    {
                        print_searched(search);
                    }
                    else cout << "Contact not found with given address\n";
                    SetConsoleTextAttribute(h, 11);
                }
            }
            else if (ch == 9)
            {
                SetConsoleTextAttribute(h, 14);
                cout << endl << "Number of contacts added are: " << contactBook->total_contacts() << endl << endl;
                SetConsoleTextAttribute(h, 14);
            }
            else if (ch == 10)
            {
                system("cls");
                AdvancedMenu();
                int ch3; cin >> ch3;
                if (ch3 == 1)
                    contactBook->AdvancedPrint();
                else if (ch3 == 2)
                    contactBook->search_string_contact();
                else if (ch3 == 3)
                    contactBook->display_search_history();
                else if (ch3 == 4)
                    contactBook->display_frequent_five();
                else if (ch3 == 5)
                    contactBook->add_group();
                else if (ch3 == 6)
                    contactBook->remove_group();
                else if (ch3 == 7)
                    contactBook->add_contact_to_group();
                else if (ch3 == 8)
                    contactBook->search_contact_group();
                else if (ch3 == 9)
                    contactBook->display_groups();
                else if (ch3 == 10)
                    contactBook->StoreGroupToFile();
                else if (ch3 == 11)
                    contactBook->LoadGroupFromFile();
                else throw string("invalid choice\n");
            }
            else if (ch == 11) {
                SetConsoleTextAttribute(h, 14);
                cout << "Exiting...\n";
                SetConsoleTextAttribute(h, 14);
                break;
            }
            else
            {
                throw out_of_range("invalid choice\n");
                continue;
            }
            cout << "Press enter to clear the screen";
            cin.ignore();
            cin.get();
            system("cls");
        } while (true);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
        cin.clear();
    }
    delete contactBook;
    system("pause");
    return 0;
}