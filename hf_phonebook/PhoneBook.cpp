#include "PhoneBook.h"

    

    
    //void PhoneBook::removeContact(Contact &c){};
   // void PhoneBook::listContacts(){};
   // void PhoneBook::readFromFile(){};
    //void PhoneBook::writeToFile(){};
   int PhoneBook::searchContact(string n){
       for (size_t i = 0; i < this->get_size() ; i++) {
           if (n.compare(this->get(i).get_name())) {
               return i;
           }
       }
       return -1;
   };
