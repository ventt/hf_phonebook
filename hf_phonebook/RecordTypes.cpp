#include "RecordTypes.h"
#include "memtrace.h"

string PhoneNumber::get_type_of_childs() const {
	string t;
	if (number_type == Mobil) {
		t = "Mobil";
		return t;
	}
	else if (number_type == Landline) {
		t = "Landline";
		return t;
	}
	else {
		t = "Satellite";
		return t;
	}
}

string IM::get_type_of_childs() const {
	string t;
	if (type == Skype) {
		t = "Skype";
		return t;
	}
	else if (type == Zoom) {
		t = "Zoom";
		return t;
	}
	else {
		t = "Discord";
		return t;
	}
}
string Address::get_address() const {
	string t;
	t = t + address.country + " " + address.city + " " + address.street + " " + std::to_string(address.number);
	return t;
}
string PhoneNumber::get_address() const {
	string t;
	t = number.countryCode + std::to_string(number.provider) + std::to_string(number.number);
	return t;
}

void Email::write(std::ofstream& os) const {
	os << 1 << std::endl;
	if (this->type == Personal) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}
	os << this->emailAddress << std::endl;
};

void Address::write(std::ofstream& os) const {
	os << 2 << std::endl;
	if (this->type == Personal) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}
	os << this->address.country << ";" << this->address.city << ";" << this->address.street << ";" << this->address.number << std::endl;
};

void IM::write(std::ofstream& os) const {
	os << 3 << std::endl;

	if (this->get_type() == Personal) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}

	if (this->type == Skype) {
		os << 1 << std::endl;  // 1 = Skype
	}
	else if (this->type == Zoom) {
		os << 2 << std::endl; // 2 = Zoom
	}
	else {
		os << 3 << std::endl; // 3 = Discord
	}
	os << this->imAddress << std::endl;
};

void PhoneNumber::write(std::ofstream& os) const {
	os << 4 << std::endl;

	if (this->type == Personal) {
		os << 1 << std::endl;
	}
	else {
		os << 2 << std::endl;
	}

	if (this->number_type == Mobil) {
		os << 1 << std::endl;  //1 = mobil
	}
	else if (this->number_type == Landline) {
		os << 2 << std::endl; //2 = landline
	}
	else {
		os << 3 << std::endl; //3 = Satelite
	}
	os << this->number.countryCode << ";" << this->number.provider << ";" << this->number.number << std::endl;
};

bool Email::search(string s) {
	if (this->emailAddress.find(s) != std::string::npos) {
		return true;
	}
	return false;
}
bool Address::search(string s) {
	if (this->address.country.find(s) != std::string::npos ||
		this->address.city.find(s) != std::string::npos ||
		this->address.street.find(s) != std::string::npos ||
		std::to_string(this->address.number).find(s) != std::string::npos) {
		return true;
	}
	return false;
}
bool IM::search(string s) {
	if (this->imAddress.find(s) != std::string::npos) {
		return true;
	}
	return false;
}
bool PhoneNumber::search(string s) {
	if (this->number.countryCode.find(s) != std::string::npos ||
		std::to_string(this->number.provider).find(s) != std::string::npos ||
		std::to_string(this->number.number).find(s) != std::string::npos) {
		return true;
	}
	return false;
}