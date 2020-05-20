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

class Contact : public serializable {
	string  name;
	List<Record*>* list;
public:
	Contact() { list = new List<Record*>(); name = ""; };
	Contact(string n) : name(n) { list = new List<Record*>(); };
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
