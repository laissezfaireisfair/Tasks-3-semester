#pragma once
#include "ConsoleLogger.h"

class Elem {
public:
	Elem();
	Elem(int const value, unsigned int const position);
	bool operator<(Elem & other);
	Elem & operator=(Elem const & other);
	unsigned int get_position() const;
private:
	int m_value;
	unsigned int m_position;
    bool m_contained;
};
