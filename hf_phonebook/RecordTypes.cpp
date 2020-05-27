#include "RecordTypes.h"
#include "memtrace.h"
/** \Stringkent visszaadja a PhoneNumber class tipusat, kiirasnal segit
* \return string
*/
string PhoneNumberRecord::get_type_of_childs() const {
	string t;
	if (number_type == NUMBER_TYPE::NUMBER_TYPE_MOBILE) {
		t = "Mobil";
		return t;
	}
	else if (number_type == NUMBER_TYPE::NUMBER_TYPE_LANDLINE) {
		t = "Landline";
		return t;
	}
	else {
		t = "Satellite";
		return t;
	}
}
/** \Stringkent visszaadja a IM tipusat, kiirasnal segit
* \return string
*/
string ImRecord::get_type_of_childs() const {
	string t;
	if (im_type == IM_TYPE_SKYPE) {
		t = "Skype";
		return t;
	}
	else if (im_type == IM_TYPE_ZOOM) {
		t = "Zoom";
		return t;
	}
	else {
		t = "Discord";
		return t;
	}
}
/** \Stringkent visszaadja az enum addressType-ban tarolt adatot, kiirasnal segit
* \return string
*/
string AddressRecord::get_address() const {
	string t;
	t = t + address->country + " " + address->city + " " + address->street + " " + std::to_string(address->number);
	return t;
}
/** \Stringkent visszaadja az enum numberType-ban tarolt adatot, kiirasnal segit
*	\string
*/
string PhoneNumberRecord::get_address() const {
	string t;
	t = number->countryCode + std::to_string(number->provider) + std::to_string(number->number);
	return t;
}
/** \Parameterkent megadott filestreambe ki ir egy Email classt
* \param std::ofstream&
*/
void EmailRecord::write(std::ofstream& os) const {
	os << 1 << std::endl;
	if (this->type == RECORD_TYPE_PERSONAL) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}
	os << this->emailAddress << std::endl;
};
/** \Parameterkent megadott filestreambe ki ir egy Address classt
* \param std::ofstream&
*/
void AddressRecord::write(std::ofstream& os) const {
	os << 2 << std::endl;
	if (this->type == RECORD_TYPE_PERSONAL) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}
	os << this->address->country << ";" << this->address->city << ";" << this->address->street << ";" << this->address->number << std::endl;
};
/** \Parameterkent megadott filestreambe ki ir egy IM classt
* \param std::ofstream&
*/
void ImRecord::write(std::ofstream& os) const {
	os << 3 << std::endl;

	if (this->get_type() == RECORD_TYPE_PERSONAL) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}

	if (this->im_type == IM_TYPE_SKYPE) {
		os << 1 << std::endl;  // 1 = Skype
	}
	else if (this->im_type == IM_TYPE_ZOOM) {
		os << 2 << std::endl; // 2 = Zoom
	}
	else {
		os << 3 << std::endl; // 3 = Discord
	}
	os << this->imAddress << std::endl;
};
/** \Parameterkent megadott filestreambe ki ir egy PhoneNumber classt
* \param std::ofstream&
*/
void PhoneNumberRecord::write(std::ofstream& os) const {
	os << 4 << std::endl;

	if (this->type == RECORD_TYPE_PERSONAL) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}

	if (this->number_type == NUMBER_TYPE_MOBILE) {
		os << 1 << std::endl;  //1 = mobil
	}
	else if (this->number_type == NUMBER_TYPE_LANDLINE) {
		os << 2 << std::endl; //2 = landline
	}
	else {
		os << 3 << std::endl; //3 = Satelite
	}
	os << this->number->countryCode << ";" << this->number->provider << ";" << this->number->number << std::endl;
};
/** \Parameterkent kap egy stringet, es megvizsgalja hogy az Email class altal tarolt adatokban elofordul-e, bool-al ter vissza
* \param string
* \return bool
*/
bool EmailRecord::search(const string& s) {
	if (this->emailAddress.find(s) != std::string::npos) {
		return true;
	}
	return false;
}
/** \Parameterkent kap egy stringet, es megvizsgalja hogy az Address class altal tarolt adatokban elofordul-e, bool-al ter vissza
* \param string
* \return bool
*/
bool AddressRecord::search(const string& s) {
	if (this->address->country.find(s) != std::string::npos ||
		this->address->city.find(s) != std::string::npos ||
		this->address->street.find(s) != std::string::npos ||
		std::to_string(this->address->number).find(s) != std::string::npos) {
		return true;
	}
	return false;
}
/** \Parameterkent kap egy stringet, es megvizsgalja hogy az IM class altal tarolt adatokban elofordul-e, bool-al ter vissza
* \param string
* \return bool
*/
bool ImRecord::search(const string& s) {
	if (this->imAddress.find(s) != std::string::npos) {
		return true;
	}
	return false;
}
/** \Parameterkent kap egy stringet, es megvizsgalja hogy az PhoneNumber class altal tarolt adatokban elofordul-e, bool-al ter vissza
* \param string
* \return bool
*/
bool PhoneNumberRecord::search(const string& s) {
	if (this->number->countryCode.find(s) != std::string::npos ||
		std::to_string(this->number->provider).find(s) != std::string::npos ||
		std::to_string(this->number->number).find(s) != std::string::npos) {
		return true;
	}
	return false;
}