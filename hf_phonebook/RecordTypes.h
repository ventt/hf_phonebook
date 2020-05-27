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
	AddressType* address;
public:
	AddressRecord() : Record() {
		address = new AddressType();
	}
	AddressRecord(const AddressRecord& ar) {
		address = (AddressType*)memcpy(new AddressType(), ar.address, sizeof(AddressType));
	}
	AddressRecord& operator=(const AddressRecord& ar) {
		if (this == &ar) return *this;
		delete address;
		address = (AddressType*)memcpy(new AddressType(), ar.address, sizeof(AddressType));
		return *this;
	}
	AddressRecord(const RECORD_TYPE r, AddressType* addr) : Record(r), address(addr) {}

	virtual string record_type() const { return "Address"; };
	virtual string get_type_of_childs() const { string t = ""; return t; };
	virtual string get_address() const;
	void write(std::ofstream&) const;
	virtual bool search(const string&);
	~AddressRecord() {
		delete address;
	}
};

class PhoneNumberRecord : public Record {
	NUMBER_TYPE number_type;
	PhoneNumber* number;
public:
	PhoneNumberRecord() : Record(), number_type(NUMBER_TYPE::NUMBER_TYPE_MOBILE) {} //default konstruktor
	PhoneNumberRecord(const RECORD_TYPE r, const NUMBER_TYPE t, PhoneNumber* n) : Record(r), number_type(t), number(n) {}
	PhoneNumberRecord(const PhoneNumberRecord& pnr) {
		number = (PhoneNumber*)memcpy(new PhoneNumber(), pnr.number, sizeof(PhoneNumber));
	}
	PhoneNumberRecord& operator=(const PhoneNumberRecord& pnr) {
		if (this == &pnr) return *this;
		delete number;
		number = (PhoneNumber*)memcpy(new PhoneNumber(), pnr.number, sizeof(PhoneNumber));
		return *this;
	}
	virtual string record_type() const { return "Phone number"; };
	virtual string get_type_of_childs() const;
	virtual string get_address() const;
	void write(std::ofstream&) const;
	virtual bool search(const string&);
	~PhoneNumberRecord() {
		delete number;
	}
};
#endif // RECORDTYPES_H
