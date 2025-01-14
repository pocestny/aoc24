#include <cstdint>
using Int = uint64_t;

int len(Int x) {
  int res = 0;
  while (x > 0) {
    res++;
    x /= 10;
  }
  return res;
}
