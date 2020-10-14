#include <iostream>
#include "ConsoleLogger.h"

class Elem;

static void ConsoleLogger::print_comparsion(Elem const & left, Elem const & right) {
	std::cout << left.get_position() << " " << right.get_position() << std::endl;
}