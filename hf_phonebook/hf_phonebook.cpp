// hf_phonebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Control.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main()
{
	/*Nagy Házi feladat
	Készítette: Széll Adrián Bence
	Neptun kód: BPE3HL
	*/
	PhoneBook* pb = new PhoneBook();
	get_save(*pb);
	menu(pb);

	return 0;
}