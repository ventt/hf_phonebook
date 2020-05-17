#ifndef CONTACTLIST_H
#define CONTACTLIST_H

#include "Contact.h"
#include "misc.h"
struct contactList{
    Contact *contact;
    contactList *next;
};
#endif // CONTACTLIST_H
