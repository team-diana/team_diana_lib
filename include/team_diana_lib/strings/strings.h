#ifndef TEAM_DIANA_LIB_STRINGS_STRINGS
#define TEAM_DIANA_LIB_STRINGS_STRINGS

#include "team_diana_lib/traits/strings.h"

#include <string>
#include <sstream>

using namespace std;

inline
void concatStream(ostream & stream)
{}

template<typename T, typename ... Args>
ostream& concatStream(ostream & os, T && arg, Args && ... args)
{
  static_assert_supports_ostream<T>();

  os << std::forward<T>(arg);
  concatStream(os, std::forward<Args>(args) ...);

  return os;
}

template<typename ... Args>
string toString(Args && ... args) {
  ostringstream oss;
  concatStream(oss, std::forward<Args>(args) ...);

  return oss.str();
}


#endif
