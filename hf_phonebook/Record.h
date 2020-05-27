#ifndef RECORD_H
#define RECORD_H

#include "misc.h"
#include "memtrace.h"
#include "Serializable.h"
class Record : public Serializable {
protected:
	RECORD_TYPE type;
public:
	Record() { type = RECORD_TYPE::RECORD_TYPE_PERSONAL; } //Default konstruktor a Record tipusat enum recordType = Personal-ra allitja
	Record(const RECORD_TYPE t) : type(t) {}
	RECORD_TYPE get_type() const { return type; }; //Visszater a Record tipusaval enum recordType = Personal/Work
	void set_type(const RECORD_TYPE t) { type = t; }; //Setter: beallitja a Record tipusat enum recordType = Personal/Work
	virtual string record_type() const = 0;
	virtual string get_address() const = 0;
	virtual string get_type_of_childs() const = 0;
	virtual void write(std::ofstream&) const = 0;
	virtual bool search(const string&) = 0;
	virtual ~Record() {};
};
#endif // RECORD_H
