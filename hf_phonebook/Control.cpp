#include "Control.h"
#include <stdlib.h>
#include <fstream>
#include "memtrace.h"
void save(PhoneBook& pb) {
	string file = "phonebook_save.txt";
	std::ofstream os(file);
	pb.write(os);
}
void get_save(PhoneBook& pb) {
	string file = "phonebook_save.txt";
	std::ifstream is(file);
	pb.read(is);
}
int read_int_from_terminal(string command) {
	int num;

	while (std::cout << command && !(std::cin >> num)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter!" << std::endl;
	}
	return num;
}
void terminal_header_view() {
	std::cout <<
		"PPPPPP  hh                               BBBBB                 kk     " << endl <<
		"PP   PP hh       oooo  nn nnn    eee     BB   B   oooo   oooo  kk  kk" << endl <<
		"PPPPPP  hhhhhh  oo  oo nnn  nn ee   e    BBBBBB  oo  oo oo  oo kkkkk" << endl <<
		"PP      hh   hh oo  oo nn   nn eeeee     BB   BB oo  oo oo  oo kk kk" << endl <<
		"PP      hh   hh  oooo  nn   nn  eeeee    BBBBBB   oooo   oooo  kk  kk " << endl << endl;
}
void menu_view(size_t number_of_contacts) {
	terminal_header_view();
	std::cout << "1. View Contacts" << " (" << number_of_contacts << ")" << endl << "2. Add Contacts" << endl << "3. Search Contact" << endl << "4. Save" << endl << "5. Exit" << endl;
}
void add_contact_view(Contact* ct) {
	cout << "Name:";
	string name = "";
	cin.ignore();
	getline(cin, name);
	ct->set_name(name);
	cout << endl;
}

void list_contacts(PhoneBook& pb) {
	for (size_t i = 0; i < pb.get_size(); i++) {
		cout << i + 1 << ":" << pb.get(i).get_name() << " (" << pb.get(i).get_size() << ")" << endl;
	}
}
void add_contact(PhoneBook* pb) {
	Contact* ct = new Contact();
	add_contact_view(ct);
	pb->getList()->add(ct);
}

