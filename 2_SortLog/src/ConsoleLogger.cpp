#include <iostream>
#include "ConsoleLogger.h"
#include "Elem.h"

 void ConsoleLogger::print_comparsion(Elem const & left, Elem const & right) {
	std::cout << left.get_position() << " " << right.get_position() << std::endl;
}