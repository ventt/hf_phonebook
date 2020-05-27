#ifndef RECORDTYPES_H
#define RECORDTYPES_H

#include "Record.h"
#include <string>
#include "misc.h"
#include "Serializable.h"
#include "memtrace.h"
using std::string;

class EmailRecord : public Record {
	string emailAddress;
public:
	EmailRecord() : Record(), emailAddress("") {}
	EmailRecord(const RECORD_TYPE r, const string& emailAddr) : Record(r), emailAddress(emailAddr) {}
	virtual string record_type() const { return "Email"; };
	virtual string get_address() const { return emailAddress; };
	virtual string get_type_of_childs() const { string t = ""; return t; };
	void write(std::ofstream&) const;
	virtual bool search(const string&);
};

class ImRecord : public Record {
	IM_TYPE im_type; //typeról refactorálva im_type-ra
	string imAddress;
public:
	ImRecord() : Record(), im_type(IM_TYPE_SKYPE), imAddress("") {}
	ImRecord(const RECORD_TYPE r, const IM_TYPE t, const string& imAddr) : Record(r), im_type(t), imAddress(imAddr) {}
	virtual string record_type() const { return "IM"; };
	virtual string get_address() const { return imAddress; };
	virtual string get_type_of_childs() const;
	void write(std::ofstream&) const;
	virtual bool search(const string&);
};

class AddressRecord : public Record {
	AddressType address;
public:
	AddressRecord() : Record() {}
	AddressRecord(const RECORD_TYPE r, const AddressType addr) : Record(r), address(addr) {}
	virtual string record_type() const { return "Address"; };
	virtual string get_type_of_childs() const { string t = ""; return t; };
	virtual string get_address() const;
	void write(std::ofstream&) const;
	virtual bool search(const string&);
};

class PhoneNumberRecord : public Record {
	NUMBER_TYPE number_type;
	PhoneNumber number;
public:
	PhoneNumberRecord() : Record(), number_type(NUMBER_TYPE_MOBILE) {} //default konstruktor
	PhoneNumberRecord(RECORD_TYPE r, NUMBER_TYPE t, PhoneNumber n) : Record(r), number_type(t), number(n) {}
	virtual string record_type() const { return "Phone number"; };
	virtual string get_type_of_childs() const;
	virtual string get_address() const;
	void write(std::ofstream&) const;
	virtual bool search(const string&);
};
#endif // RECORDTYPES_H
