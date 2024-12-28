vector<string> a;
int n, m;

char get(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) return a[i][j];
  return '_';
}
