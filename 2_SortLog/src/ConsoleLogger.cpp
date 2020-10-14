#include <iostream>
#include "ConsoleLogger.h"
#include "Elem.h"

ConsoleLogger::ConsoleLogger() {
	m_vector = std::vector<Elem>();
}

void ConsoleLogger::initialise(std::vector<Elem> const & vector) {
    m_vector = vector;
    print_vec();
}

void ConsoleLogger::print_comparsion(Elem const & left, Elem const & right) {
	std::swap(m_vector[left.position()], m_vector[right.position()]);
	print_vec();
}

bool ConsoleLogger::is_vector_same(std::vector<Elem> const & vector) const {
    if (vector.size() != m_vector.size())
        return false;
    for (unsigned int i = 0; i < vector.size(); ++i)
        if (vector[i] != m_vector[i])
            return false;
    return true;
}

void ConsoleLogger::print_vec() const {
    for (auto & elem : m_vector)
        std::cout << elem.value() << " ";
    std::cout << std::endl;
}