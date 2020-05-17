#ifndef CONTACT_H
#define CONTACT_H

#include "RecordList.h"
#include "misc.h"
#include <string>
#include "TemplateList.h"
using std::string;

class Contact{
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

    ~Contact();
};
#endif // CONTACT_H
