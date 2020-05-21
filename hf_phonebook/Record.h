#ifndef RECORD_H
#define RECORD_H

#include "misc.h"
#include "memtrace.h"
#include "Serializable.h"
class Record : public serializable {
protected:
	recordType type;
public:
	Record() { type = recordType::Personal; } //Default konstruktor a Record tipusat enum recordType = Personal-ra allitja
	Record(recordType t) : type(t) {}
	recordType get_type() const { return type; }; //Visszater a Record tipusaval enum recordType = Personal/Work
	void set_type(recordType t) { type = t; }; //Setter: beallitja a Record tipusat enum recordType = Personal/Work
	virtual string record_type() const = 0;
	virtual string get_address() const = 0;
	virtual string get_type_of_childs() const = 0;
	virtual void write(std::ofstream&) const = 0;
	virtual bool search(string) = 0;
	virtual ~Record() {};
};
#endif // RECORD_H
