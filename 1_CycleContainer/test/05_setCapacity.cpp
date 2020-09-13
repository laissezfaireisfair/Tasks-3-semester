#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<int> & buffer, vector<int> const & expected) {
  cout << "Checking buffer...";
  if (buffer.get_size() != expected.size()) {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  for (uint64_t i = 0; i < expected.size(); ++i) {
    if (buffer[i] != expected[i]) {
      cout << "FAILED" << endl << "Abort." << endl;
      return false;
    }
  }
  cout << "OK" << endl;
  return true;
}

bool change_capacity(Container<int> & buffer, uint64_t const newCapacity) {
  cout << "Resizing..........";
  try {
    buffer.set_capacity(newCapacity);
    cout << "OK" << endl;
  }
  catch(exception & e) {
    cout << "FAILED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_capacity(Container<int> const & buffer, unsigned int const expected) {
  cout << "Checking capacity.";
  if (buffer.get_capacity() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

int main() {
  cout << "Making buffer.....";
  Container<int> buffer = Container<int>(5, 42);
  cout << "OK" << endl;

  cout << "---Increase check---"  << endl;
  if (!change_capacity(buffer, 6))
    return 1;
  if (!check_capacity(buffer, 6))
    return 2;
  if (!check_buffer(buffer, vector<int>(5, 42)))
    return 3;

  cout << "---Decrease check---"  << endl;
  if (!change_capacity(buffer, 5))
    return 4;
  if (!check_capacity(buffer, 5))
    return 5;
  if (!check_buffer(buffer, vector<int>(5, 42)))
    return 6;

  cout << "All right. Exiting." << endl;
  return 0;
}
