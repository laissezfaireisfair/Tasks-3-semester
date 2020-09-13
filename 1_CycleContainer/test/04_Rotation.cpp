#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<int> & buffer, vector<int> const & expected) {
  cout << "Checking values.................";
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

bool init_buffer(Container<int> & buffer, vector<int> const & values) {
  cout << "Adding values...................";
  try {
    for (int i = 0; i < 5; ++i)
      buffer.push_back(values[i]);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_rotation_f(Container<int> & buffer, unsigned int const distance, vector<int> const & expected) {
  cout << "Making rotation forward.........";
  try {
    buffer.rotate_forward(distance);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  if (!check_buffer(buffer, expected))
    return false;
  return true;
}

bool check_rotation_b(Container<int> & buffer, unsigned int const distance, vector<int> const & expected) {
  cout << "Making rotation back............";
  try {
    buffer.rotate_back(distance);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  if (!check_buffer(buffer, expected))
    return false;
  return true;
}

int main() {
  cout << "----------ROTATION TEST-----------" << endl;
  cout << "Making allocated container......";
  Container<int> buffer = Container<int>(5);
  cout << "OK" << endl;

  vector<int> values = {0, 1, 2, 3, 4};
  if (!init_buffer(buffer, values))
    return 1;
  if (!check_buffer(buffer, values))
    return 2;

  vector<int> afterRotationF = {4, 0, 1, 2, 3};
  if (!check_rotation_f(buffer, 1, afterRotationF))
    return 3;

  vector<int> afterRotationB = {1, 2, 3, 4, 0};
  if (!check_rotation_b(buffer, 2, afterRotationB))
    return 4;

  cout << "All right. Exiting." << endl;
  return 0;
}
