#ifndef TEAM_DIANA_LIB_TRAITS_STRINGS
#define TEAM_DIANA_LIB_TRAITS_STRINGS

#include <sstream>
#include <iostream>
#include <array>

template <typename T>
class supports_ostream
{
  static std::ostream &s;
  static T& t;

  template <class U> static auto test(const U u) -> decltype(s << u, char(0)) { }
  static std::array<char, 2> test(...) { return std::array<char, 2>(); }

public:
  static const bool value = (sizeof(test(t)) == 1);
};


template <typename T>  void static_assert_supports_ostream() {
    static_assert(supports_ostream<T>::value, " the type T does not have an operator<<(std::ostream& stream, const T& t) ");
}

#endif
