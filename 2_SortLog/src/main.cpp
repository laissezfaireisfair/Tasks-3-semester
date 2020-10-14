#include <algorithm>
#include <vector>
#include "Elem.h"

int main() {
	unsigned int const numberOfElements = 10; 
	std::vector<Elem> vector(numberOfElements);
	for (unsigned int i = 0; i < numberOfElements; ++i)
		vector.emplace_back(Elem(static_cast<int>(numberOfElements - i - 1), i));
	std::sort(vector.begin(), vector.end());
	return 0;
}