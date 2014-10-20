/**
 * Temporary file. @see TODO
 */

#include "team_diana_lib/geometry/vectors.h"
#include "team_diana_lib/strings/strings.h"

#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

bool run_tests(vector<function<bool()>> tests) {
  vector<bool> results(tests.size());

  cout << "Starting " << tests.size() << " tests. " << endl;
  std::transform(tests.begin(), tests.end(), results.begin(), [](auto f) { return f(); });

  vector<bool> failed;
  std::copy_if(results.begin(), results.end(), failed.begin(), [](bool v) { return v == false; });

  cout << "Runned " << results.size() << " tests. " << endl;

  if ( failed.size() == 0 )
    cout << "All test were OK " << endl;
  else
    cout << "Failed tests: " << failed.size() << endl;

  return failed.size() == 0;
}

bool copyVector3Test() {
  struct V3A {
    float x;
    float y;
    float z;
  };
  struct V3B {
    float x;
    float y;
    float z;
  };

  V3A a;
  V3B b = { 0.1, 0.2, 0.3 };

  Td::copyVector3(a, b);

  if(! (a.x > 0 && a.y > 0 && a.z > 0 ) ) {
    cerr << " vector3 not copied!:  " << a.x << " " << endl;
    return false;
  }

  return true;
}

bool toStringTest() {
  string s = Td::toString("hello ", 1);

  if(s != "hello 1") {
    cerr << " the string was not correct. result was " << s << endl;
    return false;
  }

  class WithoutOStreamSupport {
    int v;
  };

  // This should cause a compile time exception
  // s = Td::toString(WithoutOStreamSupport() );

  return true;
}

int main(int argc, char** argv) {
  vector<function<bool()>> tests = {
    copyVector3Test,
    toStringTest
  };

  run_tests(tests);
}
