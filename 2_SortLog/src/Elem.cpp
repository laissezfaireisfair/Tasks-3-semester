#include "Elem.h"

Elem::Elem() {
	m_value = -1;
	m_position = 0;
}

Elem::Elem(int const value, int const position) {
	m_value = value;
	m_position = position;
}

bool Elem::operator<(Elem const & other) {
	ConsoleLogger::print_comparsion(*this, other);
	if (m_value < other.m_value) { // Comparsion succecful => it will be swapped (I hope)
		unsigned int tempPos = m_position;
		m_position = other.m_position;
		other.m_position = tempPos;
		return true;
	}
	return false;
}

Elem & Elem::operator=(Elem const & other) {
	m_value = other.m_value;
	m_position = other.m_position;
	return *this;
}

int Elem::get_value() const {
	return m_value;
}

int Elem::get_position() const {
	return m_position;
}

void Elem::set_position(unsigned int const newPosition) {
	m_position = newPosition;
}