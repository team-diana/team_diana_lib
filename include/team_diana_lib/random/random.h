#ifndef TEAM_DIANA_LIB_RANDOM_RANDOM
#define TEAM_DIANA_LIB_RANDOM_RANDOM

#include <random>
#include <cmath>

namespace Td {

  /**
   * @returns the next random number of a gaussian distribution of parameters (@param mean, @param sigma)
   *
   * @note: Instead of calling this function several times, use a generator from the standard library.
   *
   * TODO: memoize the generator?
   */
  template <typename T> T nextGaussian(T mean, T sigma) {
    std::default_random_engine generator;
    std::normal_distribution<T> distribution(mean, sigma);
    return distribution(generator);
  }

  template <> int nextGaussian(int mean, int sigma) {
    return round(nextGaussian((double)mean, (double)sigma));
  }

}

#endif
