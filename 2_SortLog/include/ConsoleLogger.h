#pragma once

#include <vector>

class Elem;

class ConsoleLogger {
public:
	ConsoleLogger(std::vector<Elem> const & vector);
	void print_comparsion(Elem const & left, Elem const & right);
private:
	std::vector<Elem> m_vector; // Using copy because sort might modify original vector
};