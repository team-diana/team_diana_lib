/**
 * Temporary file. @see TODO
 */

#include "team_diana_lib/geometry/vectors.h"
#include "team_diana_lib/strings/strings.h"
#include "team_diana_lib/strings/iterables.h"
#include "team_diana_lib/math/math.h"

#include <functional>
#include <algorithm>
#include <iostream>

using namespace std;

bool run_tests(vector<function<bool()>> tests) {
  vector<bool> results(tests.size());

  cout << "Starting " << tests.size() << " tests. " << endl;
  typedef typename decltype(tests)::value_type FuncT;
  std::transform(tests.begin(), tests.end(), results.begin(), [](FuncT f) { return f(); });

  vector<bool> failed;
  std::copy_if(results.begin(), results.end(), failed.begin(), [](bool v) { return v == false; });

  cout << "Ran " << results.size() << " tests. " << endl;

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

  // used struct instead of class to make the member public
  // and therefore avoid the clang warning-Wunused-private-field
  // (private field 'v' is not used)
  struct WithoutOStreamSupport {
	  int v;
  };

  // This should cause a compile time exception
  // s = Td::toString(WithoutOStreamSupport() );

  return true;
}

bool iterableToStringTest() {
  int intVec[] = {1, 2, 3, 4};
  std::vector<char> charVec {'a', 'b', 'c'};

  string intVecStr = Td::iterableToString(intVec, ":");
  if("1:2:3:4" != intVecStr) {
    cerr << "intVec was not converted to a string correctly, result was: " << intVecStr << endl;
    return false;
  }

//   const char* str = "hello";
//   TODO: will not compile, add support for string.
//   string strStr = Td::iterableToString(str);
//   if("h e l l o" != strStr) {
//     cerr << "strStr was not converted to a string correctly, result was: " << strStr << endl;
//     return false;
//   }

  string charVecString = Td::iterableToString(charVec, "<o>");
  if("a<o>b<o>c" != charVecString) {
    cerr << "charVec was not converted to a string correctly, result was: " << charVecString << endl;
    return false;
  }

  return true;
}

bool sgnTest() {
  double v1 = -0.01;

  double sgnv1 = Td::sgn(v1);
  if(sgnv1 >= 0) {
    cerr << "the sign of v1 was wrong " << sgnv1 << endl;
    return false;
  }

  return true;
}

int main(int argc, char** argv) {
  vector<function<bool()>> tests = {
    copyVector3Test,
    toStringTest,
    iterableToStringTest,
    sgnTest
  };

  run_tests(tests);
}
