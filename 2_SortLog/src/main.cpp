#include <iostream>
#include <algorithm>
#include <vector>
#include "Elem.h"
#include "ConsoleLogger.h"

int main() {
	unsigned int const numberOfElements = 10; 
	std::vector<Elem> vector(numberOfElements);
    ConsoleLogger logger;
	for (unsigned int i = 0; i < numberOfElements; ++i)
		vector[i] = Elem(static_cast<int>(numberOfElements - i - 1), i, logger);
    ConsoleLogger::print_vec(vector);
	std::sort(vector.begin(), vector.end());
	logger.print_operations();
	return 0;
}