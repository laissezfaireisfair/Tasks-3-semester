#pragma once
#include "ConsoleLogger.h"

class ConsoleLogger;

class Elem {
public:
	Elem();
	Elem(int const value, unsigned int const position, ConsoleLogger & logger);
	bool operator<(Elem & other);
	Elem & operator=(Elem const & other);
	unsigned int position() const;
	int value() const;
private:
	int m_value;
	unsigned int m_position;
    bool m_contained;
    ConsoleLogger * m_logger;
};