void contact_view(Contact& c) {
	cout << c.get_name() << ":" << endl;
	for (size_t i = 0; i < c.get_size(); i++) {
		cout << i + 1 << "->";
		if (c.getRecord(i).get_type() == Personal) {
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
void edit_contact_name(Contact& c) {
	cout << "Old name: " << c.get_name() << endl;;
	cout << "Give the new name: ";
	string new_name;
	cin.ignore();
	getline(cin, new_name);
	cout << endl;
	if (new_name != "")
		c.set_name(new_name);
}

recordType set_record_type() {
	recordType recordt;
	int choice;
	cout << "1 = Personal, 2 = Work" << endl;
	choice = read_int_from_terminal("Command: ");
	if (choice == 1) {
		recordt = Personal;
	}
	else if (choice == 2) {
		recordt = Work;
	}
	else {
		cout << endl << "Invalid command, Type is set default(Personal)" << endl;
		recordt = Personal;
	}
	return recordt;
}
void add_record_view(Contact& c) {
	int choice;
	int exit = stay;

	while (exit) {
		system("CLS");
		contact_view(c);

		numberType nt;
		phoneNumber nb;
		addressType at;
		imType type = Skype;
		string mail;
		string addr;
		recordType recordt;
		Address* ad;
		PhoneNumber* nn;
		Email* m;
		IM* im;

		cout << "1 = Phone Number, 2 = Address, 3 = Email, 4 = IM, 0 = back" << endl;
		choice = read_int_from_terminal("Choice: ");

		switch (choice)
		{
		case 1: //Telefonszám record hozzáadása
			recordt = set_record_type();
			cout << "1 = Landline, 2 = Satellite, 3 = Mobil, 0 = back" << endl;
			choice = read_int_from_terminal("Choice: ");
			if (choice == 1) {
				nt = Landline;
			}
			else if (choice == 2) {
				nt = Satellite;
			}
			else if (choice == 0) {
				exit = turn_off;
				break;
			}
			else if (choice == 3) {
				nt = Mobil;
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

			nn = new PhoneNumber(recordt, nt, nb);
			c.get_list()->add(nn);

			break;
		case 2: //Cím record hozzáadása
			recordt = set_record_type();
			cout << "Country: ";
			cin.ignore();
			getline(cin, at.country);
			cout << " city: ";
			getline(cin, at.city);
			cout << " street: ";
			getline(cin, at.street);
			at.number = read_int_from_terminal("House number: ");
			ad = new Address(recordt, at);
			c.get_list()->add(ad);

			break;
		case 3: //Email record hozzáadása
			recordt = set_record_type();
			cout << "Email: ";
			cin.ignore();
			getline(cin, mail);
			m = new Email(recordt, mail);
			c.get_list()->add(m);

			break;
		case 4: // im hozzáadás
			recordt = set_record_type();
			cout << "1 = Skype, 2 = Zoom, 3 = Discord, 0 = back" << endl;
			choice = read_int_from_terminal("Choice: ");
			if (choice == 1) {
				type = Skype;
			}
			else if (choice == 2) {
				type = Zoom;
			}
			else if (choice == 3) {
				type = Discord;
			}
			else if (choice == 0) {
				exit = turn_off;
			}
			else {
				cout << endl << "Invalid command!, IM type set as Default(Skype)" << endl;
				break;
			}
			cout << endl << "Address: ";
			cin.ignore();
			getline(cin, addr);
			im = new IM(recordt, type, addr);
			c.get_list()->add(im);

			break;
		case 0:  //Kilépés
			exit = turn_off;
			break;
		default: //Nem jó parancs
			cout << endl << "Invalid command!" << endl;
			break;
		}
	}
}
void list_contact_view(int contact_number, PhoneBook& pb) {
	contact_view(pb.get(contact_number - 1));
	cout << "1 = Edit Contact name, 2 = Add record, 3 = Delete record, 4 = Delete contact, 0 = Back " << endl;
	int choice;
	choice = read_int_from_terminal("Choice: ");
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
		if (choice - 1 > pb.get_size() || choice - 1 < 0) {
			cout << "Invalid choice" << endl;
		}
		else {
			if (choice > pb.get(contact_number - 1).get_size() || choice <= 0) {
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
List<Contact*>* search(string s, PhoneBook& pb) {
	List<Contact*>* return_list = new List<Contact*>();
	for (size_t i = 0; i < pb.get_size(); i++) {
		if (pb.get(i).search(s)) {
			return_list->add(&pb.get(i));
		}
	}
	return return_list;
}

void search_view(PhoneBook& pb) {
	string s;
	terminal_header_view();
	cout << "Search: ";
	getline(cin, s);
	cin.ignore();
	List<Contact*>* list;
	list = search(s, pb);
	if (list->get_size() <= 0) {
		cout << "Not found.";
		system("CLS");
	}
	else {
		for (size_t i = 0; i < list->get_size(); i++) {
			cout << i + 1 << ".Result:" << endl;
			cout << list->get_data(i)->get_name();
			cout << endl;
		}
		cout << endl;
		int selected = read_int_from_terminal("Select: ");
		system("CLS");
		list_contact_view(selected, pb);
	}
	delete list;
}
void menu(PhoneBook* pb) {
	int choice = 1;
	int menu_state = 0;
	int exit = stay;

	while (exit) {
		system("CLS");
		menu_view(pb->get_size());

		menu_state = read_int_from_terminal("Command: ");

		system("CLS");
		switch (menu_state - 1)
		{
		case list_contact_Screen:
			terminal_header_view();
			list_contacts(*pb);
			int contact_number;

			contact_number = read_int_from_terminal("Give the contact number(0 is back): ");

			system("CLS");
			if (contact_number == 0 || contact_number - 1 > pb->get_size())
				break;
			list_contact_view(contact_number, *pb);
			break;
		case add_Contact_Screen:
			terminal_header_view();
			add_contact(pb);
			break;
		case search_Contact_Screen:
			search_view(*pb);
			break;
		case exit_app:
			cout << "Save?" << endl << "(For any other command, save is default)" << endl;
			choice = read_int_from_terminal("1 = yes, 2 = no\nCommand: ");
			if (choice != 2) {
				save(*pb);
			}
			exit = turn_off;
			break;
		case save_screen:
			save(*pb);
			break;
		default:

			cout << endl << "Invalid command!" << endl;
			break;
		}
	}
}