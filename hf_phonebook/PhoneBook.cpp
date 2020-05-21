#include "PhoneBook.h"
/*Parameterkent kap egy stringet, es megvizsgalja hogy az PhoneBook class altal tarolt Contact lista elemeiben elofordul-e a parameterkent kapott string es
a talatokbol keszit egy size_t listat.
@param string
@return List<size_t*>*
*/
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
/*Kiirja az egesz PhoneBook class allapotat a file streamre
@param std::ofstream&
*/
void PhoneBook::write(std::ofstream& os) const {
	os << this->list->get_size() << std::endl;
	for (size_t i = 0; i < this->list->get_size(); i++) {
		this->list->get_data(i)->write(os);
	}
}
/*Beolvas egy egesz PhoneBook classt a file streamrol
@param std::ofstream&
*/
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