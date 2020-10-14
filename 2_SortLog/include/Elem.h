#pragma once
#include "ConsoleLogger.h"

class Elem {
public:
	Elem();
	Elem(int const value, int const position);
	bool operator<(Elem const & other);
	Elem & operator=(Elem const & other);
	int get_value() const;
	int get_position() const;
	void set_position(unsigned int const newPosition);
private:
	int m_value;
	unsigned int m_position;
};
