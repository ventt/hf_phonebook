// hf_phonebook.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Control.h"
#include <iostream>
#include <fstream>
#include <sstream>
int main()
{
	/*Nagy H�zi feladat
	K�sz�tette: Sz�ll Adri�n Bence
	Neptun k�d: BPE3HL
	*/
	PhoneBook* pb = new PhoneBook();
	get_save(*pb);
	menu(pb);

	return 0;
}