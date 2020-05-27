#ifndef CONTROL_H
#define CONTROL_H
#include "PhoneBook.h"
#include "RecordTypes.h"
#include <string>
#include <iostream>
#include "memtrace.h"
#include "misc.h"
using namespace std;

enum MENU {
	MENU_LIST_CONTACT,//0
	MENU_ADD_CONTACT, //1
	MENU_SEARCH_CONTACT, //2
	MENU_SAVE, //3
	MENU_EXIT //4
};

enum ADD_RECORD {
	ADD_RECORD_EXIT,
	ADD_RECORD_PHONE_NUMBER,
	ADD_RECORD_ADDRESS,
	ADD_RECORD_EMAIL,
	ADD_RECORD_IM
};

enum EXIT_TYPE {
	EXIT_TYPE_EXIT,
	EXIT_TYPE_RETURN
};
void get_save(PhoneBook&);
void menu(PhoneBook*);
#endif // !CONTROL_H
