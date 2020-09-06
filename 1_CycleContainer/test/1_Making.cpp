#include <iostream>
#include "CycleContainer.hpp"

using namespace CycleContainer;

int main() {
  Container<int> emptyCont       = Container<int>();
  Container<int> allocatedCont   = Container<int>(5);
  Container<int> initialisedCont = Container<int>(42, 5);
  Container<int> copyCont        = Container<int>(initialisedCont);
  emptyCont = initialisedCont;
  return 0;
}
