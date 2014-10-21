#ifndef TEAM_DIANA_LIB_MATH_MATH
#define TEAM_DIANA_LIB_MATH_MATH

namespace Td {

  /**
   *  @returns the sign of @b val
   *  @author http://stackoverflow.com/posts/4609795/revisions
   */
  template <typename T, typename R = int> R sgn(T val) {
      return (T(0) < val) - (val < T(0));
  }
}

#endif
