#include <iostream>
#include "ConsoleLogger.h"
#include "Elem.h"

ConsoleLogger::ConsoleLogger(std::vector<Elem> const & vector) {
	m_vector = vector;
}

void ConsoleLogger::print_comparsion(Elem const & left, Elem const & right) {
	std::swap(m_vector[left.position()], m_vector[right.position()]);
	for (auto & elem : m_vector)
		std::cout << elem.value() << " ";
	std::cout << std::endl;
}