#ifndef RECORDLIST_H
#define RECORDLIST_H

#include "Record.h"
#include "misc.h"

struct recordList{
    Record *record;
    recordList *next;
};
#endif // RECORDLIST_H
