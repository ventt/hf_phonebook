#include "PhoneBook.h"

int PhoneBook::searchContact(string n) {
	for (size_t i = 0; i < this->get_size(); i++) {
		if (n.compare(this->get(i).get_name())) {
			return i;
		}
	}
	return -1;
};
void PhoneBook::write(std::ofstream& os) const {
	os << this->list->get_size() << std::endl;
	for (size_t i = 0; i < this->list->get_size(); i++) {
		this->list->get_data(i)->write(os);
	}
}
void PhoneBook::read(std::ifstream& is) {
	string name;
	int size = 0;
	is >> size;
	is.ignore();

	for (size_t i = 0; i < size; i++) {
		std::getline(is, name);
		Contact* ct = new Contact(name);
		ct->read(is);
		this->list->add(ct);
	}
}