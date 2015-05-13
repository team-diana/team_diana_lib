#ifndef TEAM_DIANA_LIB_STRINGS_STRINGS
#define TEAM_DIANA_LIB_STRINGS_STRINGS

#include "team_diana_lib/traits/strings.h"

#include <string>
#include <sstream>

namespace Td {

  inline
  void put(std::ostream & stream) {
  }

  /**
  * @brief Appends each argument to the stream, using the argument's operator<<
  *
  * This function will stop at compile time with an error message if the
  * argument is not supported.
  *
  * @param os ostream that will be used.
  * @param args argument to be appended.
  * @returns the updated ostream.
  **/
  template<typename T, typename ... Args>
  std::ostream& put(std::ostream & os, T && arg, Args && ... args)
  {
    static_assert_supports_ostream<T>();

    os << std::forward<T>(arg);
    put(os, std::forward<Args>(args) ...);

    return os;
  }

  /**
  * @brief Creates a string that concatenates each arguments
  *
  * This function will use each argument's operator<< for concatenation.
  * Since most types implements operator<<, this function can be used like the
  * toString function of many other programming languages.
  *
  * This function will stop at compile time with an error message if the
  * argument is not supported.
  *
  * @param os ostream that will be used.
  * @param args argument to be appended.
  * @returns the updated ostream.
  **/
  template<typename ... Args>
  std::string toString(Args && ... args) {
    std::ostringstream oss;
    put(oss, std::forward<Args>(args) ...);

    return oss.str();
  }

}

#endif
