#ifndef CONTROL_H
#define CONTROL_H
#include "PhoneBook.h"
#include "RecordTypes.h"
#include <string>
#include <iostream>
#include "memtrace.h"
#include "misc.h"
using namespace std;

enum menu_types {
	list_contact_Screen,//0
	add_Contact_Screen, //1
	search_Contact_Screen, //2
	save_screen, //3
	exit_app //4
};
enum exit_value {
	turn_off,
	stay
};
void get_save(PhoneBook&);
void menu(PhoneBook*);
#endif // !CONTROL_H
