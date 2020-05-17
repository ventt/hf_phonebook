#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include "ContactList.h"
#include "misc.h"
#include "TemplateList.h"
#include "Serializable.h"

class PhoneBook{
    List<Contact*>* list;
public:
    PhoneBook() { list = new List<Contact*>();}
    Contact& get(size_t s) const { return *this->list->get_data(s); };
    List<Contact*>* getList() { return this->list; };
    size_t get_size(){return this->list->get_size();}
    //void removeContact(Contact&);
   // void listContacts();
   // void readFromFile();
    //void writeToFile();
   int searchContact(string);
    ~PhoneBook(){};
};
#endif // PHONEBOOK_H
