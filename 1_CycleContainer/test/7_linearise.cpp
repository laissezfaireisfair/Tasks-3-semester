#include <iostream>
#include <vector>
#include "CycleContainer.hpp"

using namespace std;
using namespace CycleContainer;

bool check_linearity(Container<int> const & buffer, bool const expected) {
  cout << "Checking linearity..";
  if (buffer.is_linear() == expected) {
    cout << "OK" << endl;
  } else {
    cout << "FAILED" << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool pop_f(Container<int> & buffer) {
  cout << "Poping front..ю.....";
  try {
    buffer.pop_front();
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

bool linearise(Container<int> & buffer)  {
  cout << "Linearising.........";
  try {
    buffer.linearize();
    cout << "OK" << endl;
  }
  catch (exception & e) {
    cout << "FALIED" << endl << e.what() << endl << "Abort." << endl;
    return false;
  }
  return true;
}

int main() {
  cout << "Making buffer.......";
  Container<int> buffer = Container<int>(5, 42);
  cout << "OK" << endl;

  if (!check_linearity(buffer, true))
    return 1;

  if (!pop_f(buffer))
    return 2;

  if (!check_linearity(buffer, false))
    return 3;

  if (!linearise(buffer))
    return 3;

  if (!check_linearity(buffer, true))
    return 3;


  cout << "All right. Exiting." << endl;
  return 0;
}
