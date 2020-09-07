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

int main() {
  cout << "Making allocated container.....";
  Container<int> buffer = Container<int>(5);
  cout << "OK" << endl << "Pushing front values...........";
  try {
    for (int i = 0; i < 5; ++i)
      buffer.push_back(i);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 1;
  }
  cout << "Checking values................";
  vector<int> expected = {0, 1, 2, 3, 4};
  if (check_buffer(buffer, expected)) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return 2;
  }
  cout << "Making rotation forward........";
  try {
    buffer.rotate_forward(1);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 3;
  }
  cout << "Checking rotation forward......";
  vector<int> expectedAfterRotation = {4, 0, 1, 2, 3};
  if (check_buffer(buffer, expectedAfterRotation)) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return 4;
  }

  cout << "Making rotation back...........";
  try {
    buffer.rotate_back(2);
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return 5;
  }
  cout << "Checking rotation back.........";
  vector<int> expectedAfterRotationB = {1, 2, 3, 4, 0};
  if (check_buffer(buffer, expectedAfterRotationB)) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return 6;
  }

  cout << "All right. Exiting." << endl;
  return 0;
}
