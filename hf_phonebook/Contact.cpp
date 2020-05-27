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
PhoneNumber get_phone_number(string l) {
	PhoneNumber phone_number;
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
AddressType get_address(string l) {
	AddressType  address_type;
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

	NUMBER_TYPE number_type = NUMBER_TYPE_MOBILE;

	IM_TYPE imtype = IM_TYPE_SKYPE;
	int type = 0;

	string string_int = "";

	int pers_or_work = 0;
	int which_record = 0;
	RECORD_TYPE rt = RECORD_TYPE_PERSONAL;
	if (size == 0) { //üres recordList esetén
		is.ignore();
	}
	for (size_t i = 0; i < size; i++) {
		EmailRecord* mail = 0;
		ImRecord* im = 0;
		AddressRecord* adr = 0;
		PhoneNumberRecord* pn = 0;
		l.clear();
		line.clear();

		is >> which_record;
		is >> pers_or_work;

		if (pers_or_work == 1) {
			rt = RECORD_TYPE_PERSONAL;
		}
		else {
			rt = RECORD_TYPE_WORK;
		}

		switch (which_record)
		{
		case 1:
		{
			is.ignore();
			std::getline(is, l);
			mail = new EmailRecord(rt, l);
			this->list->add(mail);
			break;
		}
		case 2:
			is.ignore();
			std::getline(is, l);
			adr = new AddressRecord(rt, get_address(l));
			this->list->add(adr);
			break;
		case 3:
			is >> type;
			is.ignore();
			if (type == 1) {
				imtype = IM_TYPE_SKYPE;
			}
			else if (type == 2) {
				imtype = IM_TYPE_ZOOM;
			}
			else {
				type = IM_TYPE_DISCORD;
			}
			std::getline(is, l);
			im = new ImRecord(rt, imtype, l);
			this->list->add(im);
			break;
		case 4:
			is >> type;
			is.ignore();
			if (type == 1) {
				number_type = NUMBER_TYPE_MOBILE;
			}
			else if (type == 2) {
				number_type = NUMBER_TYPE_LANDLINE;
			}
			else {
				number_type = NUMBER_TYPE_SATELLITE;
			}

			std::getline(is, l);
			pn = new PhoneNumberRecord(rt, number_type, get_phone_number(l));
			this->list->add(pn);
			break;
		default:
			std::cout << "Unable to read the file!" << std::endl;
			break;
		}
	}
}