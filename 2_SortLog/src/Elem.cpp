#include "Elem.h"

Elem::Elem() {
	m_value = -1;
	m_position = 0;
	m_contained = false;
}

Elem::Elem(int const value, unsigned int const position) {
	m_value = value;
	m_position = position;
	m_contained = true;
}

bool Elem::operator<(Elem & other) {
	if (m_value < other.m_value) { // Comparsion succecful => it will be swapped (I hope)
		if (m_contained && other.m_contained)
			ConsoleLogger::print_comparsion(*this, other);
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
	return *this;
}

unsigned int Elem::get_position() const {
	return m_position;
}