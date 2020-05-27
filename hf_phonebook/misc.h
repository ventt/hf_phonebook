#ifndef MISC_H
#define MISC_H
#include <string>
#include <iostream>
/*enumok és egyéb típusok amikre szüksége lehet a programnak*/
using std::string;

enum RECORD_TYPE
{
	RECORD_TYPE_PERSONAL,
	RECORD_TYPE_WORK
};
enum IM_TYPE
{
	IM_TYPE_SKYPE,
	IM_TYPE_ZOOM,
	IM_TYPE_DISCORD
};
enum NUMBER_TYPE
{
	NUMBER_TYPE_MOBILE,
	NUMBER_TYPE_LANDLINE,
	NUMBER_TYPE_SATELLITE
};
struct AddressType
{
	string country = "";
	string city = "";
	string street = "";
	int number = 0;
};
struct PhoneNumber
{
	string countryCode = "";
	int provider = 0;
	int number = 0;
};

#endif
