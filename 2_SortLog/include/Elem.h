#pragma once
#include "ConsoleLogger.h"

class ConsoleLogger;

class Elem {
public:
	Elem();
	Elem(int const value, unsigned int const position, ConsoleLogger & logger);
    Elem(Elem const & other);
	bool operator<(Elem & other);
	Elem & operator=(Elem const & other);
    bool operator==(Elem const & other) const;
    bool operator!=(Elem const & other) const;
	unsigned int position() const;
	int value() const;
private:
	int m_value;
	unsigned int m_position;
    bool m_contained;
    ConsoleLogger * m_logger;
};
