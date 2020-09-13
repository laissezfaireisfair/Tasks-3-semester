#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<int> & buffer, vector<int> const & expected) {
  if (buffer.get_size() != expected.size()) 
    return false;
  for (uint64_t i = 0; i < expected.size(); ++i)
    if (buffer[i] != expected[i])
      return false;
  return true;
}

bool insert(Container<int> & buffer, size_t const place, int const elem) {
  cout << "Inserting.......................";
  try {
    buffer.insert(place, elem);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool erase(Container<int> & buffer, size_t const first, size_t const last) {
  cout << "Erasing.........................";
  try {
    buffer.erase(first, last);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool reserve(Container<int> & buffer, size_t const newCapacity) {
  cout << "Reserving.......................";
  try {
    buffer.set_capacity (newCapacity);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

int main() {
  cout << "------INSERT AND ERASE TEST-------" << endl;
  cout << "Making buffer...................";
  Container<int> buffer = Container<int>(5, 42);
  cout << "OK" << endl;
  vector<int> expected(5, 42);

  if (!reserve(buffer, 6))
    return 1;

  if (!insert(buffer, 1, 54))
    return 2;
  expected.insert(expected.begin() + 1, 54);
  cout << "Checking insert.................";
  if (check_buffer(buffer, expected)) {
    cout << "OK" << endl;
  } else {
    cout << "FALIED"  << endl << "Abort." << endl;
    return 3;
  }

  if (!erase(buffer, 2, 4))
    return 4;
  expected.erase(expected.begin() + 2, expected.begin() + 4);
  cout << "Checking erase..................";
  if (check_buffer(buffer, expected)) {
    cout << "OK" << endl;
  } else {
    cout << "FALIED"  << endl << "Abort." << endl;
    return 5;
  }

  cout << "All right. Exiting." << endl;
  return 0;
}
