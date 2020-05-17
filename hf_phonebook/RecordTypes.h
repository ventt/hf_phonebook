#ifndef RECORDTYPES_H
#define RECORDTYPES_H

#include "Record.h"
#include <string>
#include "misc.h"
using std::string;

class Email : public Record{
string emailAddress;
public:
    Email() : Record() {}
    Email(recordType r, string emailAddr) : Record(r), emailAddress(emailAddr) {}
    virtual string record_type() { return "Email"; };
    virtual string get_address() { return emailAddress; };
    virtual string get_type_of_childs() { string t = ""; return t; };
    
    
    ~Email();
};

class IM : public Record{
imType type;
string imAddress;
public:
    IM() : Record() {}
    IM(recordType r,imType t, string imAddr) : Record(r), type(t), imAddress(imAddr) {}
    virtual string record_type() { return "IM"; };
    virtual string get_address() { return imAddress; };
    virtual string get_type_of_childs();
    

    ~IM();
};

class Address : public Record{
addressType address;
public:
    Address() : Record() {}
    Address(recordType r, addressType addr) : Record(r), address(addr) {}
    virtual string record_type() { return "Address"; };
    virtual string get_type_of_childs() { string t = ""; return t; };
    virtual string get_address();
    
    ~Address();
};

class PhoneNumber : public Record{
numberType number_type;
phoneNumber number;
public:
    PhoneNumber() : Record() {}
    PhoneNumber(recordType r, numberType t, phoneNumber n) : Record(r), number_type(t), number(n) {}
    virtual string record_type() { return "Phone number"; };
    virtual string get_type_of_childs();
    virtual string get_address();
    ~PhoneNumber();
};
#endif // RECORDTYPES_H
