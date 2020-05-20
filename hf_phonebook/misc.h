#ifndef MISC_H
#define MISC_H
#include <string>
#include <iostream>
/*enumok �s egy�b t�pusok amikre sz�ks�ge lehet a programnak*/
using std::string;

enum recordType
{
	Personal,
	Work
};
enum imType
{
	Skype,
	Zoom,
	Discord
};
enum numberType
{
	Mobil,
	Landline,
	Satellite
};
struct addressType
{
	string country;
	string city;
	string street;
	int number;
};
struct phoneNumber
{
	string countryCode;
	int provider;
	int number;
};

#endif
