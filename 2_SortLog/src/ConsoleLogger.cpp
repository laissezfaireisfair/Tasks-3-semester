#include <iostream>
#include "ConsoleLogger.h"

static void ConsoleLogger::print_comparsion(Elem const & left, Elem const & right) {
	std::cout << left.get_value() << " " << right.get_value() << std::endl;
}