#pragma once

#include <vector>

class Elem;

class ConsoleLogger {
public:
	ConsoleLogger();
	void initialise(std::vector<Elem> const & vector);
	void print_comparsion(Elem const & left, Elem const & right);
	bool is_vector_same(std::vector<Elem> const & vector) const;
private:
    void print_vec() const;
	std::vector<Elem> m_vector; // Using copy because sort might modify original vector
};