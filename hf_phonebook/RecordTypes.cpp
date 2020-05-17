#include "RecordTypes.h"



  
string PhoneNumber::get_type_of_childs() {
    string t;
    if (number_type == Mobil) {
        t = "Mobil";
        return t;
    }
    else if (number_type == Landline) {
        t = "Landline";
        return t;
    }
    else {
        t = "Satellite";
        return t;
    }
}



string IM::get_type_of_childs() {
    string t;
    if (type == Skype) {
        t = "Skype";
        return t;
    }
    else if (type == Zoom) {
        t = "Zoom";
        return t;
    }
    else {
        t = "Discord";
        return t;
    }
}
string Address::get_address() {
    string t;
    t = t + address.country + " " + address.city + " " + address.street + " " + std::to_string(address.number);
    return t;
}
string PhoneNumber::get_address() {
    string t;
    t = number.countryCode + std::to_string(number.provider) + std::to_string(number.number);
    return t;
}
    
