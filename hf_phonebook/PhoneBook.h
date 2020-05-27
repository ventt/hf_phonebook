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
	PhoneBook(const PhoneBook& pb) {
		list = new List<Contact*>();
		list->addAll(pb.list);
	}
	PhoneBook& operator=(const PhoneBook& pb) {
		if (this == &pb) return *this;
		delete list;
		list = new List<Contact*>();
		list->addAll(pb.list);
		return *this;
	};
	Contact& get(size_t s) const { return *this->list->get_data(s); };
	List<Contact*>* getList() const { return this->list; };
	size_t get_size() const { return this->list->get_size(); }
	void write(std::ofstream&) const;
	void read(std::ifstream&);
	List<size_t*>* search(const string&);
	~PhoneBook() { delete list; };
};
#endif // PHONEBOOK_H
