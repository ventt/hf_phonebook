#include "Contact.h"
#include <string>
#include <iostream>
#include "misc.h"
#include <sstream>
#include "memtrace.h"
/** \stringet kap és letrehoz egy enum phoneNumber tipusu valtozot
* \param string
* \return phoneNumber
*/
phoneNumber get_phone_number(string l) {
	phoneNumber phone_number;
	string string_int;
	std::stringstream line(l);
	std::getline(line, phone_number.countryCode, ';');
	std::getline(line, string_int, ';'); phone_number.provider = stoi(string_int);
	std::getline(line, string_int, ';'); phone_number.number = stoi(string_int);
	return phone_number;
}
/** \Stringet kap és letrehoz egy enum addressType tipusu valtozot
* \param string
* \return addressType
*/
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
/** \Parameterkent megadott filestreambe ir ki egy Contact class-t
* \param std::ofstream&
*/
void Contact::write(std::ofstream& os) const {
	os << this->name << std::endl;
	os << this->list->get_size() << std::endl;
	for (size_t i = 0; i < this->list->get_size(); i++) {
		this->list->get_data(i)->write(os);
	}
}
/** \Megvizsgalja a Contact nevében és a Contact altal tarolt adatokban, hogy elofordul-e a parameterkent kapott string, bool-al ter vissza
* \param string
* \return bool
*/
bool Contact::search(string s) {
	if (s.empty())
		return false;

	if (this->name.find(s) != std::string::npos)
		return true;

	else {
		for (size_t j = 0; j < this->get_size(); j++) {
			if (this->getRecord(j).search(s)) {
				return true;
			}
		}
	}
	return false;
}
/** \Parameterkent kapott file streambol beolvas egy Contact class-t majd a benne tarolt Recordokat is hozzafuzi a Contact list-hez
* \param std::ifstream&
*/
void Contact::read(std::ifstream& is) {
	size_t size = 0;
	is >> size;

	string l = ""; //egesz sor
	std::stringstream line(l);

	numberType number_type = Mobil;

	imType imtype = Skype;
	int type = 0;

	string string_int = "";

	int pers_or_work = 0;
	int which_record = 0;
	recordType rt = Personal;
	if (size == 0) { //üres recordList esetén
		is.ignore();
	}
	for (size_t i = 0; i < size; i++) {
		Email* mail = 0;
		IM* im = 0;
		Address* adr = 0;
		PhoneNumber* pn = 0;
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