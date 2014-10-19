#ifndef TEAM_DIANA_LIB_GEOMETRY_VECTORS
#define TEAM_DIANA_LIB_GEOMETRY_VECTORS

namespace Td
{

  /**
   * @brief copy vector @b from content to vector @b to content.
   *
   * @param to result vector
   * @param from vector to copy
   */
  template<class L, class R> void copyVector3(L& to, const R& from) {
    to.x = from.x;
    to.y = from.y;
    to.z = from.z;
  }

  /**
   * @brief returns true if @b v is a zero vector.
   */
  template<class T> bool isVector3Zero(const T& v) {
    return v.x == 0 && v.y == 0 && v.z == 0;
  }

}

#endif
