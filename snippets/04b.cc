#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> a;
int n, m;

char get(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) return a[i][j];
  return '_';
}

// zistím, či sa z pozície [i,j] vyskytuje MAS alebo SAM v smere doprava alebo doľava dole
bool match(int i, int j, int dj) {     
  for (string p : {"MAS", "SAM"}) {  // pre tento zápis pozri str. 129
    bool got = true;
    for (int k = 0; k < 3; k++)
      if (get(i + k, j + (k * dj)) != p[k]) got = false;
    if (got) return true;
  }
  return false;
}

int main() {
  string line;
  while (getline(cin, line)) a.push_back(line);
  n = a.size();
  m = a[0].size();

  int res = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      if (match(i, j, 1) && match(i, j + 2, -1)) res++;

  cout << res << endl;
}
