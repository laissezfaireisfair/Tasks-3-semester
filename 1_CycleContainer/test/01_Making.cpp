#include <iostream>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

int main() {
  cout                 << "-----------MAKING TEST------------" << endl;
  cout                 << "Making empty container..........";
  Container<int> emptyCont = Container<int>();
  cout << "OK" << endl << "Making allocated container......";
  Container<int> allocatedCont = Container<int>(5);
  cout << "OK" << endl << "Making initialised container....";
  Container<int> initialisedCont = Container<int>(42, 5);
  cout << "OK" << endl << "Making copy of container........";
  Container<int> copyCont = Container<int>(initialisedCont);
  cout << "OK" << endl << "Copying to existing container...";
  emptyCont = initialisedCont;
  cout << "OK" << endl << "All right. Exiting." << endl;
  return 0;
}
