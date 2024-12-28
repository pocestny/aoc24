#include <iostream>
#include <string>
#include <vector>
using namespace std;

// všetky tri spôsoby, ako inicializovať string, sú správne
// string p("XMAS");
// string p = "XMAS";
string p{"XMAS"};

vector<string> a;
int n, m, t;

char get(int i, int j) {
  if (i >= 0 && i < n && j >= 0 && j < m) return a[i][j];
  return '_';
}

int main() {
  string line;

  while (getline(cin, line)) a.push_back(line);  // prečítam si vstup
  n = a.size();
  m = a[0].size();
  t = p.size();

  int res = 0;

  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)                     // týmito dvoma cyklami prechádzam všetky políčka
      for (int di = -1; di < 2; di++)
        for (int dj = -1; dj < 2; dj++) {           // týmito dvoma cyklami skúšam všetky smery
          bool got = true;                          // tu si pamätám, či je v danom smere výskyt 
          for (int k = 0; got && k < t; k++) {      // týmto cyklom testujem výskyt v danom smere 
            int ii = i + k * di, jj = j + k * dj;
            if (get(ii, jj) != p[k]) got = false;
          }
          if (got) res++;
        }
  cout << res << endl;
}
