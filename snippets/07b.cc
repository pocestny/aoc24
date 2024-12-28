#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
using Int = uint64_t;

Int comb(Int a, Int b) {
  Int m = 10;
  while (b >= m) m *= 10;
  return a * m + b;
}

vector<int> c;

bool inc() {
  int i = 0;
  while (i < c.size() && c[i] == 2) c[i++] = 0;
  if (i == c.size()) return false;
  c[i]++;
  return true;
}

int main() {
  string line;
  Int res = 0;
  while (getline(cin, line)) {         // spracujem každý riadok
    replace(line.begin(), line.end(), ':', ' ');
    stringstream ss(line);
    Int m;
    ss >> m;
    vector<int> a;
    Int x;
    while (ss >> x) a.push_back(x);
    int n = a.size();
    c.clear();               // vyčistím c
    c.resize(n - 1, 0);      // tento zápis upraví počet prvkov na n-1 (ak ich predtým, bolo viac, 
                             // zvyšneé zahodí, ak ich bolo menej, doplní ich nulami)
                             // keďže som ho predtým vyprázdnil, teraz v ňom budú samé nuly
    bool ok = false;
    do {                     // cyklus v ktorom skúšam všetky možnosti
      Int x = a[0];
      for (int i = 0; i < n - 1; i++) {
        if (c[i] == 0)
          x *= a[i + 1];
        else if (c[i] == 1)
          x += a[i + 1];
        else
          x = comb(x, a[i + 1]);
      }
      if (x == m) ok = true;
    } while (!ok && inc());  // ak som nenašiel, zavolám inc() pre ďalšiu možnosť

    if (ok) res += m;
  }

  cout << res << endl;
}
