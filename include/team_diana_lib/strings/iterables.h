#ifndef TEAM_DIANA_LIB_STRINGS_ITERABLES
#define TEAM_DIANA_LIB_STRINGS_ITERABLES

#include "team_diana_lib/strings/strings.h"
#include "team_diana_lib/traits/array.h"

#include <string>
#include <sstream>
#include <iterator>
#include <type_traits>

namespace Td {

  // TODO: // can this two template function be joined?
  template <typename C, class = typename std::enable_if<std::is_array<C>::value>::type >
  std::string iterableToString(const C& iterable, std::string separator = " ") {
      std::string str;

      int arraySize = sizeof_array(iterable);
      for (int i = 0; i != arraySize; ++i) {
          if(arraySize - i > 1) {
            str += toString(iterable[i]) + separator;
          } else {
            str += toString(iterable[i]);
          }
      }

      return str;
  };

  template <typename C, class = typename std::enable_if<!std::is_array<C>::value>::type, class = int >
  std::string iterableToString(const C& iterable, std::string separator = " ") {
      std::string str;

      typename C::const_iterator begin = iterable.begin();
      typename C::const_iterator end = iterable.end();

      for (typename C::const_iterator i = begin; i != end; ++i) {
          if(std::distance(i, end) > 1) {
            str += toString(*i) + separator;
          } else {
            str += toString(*i);
          }
      }

      return str;
  };

}

#endif
