#include "Elem.h"

Elem::Elem(int const value, int const position) {
	m_value = value;
	m_position = position;
}

bool Elem::operator<(Elem const & other) {
	ElemObserver::comparsion_happened(*this, other);
	return m_value < other.m_value;
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