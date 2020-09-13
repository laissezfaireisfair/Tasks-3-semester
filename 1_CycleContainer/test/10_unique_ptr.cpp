#include <iostream>
#include <vector>
#include <memory>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<unique_ptr<int>> const & buffer, vector<int> const & expected) {
  cout << "Checking size...................";
  if (buffer.get_size() == expected.size()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  cout << "Checking values in container....";
  for (uint64_t i = 0; i < expected.size(); ++i) {
    if (*buffer[i] != expected[i]) {
      cout << "FAILED" << endl << "Abort." << endl;
      return false;
    }
  }
  cout << "OK" << endl;
  return true;
}

int main() {
  cout << "----------UNIQUE_PTR TEST---------" << endl;
  Container<unique_ptr<int>> buffer(5);
  unique_ptr<int> ptr = make_unique<int>();
  *ptr = 54;
  buffer.push_back(move(ptr));
  for (size_t i = 1; i < 5; ++i) {
    buffer.push_back(make_unique<int>());
    *buffer[buffer.get_size() - 1] = 54;
  }
  if (!check_buffer(buffer, vector<int>(5, 54)))
    return 1;

  cout << "All right. Exiting." << endl;
  return 0;
}
