#include <iostream>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

int main() {
  cout << "----------COMPARSION TEST---------" << endl;
  cout << "Making buffers..................";
  Container<int> buffer1 = Container<int>(5, 42);
  Container<int> buffer2 = Container<int>(5, 54);
  cout << "OK" << endl;

  cout << "Comparsion test 1...............";
  if (buffer1 == buffer2) {
    cout << "FAILED" << endl << "Abort." << endl;
    return 1;
  }
  if (!(buffer1 != buffer2)) {
    cout << "FAILED" << endl << "Abort." << endl;
    return 2;
  }
  cout << "OK" << endl;

  for (size_t i = 0; i < 6; ++i)
    buffer2[i] = 42;

  cout << "Comparsion test 2...............";
  if (buffer1 != buffer2) {
    cout << "FAILED" << endl << "Abort." << endl;
    return 1;
  }
  if (!(buffer1 == buffer2)) {
    cout << "FAILED" << endl << "Abort." << endl;
    return 2;
  }
  cout << "OK" << endl;

  cout << "All right. Exiting." << endl;
  return 0;
}
