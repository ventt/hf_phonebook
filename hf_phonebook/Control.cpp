#include "Control.h"
#include <stdlib.h>
#include <fstream>
#include "memtrace.h"

// Menu staterol atnevezve, scope javitva
enum MENU {
	MENU_LIST_CONTACT,//0
	MENU_ADD_CONTACT, //1
	MENU_SEARCH_CONTACT, //2
	MENU_SAVE, //3
	MENU_EXIT //4
};

enum ADD_RECORD {
	ADD_RECORD_EXIT,
	ADD_RECORD_PHONE_NUMBER,
	ADD_RECORD_ADDRESS,
	ADD_RECORD_EMAIL,
	ADD_RECORD_IM
};

enum EXIT_TYPE {
	EXIT_TYPE_EXIT,
	EXIT_TYPE_RETURN
};

/** \Elmenti a jelenlegi allapotot
* \param PhoneBook&
*/
void save(PhoneBook& pb) {
	string file = "phonebook_save.txt";
	std::ofstream os(file);
	pb.write(os);
}
/** \Fajlbol kiolvassa az elmentet allapotot
* \param PhoneBook&
*/
void get_save(PhoneBook& pb) {
	string file = "phonebook_save.txt";
	std::ifstream is(file);
	pb.read(is);
}
/** \szabvanyos bemenetrol olvas ki Integer-t, addig probalkozik amig nem Integert kap, megadhato stringkent a szoveg amivel bekeri az adatot
* \param string
*/
int read_int_from_terminal(const string& command) {
	int num = 0;

	while (std::cout << command && !(std::cin >> num)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter!" << std::endl;
	}
	return num;
}
/** \Szabványos kimenetre kiirja a fejlecet
*/
void terminal_header_view() {
	std::cout <<
		"PPPPPP  hh                               BBBBB                 kk     " << endl <<
		"PP   PP hh       oooo  nn nnn    eee     BB   B   oooo   oooo  kk  kk" << endl <<
		"PPPPPP  hhhhhh  oo  oo nnn  nn ee   e    BBBBBB  oo  oo oo  oo kkkkk" << endl <<
		"PP      hh   hh oo  oo nn   nn eeeee     BB   BB oo  oo oo  oo kk kk" << endl <<
		"PP      hh   hh  oooo  nn   nn  eeeee    BBBBBB   oooo   oooo  kk  kk " << endl << endl;
}
/** \Szabvanyos kimenetre kiirja a Contactokat
* \param size_t
*/
void menu_view(const size_t number_of_contacts) {
	terminal_header_view();
	std::cout << "1. View Contacts" << " (" << number_of_contacts << ")" << endl << "2. Add Contacts" << endl << "3. Search Contact" << endl << "4. Save" << endl << "5. Exit" << endl;
}
/** \Contact hozzadasara szolgal, formalisan kiir a szabvanyos kimenetre
* \param Contact*
*/
void add_contact_view(Contact* ct) {
	cout << "Name:";
	string name = "";
	cin.ignore();
	getline(cin, name);
	ct->set_name(name);
	cout << endl;
}
/** \Szabvanyos kimenetre kilistazza a PhoneBook altal tarolt Contactokat
*	\param PhoneBook&
*/
void list_contacts(const PhoneBook& pb) {
	for (size_t i = 0; i < pb.get_size(); i++) {
		cout << i + 1 << ":" << pb.get(i).get_name() << " (" << pb.get(i).get_size() << ")" << endl;
	}
}
/** \Letrehoz es hozzafuz a PhoneBook altal tarolt listara egy Contactot
* \param PhoneBook&
*/
void add_contact(const PhoneBook& pb) {
	Contact* ct = new Contact();
	add_contact_view(ct);
	pb.getList()->add(ct);
}
/** \Formalisan kiir egy Contact-ot
* \param Contact&
*/
void contact_view(Contact& c) {
	cout << c.get_name() << ":" << endl;
	for (size_t i = 0; i < c.get_size(); i++) {
		cout << i + 1 << "->";
		if (c.getRecord(i).get_type() == RECORD_TYPE_PERSONAL) {
			cout << "Personal" << endl;
		}
		else {
			cout << "Work" << endl;
		}
		cout << c.getRecord(i).record_type() << ": ";
		cout << c.getRecord(i).get_type_of_childs() << endl;
		cout << c.getRecord(i).get_address() << endl << endl;
	}
}
/** \Formalisan kiirja az "edit contact name" ablakot es atirja a nevet a Contact-ban
* \param Contact&
*/
void edit_contact_name(Contact& c) {
	cout << "Old name: " << c.get_name() << endl;;
	cout << "Give the new name: ";
	string new_name = "";
	cin.ignore();
	getline(cin, new_name);
	cout << endl;
	if (new_name != "")
		c.set_name(new_name);
}
/** \Letrehoz egy enum recordType valtozot es visszater vele
* \return recordType
*/
RECORD_TYPE set_record_type() {
	RECORD_TYPE rt = RECORD_TYPE_PERSONAL;

	cout << "1 = Personal, 2 = Work" << endl;
	const int choice = read_int_from_terminal("Command: ");
	if (choice == 1) {
		rt = RECORD_TYPE_PERSONAL;
	}
	else if (choice == 2) {
		rt = RECORD_TYPE_WORK;
	}
	else {
		cout << endl << "Invalid command, Type is set default(Personal)" << endl;
		rt = RECORD_TYPE_PERSONAL;
	}
	return rt;
}
/** \Letrehoz egy recordot amit hozzafuz a parameterkent kapott Contact listajahoz
* \Contact&
*/
void add_record_view(Contact& c) {
	for (int exit = EXIT_TYPE_RETURN; exit;) {
		system("CLS");
		contact_view(c);

		NUMBER_TYPE nt = NUMBER_TYPE_MOBILE;
		PhoneNumber nb;
		AddressType at;
		IM_TYPE type = IM_TYPE_SKYPE;
		string mail = "";
		string addr = "";
		RECORD_TYPE recordt = RECORD_TYPE_PERSONAL;
		AddressRecord* ad = 0;
		PhoneNumberRecord* nn = 0;
		EmailRecord* m = 0;
		ImRecord* im = 0;

		cout << "1 = Phone Number, 2 = Address, 3 = Email, 4 = IM, 0 = back" << endl;
		int choice = read_int_from_terminal("Choice: ");

		switch (choice)
		{
		case ADD_RECORD_PHONE_NUMBER: //Telefonszám record hozzáadása
			recordt = set_record_type();
			cout << "1 = Landline, 2 = Satellite, 3 = Mobil, 0 = back" << endl;
			choice = read_int_from_terminal("Choice: ");
			if (choice == 1) {
				nt = NUMBER_TYPE_LANDLINE;
			}
			else if (choice == 2) {
				nt = NUMBER_TYPE_SATELLITE;
			}
			else if (choice == 0) {
				exit = EXIT_TYPE_EXIT;
				break;
			}
			else if (choice == 3) {
				nt = NUMBER_TYPE_MOBILE;
			}
			else {
				cout << endl << "Invalid command!";
				break;
			}

			cout << "Country code(+36): ";
			cin.ignore();
			getline(cin, nb.countryCode);

			nb.provider = read_int_from_terminal("Provider number: ");
			nb.number = read_int_from_terminal("Number: ");

			nn = new PhoneNumberRecord(recordt, nt, nb);
			c.get_list()->add(nn);

			break;
		case ADD_RECORD_ADDRESS: //Cím record hozzáadása
			recordt = set_record_type();
			cout << "Country: ";
			cin.ignore();
			getline(cin, at.country);
			cout << " city: ";
			getline(cin, at.city);
			cout << " street: ";
			getline(cin, at.street);
			at.number = read_int_from_terminal("House number: ");
			ad = new AddressRecord(recordt, at);
			c.get_list()->add(ad);

			break;
		case ADD_RECORD_EMAIL: //Email record hozzáadása
			recordt = set_record_type();
			cout << "Email: ";
			cin.ignore();
			getline(cin, mail);
			m = new EmailRecord(recordt, mail);
			c.get_list()->add(m);

			break;
		case ADD_RECORD_IM: // im hozzáadás
			recordt = set_record_type();
			cout << "1 = Skype, 2 = Zoom, 3 = Discord, 0 = back" << endl;
			choice = read_int_from_terminal("Choice: ");
			if (choice == 1) {
				type = IM_TYPE_SKYPE;
			}
			else if (choice == 2) {
				type = IM_TYPE_ZOOM;
			}
			else if (choice == 3) {
				type = IM_TYPE_DISCORD;
			}
			else if (choice == 0) {
				exit = EXIT_TYPE_EXIT;
			}
			else {
				cout << endl << "Invalid command!, IM type set as Default(Skype)" << endl;
				break;
			}
			cout << endl << "Address: ";
			cin.ignore();
			getline(cin, addr);
			im = new ImRecord(recordt, type, addr);
			c.get_list()->add(im);

			break;
		case ADD_RECORD_EXIT:  //Kilépés
			exit = EXIT_TYPE_EXIT;
			break;
		default: //Nem jó parancs
			cout << endl << "Invalid command!" << endl;
			break;
		}
	}
}
/** \Kilistazza a parameterkent kapott int es PhoneBook& altal behatarolt Contact-ban tarolt elemeket, majd
* \param int, PhoneBook&
*/
void list_contact_view(const int contact_number, const PhoneBook& pb) { //const pb
	contact_view(pb.get(contact_number - 1));
	cout << "1 = Edit Contact name, 2 = Add record, 3 = Delete record, 4 = Delete contact, 0 = Back " << endl;
	int choice = read_int_from_terminal("Choice: ");
	system("CLS");
	if (choice == 1) {
		edit_contact_name(pb.get(contact_number - 1));
		system("CLS");
	}
	else if (choice == 2) {
		add_record_view(pb.get(contact_number - 1));
		system("CLS");
	}
	else if (choice == 3) { //delete record
		contact_view(pb.get(contact_number - 1));
		choice = read_int_from_terminal("Which record: ");
		if (choice - 1 > static_cast<int>(pb.get_size()) || choice - 1 < 0) {
			cout << "Invalid choice" << endl;
		}
		else {
			if (choice > static_cast<int>(pb.get(contact_number - 1).get_size()) || choice <= 0) {
				cout << "Invalid choice!" << endl;
			}
			else {
				pb.get(contact_number - 1).get_list()->remove_from_list(choice - 1);
			}
		}
	}
	else if (choice == 4) {
		cout << "Are you sure that you want to delete the whole contact?" << endl;
		choice = read_int_from_terminal("1 = yes, 2 = no\nSure?: ");
		if (choice == 1)
			pb.getList()->remove_from_list(contact_number - 1);
	}
	else if (choice == 0) {
		//itt kilép
	}
	else {
		cout << endl << "Invalid command!" << endl;
	}
}
/** \Kereso ablak formalis megvalósítása
* \param PhoneBook&
*/
void search_view(PhoneBook& pb) {
	string s = "";
	terminal_header_view();
	cout << "Search: ";
	cin.ignore();
	getline(cin, s);

	List<size_t*>* list = pb.search(s);
	if (list->get_size() == 0) { // <= -> ==
		cout << "Not found.";
		system("CLS");
	}
	else {
		cout << "List of matching items: " << endl;
		int i = 0;
		for (Node<size_t*>* it = list->get_head(); it != NULL; it = it->next, i++) {
			cout << i + 1 << ": ";
			cout << pb.get(*it->data).get_name();
			cout << endl;
		}
		cout << endl;
		int selected = read_int_from_terminal("Select: ");
		system("CLS");
		list_contact_view(selected - 1, pb);
	}
	delete list;
}
/** \A Program fomenuje, mondhatni a main
* \param pb
*/
void menu(PhoneBook& pb) {
	for (int exit = EXIT_TYPE_RETURN; exit;) {
		system("CLS");
		menu_view(pb.get_size());

		const int menu_state = read_int_from_terminal("Command: ");

		system("CLS");
		switch (menu_state - 1)
		{
		case MENU_LIST_CONTACT:
			terminal_header_view();
			list_contacts(pb);
			int contact_number;

			contact_number = read_int_from_terminal("Give the contact number(0 is back): ");

			system("CLS");
			if (contact_number == 0 || contact_number - 1 > static_cast<int>(pb.get_size()))
				break;
			list_contact_view(contact_number, pb);
			break;
		case MENU_ADD_CONTACT:
			terminal_header_view();
			add_contact(pb);
			break;
		case MENU_SEARCH_CONTACT:
			search_view(pb);
			break;
		case MENU_EXIT:
			cout << "Save?" << endl << "(For any other command, save is default)" << endl;
			if (read_int_from_terminal("1 = yes, 2 = no\nCommand: ") != 2) { //choice el lett hagyva
				save(pb);
			}
			exit = EXIT_TYPE_EXIT;
			break;
		case MENU_SAVE:
			save(pb);
			break;
		default:

			cout << endl << "Invalid command!" << endl;
			break;
		}
	}
}