#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

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

bool check_empty(Container<int> const & buffer, bool const expected) {
  cout << "Checking empty..................";
  if (buffer.is_empty() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_size(Container<int> const & buffer, unsigned int const expected) {
  cout << "Checking size...................";
  if (buffer.get_size() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_capacity(Container<int> const & buffer, unsigned int const expected) {
  cout << "Checking capacity...............";
  if (buffer.get_capacity() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_back(Container<int> const & buffer, int const expected) {
  cout << "Checking back...................";
  if (buffer.get_back() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool check_front(Container<int> const & buffer, int const expected) {
  cout << "Checking front..................";
  if (buffer.get_front() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

int main() {
  cout << "--------INFO METHODS TEST---------" << endl;
  cout << "Making allocated container......";
  Container<int> buffer = Container<int>(5);
  cout << "OK" << endl;

  if (!check_empty(buffer, true))
    return 1;
  if (!push_f(buffer, 42)) // {42}
    return 2;
  if (!check_empty(buffer, false))
    return 3;

  if (!check_size(buffer, 1))
    return 4;

  if (!check_capacity(buffer, 5))
    return 5;

  if (!push_b(buffer, 43)) // {42,43}
    return 6;

  if (!check_back(buffer, 43))
    return 7;

  if (!check_front(buffer, 42))
    return 8;

  cout << "All right. Exiting." << endl;
  return 0;
}
