#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include "PhoneBook.h"
#include "RecordTypes.h"
#include <string>
#include <iostream>
using namespace std;
enum menu_types {
	list_contact_Screen,//0
	add_Contact_Screen, //1
	search_Contact_Screen, //2
	exit_app //3
};
enum exit_value {
	turn_off,
	stay
};
void terminal_header_view();
void menu_view(size_t number_of_contacts);
void add_contact_view(Contact* ct);
void search_view();
void menu(PhoneBook*);
void add_contact(PhoneBook*);
void search_contact(PhoneBook*);
void list_contacts(PhoneBook&);
void contact_view(Contact&);

#endif // !CONTROL_H

