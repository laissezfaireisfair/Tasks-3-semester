#include <iostream>
#include <vector>
#include <memory>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_buffer(Container<unique_ptr<int>> const & buffer, vector<int> const & expected) {
  cout << "Checking size..................";
  if (buffer.get_size() == expected.size()) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  cout << "Checking values in container...";
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
  Container<unique_ptr<int>> ptrs(1);
  unique_ptr<int> num = make_unique<int>();
  *num = 54;
  ptrs.push_back(move(num));
  if (!check_buffer(ptrs, vector<int>(1, 54)))
    return 1;  

  cout << "All right. Exiting." << endl;
  return 0;
}
