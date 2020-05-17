#include "Control.h"
#include <conio.h>
#include <stdlib.h>

int read_int_from_terminal(string command) {
	int num;
	while (std::cout << command && !(std::cin >> num)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter!" << endl;
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
	std::cout << "1. View Contacts" << " (" << number_of_contacts << ")" << endl << "2. Add Contacts" << endl << "3. Search Contact" << endl << "4. Exit" << endl;
}
void add_contact_view(Contact* ct) {
	terminal_header_view();
	cout << "Name:";
	string name = "";
	cin.ignore();
	getline(cin, name);
	ct->set_name(name);
	cout << endl;
}
void search_view() {
	terminal_header_view();
	cout << "Give the name: ";
}


void list_contacts(PhoneBook& pb) {
	for (size_t i = 0; i < pb.get_size(); i++) {
		cout << i + 1 << ":" << pb.get(i).get_name() << endl;
	}
}
void add_contact(PhoneBook* pb) {
	Contact* ct = new Contact();
	add_contact_view(ct);
	pb->getList()->add(ct);
}

void contact_view(Contact& c){
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
		cout << "Give the new name: ";
		string new_name;
		cin.ignore();
		getline(cin, new_name);
		cout << endl;
		c.set_name(new_name);
	
}

void search_contact(PhoneBook* pb) { //miakar ez lenni?
	search_view();
	string n; //searchable name
	cin.ignore();
	getline(cin, n);
	cout << endl;
	int contactNumber = pb->searchContact(n);
	if (contactNumber < 0) {
		cout << "Name was not found" << endl;
	}
	else {
		contact_view(pb->get(contactNumber));
	}
}
void edit_record_wiew(Record& r) {

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

	

	while(exit) {
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
			else if(choice == 0){
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
			getline(cin,nb.countryCode);
			
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
			cout << "1 = Skype, 2 = Zoom, 3 = Discord, 0 = back" <<endl;
			choice = read_int_from_terminal("Choice: ");
			if (choice == 1) {
				type = Skype;
			}
			else if (choice == 2) {
				type = Zoom;
			}
			else if(choice == 3){
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

void menu(PhoneBook* pb) {
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
			cout << endl; // Nézd meg kell-e ez ide
			contact_number = read_int_from_terminal("Give the contact number(0 is back): ");
			cout << endl;
			system("CLS");
			if (contact_number == 0)
				break;
			contact_view(pb->get(contact_number - 1));
			cout << "1 = Edit Contact name, 2 = Add record, 3 = Edit record, 0 = Back " << endl;
			int choice;
			choice = read_int_from_terminal("Choice: ");
			system("CLS");
			if (choice == 1) {
				edit_contact_name(pb->get(contact_number - 1));
				system("CLS");
			}
			else if (choice == 2) {
				add_record_view(pb->get(contact_number - 1));
				system("CLS");
			}
			else if (choice == 3) {
				//lesz vmi
			}
			else if(choice == 0){
				break;
			}
			else {
				cout << endl << "Invalid command!" << endl;
			}
				break;
		case add_Contact_Screen:
			terminal_header_view();
			add_contact(pb);
			break;
		case search_Contact_Screen:

			break;
		case exit_app:
			exit = turn_off;
			break;
		default:
			
			cout << endl << "Invalid command!" << endl;
			break;
			}
		}
	}
