#include "PhoneBook.h"

List<size_t*>* PhoneBook::search(string s) {
	List<size_t*>* result = new List<size_t*>();

	Node<Contact*>* it = this->list->get_head();
	for (size_t i = 0; it != NULL; it = it->next, i++)
	{
		if (it->data->search(s)) {
			size_t* p = new size_t;
			*p = i;
			result->add(p);
		}
	}

	return result;
}

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

	for (int i = 0; i < size; i++) {
		std::getline(is, name);
		Contact* ct = new Contact(name);
		ct->read(is);
		this->list->add(ct);
	}
}