#include "Contact.h"
#include <string>
#include <iostream>
#include "misc.h"
#include <sstream>
#include "memtrace.h"
phoneNumber get_phone_number(string l) {
	phoneNumber phone_number;
	string string_int;
	std::stringstream line(l);
	std::getline(line, phone_number.countryCode, ';');
	std::getline(line, string_int, ';'); phone_number.provider = stoi(string_int);
	std::getline(line, string_int, ';'); phone_number.number = stoi(string_int);
	return phone_number;
}
addressType get_address(string l) {
	addressType  address_type;
	std::stringstream line(l);
	string string_int;
	std::getline(line, address_type.country, ';');
	std::getline(line, address_type.city, ';');
	std::getline(line, address_type.street, ';');
	std::getline(line, string_int, ';'); address_type.number = stoi(string_int);
	return address_type;
}
void Contact::write(std::ofstream& os) const {
	os << this->name << std::endl;
	os << this->list->get_size() << std::endl;
	for (size_t i = 0; i < this->list->get_size(); i++) {
		this->list->get_data(i)->write(os);
	}
}
bool Contact::search(string s) {
	if (this->name.find(s) != std::string::npos) {
		return true;
	}
	else {
		for (size_t j = 0; j < this->get_size(); j++) {
			if (this->getRecord(j).search(s)) {
				return true;
			}
		}
	}
	return false;
}
void Contact::read(std::ifstream& is) {
	size_t size = 0;
	is >> size;

	string l; //egesz sor
	std::stringstream line(l);

	numberType number_type;

	imType imtype;
	int type;

	string string_int = "";

	int pers_or_work;
	int which_record;
	recordType rt;
	if (size == 0) { //üres recordList esetén
		is.ignore();
	}
	for (size_t i = 0; i < size; i++) {
		Email* mail = NULL;
		IM* im = NULL;
		Address* adr = NULL;
		PhoneNumber* pn = NULL;
		l.clear();
		line.clear();

		is >> which_record;
		is >> pers_or_work;

		if (pers_or_work == 1) {
			rt = Personal;
		}
		else {
			rt = Work;
		}

		switch (which_record)
		{
		case 1:
		{
			is.ignore();
			std::getline(is, l);
			mail = new Email(rt, l);
			this->list->add(mail);

			break;
		}
		case 2:
			is.ignore();
			std::getline(is, l);
			adr = new Address(rt, get_address(l));
			this->list->add(adr);
			break;
		case 3:
			is >> type;
			is.ignore();
			if (type == 1) {
				imtype = Skype;
			}
			else if (type == 2) {
				imtype = Zoom;
			}
			else {
				type = Discord;
			}
			std::getline(is, l);
			im = new IM(rt, imtype, l);
			this->list->add(im);
			break;
		case 4:
			is >> type;
			is.ignore();
			if (type == 1) {
				number_type = Mobil;
			}
			else if (type == 2) {
				number_type = Landline;
			}
			else {
				number_type = Satellite;
			}

			std::getline(is, l);
			pn = new PhoneNumber(rt, number_type, get_phone_number(l));
			this->list->add(pn);
			break;
		default:
			std::cout << "Unable to read the file!" << std::endl;
			break;
		}
	}
}