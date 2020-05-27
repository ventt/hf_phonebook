#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H
#include <iostream>
#include "memtrace.h"
#include <fstream>
struct Serializable {
	virtual void write(std::ofstream&) const {};
	virtual void read(std::ifstream&) {};
	virtual ~Serializable() {}
};
#endif // !SERIALIZABLE_H
