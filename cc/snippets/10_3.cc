int Get(Pos p) {
  if (p.r >= 0 && p.r < r && p.s >= 0 && p.s < s) return in[p.r][p.s];
  return -1;
}
