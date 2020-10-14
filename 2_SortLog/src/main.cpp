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
    logger.initialise(vector);
	std::sort(vector.begin(), vector.end());
	if (logger.is_vector_same(vector))
	    std::cout << "Vector traced normally" << std::endl;
	else
        std::cout << "TRACING FAILED" << std::endl;
	return 0;
}