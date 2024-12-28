string p = "XMAS";
int di = -1, dj = 1;

bool got = true;
for (int k = 0; k < (int)p.size(); k++) {
  int ii = i + k * di, jj = j + k * dj;
  if (get(ii, jj) != p[k]) got = false;
}
