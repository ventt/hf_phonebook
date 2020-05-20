#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include "Contact.h"
#include "misc.h"
#include "TemplateList.h"
#include "Serializable.h"
#include "memtrace.h"
#include <fstream>

class PhoneBook {
	List<Contact*>* list;
public:
	PhoneBook() { list = new List<Contact*>(); }
	Contact& get(size_t s) const { return *this->list->get_data(s); };
	List<Contact*>* getList() { return this->list; };
	size_t get_size() { return this->list->get_size(); }
	void write(std::ofstream&) const;
	void read(std::ifstream&);
	int searchContact(string);
	~PhoneBook() { delete list; };
};
#endif // PHONEBOOK_H
