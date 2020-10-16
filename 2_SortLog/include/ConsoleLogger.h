#pragma once

#include <vector>

class Operation;
class Elem;

class ConsoleLogger {
public:
	ConsoleLogger();
	void operation_happened(Operation const & operation);
    void print_operations() const;
    static void print_vec(std::vector<Elem> const & vec);
private:
	std::vector<Operation*> m_operations;
};