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
  /// Empty tests:
  cout << "Making allocated container.....";
  Container<int> buffer = Container<int>(5);
  cout << "OK" << endl << "Checking empty.................";
  if (buffer.is_empty()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort.";
    return 1;
  }
  cout << "Pushing back value.............";
  try {
    buffer.push_front(42);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 2;
  }
  cout << "Checking empty.................";
  if (!buffer.is_empty()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort.";
    return 3;
  }

  /// Size test:
  cout << "Checking size..................";
  if (buffer.get_size() == 1) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort.";
    return 4;
  }

  /// Capacity test:
  cout << "Checking capacity..............";
  if (buffer.get_capacity() == 5) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort.";
    return 4;
  }

  /// Get front & back tests:
  cout << "Pushing back value.............";
  try {
    buffer.push_back(43);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 5;
  }
  cout << "Checking get_back()............";
  if (buffer.get_back() == 43) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return 6;
  }
  cout << "Checking get_front()...........";
  if (buffer.get_front() == 42) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return 7;
  }

  cout << "All right. Exiting." << endl;
  return 0;
}
