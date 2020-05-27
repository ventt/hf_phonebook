#ifndef CONTACT_H
#define CONTACT_H

#include "misc.h"
#include <string>
#include "Record.h"
#include "RecordTypes.h"
#include "TemplateList.h"
#include "Serializable.h"
#include "memtrace.h"
using std::string;

class Contact : public Serializable {
	string  name;
	List<Record*>* list;
public:
	Contact() : name("") { list = new List<Record*>(); }; //inicializáló listában adjuk meg a default értéket
	Contact(string n) : name(n) { list = new List<Record*>(); };
	Contact(string n, List<Record*>* l) : name(n), list(l) {};
	Contact(const Contact& c) {
		this->name = c.name;
		this->list = new List<Record*>();
		this->list->addAll(c.list);
	}
	Contact& operator=(const Contact& c) {
		if (this == &c) return *this;
		delete list;
		this->name = c.name;
		this->list = new List<Record*>();
		this->list->addAll(c.list);
		return *this;
	};
	string get_name() { return name; };
	void set_name(string n) { name = n; };
	size_t get_size() { return this->list->get_size(); };
	Record& getRecord(size_t s) { return *list->get_data(s); };
	List<Record*>* get_list() { return list; };
	void write(std::ofstream&) const;
	void read(std::ifstream&);
	bool search(string);
	~Contact() { delete list; };
};
#endif // CONTACT_H
