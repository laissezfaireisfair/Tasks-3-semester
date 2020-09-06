#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<int> & buffer, vector<int> const & expected) {
  cout << "Checking size..................";
  if (buffer.get_size() == expected.size()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  cout << "Checking values in container...";
  for (uint64_t i = 0; i < expected.size(); ++i) {
    if (buffer[i] != expected[i]) {
      cout << "FAILED" << endl << "Abort." << endl;
      return false;
    }
  }
  cout << "OK" << endl;
  return true;
}

int main() {
  cout << "Making initialised container...";
  Container<int> buffer = Container<int>(5, 42);
  cout << "OK" << endl;
  if (!check_buffer(buffer, vector<int>(5, 42)))
    return 1;

  cout << "Making allocated container.....";
  Container<int> buff2 = Container<int>(5);
  cout << "OK" << endl << "Pushing back value.............";
  try {
    buff2.push_back(42);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 2;
  }
  if (!check_buffer(buff2, vector<int>(1, 42)))
    return 3;

  cout << "Pushing front value............";
  try {
    buff2.push_front(41);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 4;
  }
  vector<int> expected = {41, 42};
  if (!check_buffer(buff2, expected))
    return 5;
  return 0;
}
