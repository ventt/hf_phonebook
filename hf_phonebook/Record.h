#ifndef RECORD_H
#define RECORD_H

#include "misc.h"
#include "memtrace.h"
#include "Serializable.h"
class Record : public serializable {
protected:
	recordType type;
public:
	Record() { type = recordType::Personal; }
	Record(recordType t) : type(t) {}
	recordType get_type() { return type; };
	void set_type(recordType t) { type = t; };
	virtual string record_type() = 0;
	virtual string get_address() = 0;
	virtual string get_type_of_childs() = 0;
	virtual void write(std::ofstream&) const = 0;
	virtual bool search(string) = 0;
	virtual ~Record() {};
};
#endif // RECORD_H
