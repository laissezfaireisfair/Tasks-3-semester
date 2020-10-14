#include "Elem.h"

Elem::Elem() {
	m_value = -1;
	m_position = 0;
	m_contained = false;
	m_logger = nullptr;
}

Elem::Elem(int const value, unsigned int const position, ConsoleLogger & logger) {
	m_value = value;
	m_position = position;
	m_contained = true;
	m_logger = &logger;
}

Elem::Elem(Elem const & other) {
    m_value = other.m_value;
    m_position = other.m_position;
    m_contained = other.m_contained;
    m_logger = other.m_logger;
}

bool Elem::operator<(Elem & other) {
	if (m_value < other.m_value) { // Comparison successful => it will be swapped (I hope)
		if (m_contained && other.m_contained)
            m_logger->print_comparsion(*this, other);
		unsigned int tempPos = m_position;
		m_position = other.m_position;
		other.m_position = tempPos;
		return true;
	}
	return false;
}

Elem & Elem::operator=(Elem const & other) {
	if (&other == this)
		return *this;
	m_value = other.m_value;
	m_position = other.m_position;
	m_contained = other.m_contained;
	m_logger = other.m_logger;
	return *this;
}

bool Elem::operator==(Elem const & other) const {
    return m_value == other.m_value;
}

bool Elem::operator!=(Elem const & other) const {
    return m_value != other.m_value;
}

unsigned int Elem::position() const {
	return m_position;
}

int Elem::value() const {
	return m_value;
}