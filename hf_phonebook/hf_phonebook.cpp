// hf_phonebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "Control.h"
int main()
{
    
	PhoneBook* pb = new PhoneBook();
	Contact* ct = new Contact();
	Email* mail = new Email(Personal, "faszjancsi@gmail.com");
	Email* mailWork = new Email(Work, "ifj.faszjancsi@gmail.com");
	
	phoneNumber pn;
	pn.countryCode = "+36";
	pn.provider = 20;
	pn.number = 2507624;
	PhoneNumber* number = new PhoneNumber(Personal, Mobil, pn);
	IM* im = new IM(Work, Zoom, "fosceg.hu/1121");
	addressType adrr;
	adrr.country = "Hungary";
	adrr.city = "Budapest";
	adrr.street = "Plébánia utca";
	adrr.number = 36;
	Address* adr = new  Address(Personal, adrr);
	ct->set_name("Faszikam");
	ct->get_list()->add(mail);
	ct->get_list()->add(mailWork);
	ct->get_list()->add(number);
	ct->get_list()->add(im);
	ct->get_list()->add(adr);
	pb->getList()->add(ct);
	menu(pb);


   
    
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
