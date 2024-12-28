Int comb(Int a, Int b) {
  Int m = 10;
  while (b >= m) m *= 10;
  return a * m + b;
}
