#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <iostream>
#include "memtrace.h"
#include <fstream>
struct serializable {
	virtual void write(std::ofstream&) const {};
	virtual void read(std::ifstream&) {};
	virtual ~serializable() {}
};
#endif // !SERIALIZABLE_H
