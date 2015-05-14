#ifndef TEAM_DIANA_LIB_ENUM_ENUM
#define TEAM_DIANA_LIB_ENUM_ENUM

#include <type_traits>


namespace Td
{

  // http://stackoverflow.com/a/11421471/595897
  template <typename Enumeration> constexpr
    auto to_int(Enumeration const value)
        -> typename std::underlying_type<Enumeration>::type
    {
        return static_cast<typename std::underlying_type<Enumeration>::type>(value);
    }

}

#endif
