#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<int> & buffer, vector<int> const & expected) {
  cout << "Checking size...................";
  if (buffer.get_size() == expected.size()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  cout << "Checking values in container....";
  for (uint64_t i = 0; i < expected.size(); ++i) {
    if (buffer[i] != expected[i]) {
      cout << "FAILED" << endl << "Abort." << endl;
      return false;
    }
  }
  cout << "OK" << endl;
  return true;
}

bool push_b(Container<int> & buffer, int const value) {
  cout << "Pushing back value..............";
  try {
    buffer.push_back(value);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool push_f(Container<int> & buffer, int const value) {
  cout << "Pushing front value.............";
  try {
    buffer.push_front(value);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

int main() {
  cout << "--------INIT AND PUSH TEST--------" << endl;
  cout << "Making initialised container....";
  Container<int> buffer = Container<int>(5, 42);
  cout << "OK" << endl;
  if (!check_buffer(buffer, vector<int>(5, 42)))
    return 1;

  cout << "Making allocated container......";
  Container<int> buff2 = Container<int>(5);
  cout << "OK" << endl;
  if (!push_b(buff2, 42))
    return 2;
  if (!check_buffer(buff2, vector<int>(1, 42)))
    return 3;

  if(!push_f(buff2, 41))
    return 4;
  vector<int> expected = {41, 42};
  if (!check_buffer(buff2, expected))
    return 5;
  cout << "All right. Exiting." << endl;
  return 0;
}
