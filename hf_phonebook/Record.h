#ifndef RECORD_H
#define RECORD_H

#include "misc.h"
//template <typename T>
class Record{
    recordType type;
public:
    Record(){type = Personal;}
    Record(recordType t) : type(t) {}
    recordType get_type() { return type; };
    void set_type(recordType t) { type = t; };
    virtual string record_type() = 0;
    virtual string get_address() = 0;
    virtual string get_type_of_childs() = 0;
    
   // virtual ~Record();

};
#endif // RECORD_H
