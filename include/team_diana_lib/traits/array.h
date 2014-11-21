#ifndef TEAM_DIANA_LIB_TRAITS_ARRAY
#define TEAM_DIANA_LIB_TRAITS_ARRAY

namespace Td {

  template< typename T, size_t N > constexpr size_t sizeof_array(T (&)[N])
  {
      return N;
  }

}

#endif
