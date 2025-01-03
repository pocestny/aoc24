#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using Int = int64_t;

int main() {
  string line;
  Int res = 0;

  while (getline(cin, line)) {  // prečítam riadok
    replace(line.begin(), line.end(), ':', ' ');  // dám preč dvojbodku za prvým číslom
    stringstream ss(line);  // vyrobím si stream z riadku
    Int m;                  // prečítam prvé číslo (cieľové)
    ss >> m;
    vector<Int> a;  // zvyšok si uložím sem
    Int x;    
    while (ss >> x) a.push_back(x);

    int n = a.size();
    bool ok = false; // tu je výsledok, či sa mi podarilo vyskladať m

    for (Int N = 0; !ok && (N < (1L << (n - 1))); N++) {  // v N budem mať čísla od 0 po 2^(n-1)-1
      Int x = a[0];                       // v x si budem zbierať výsledok

      for (int i = 0; i < n - 1; i++)     // prejdem n-1 pozícií 
        if (N & (1L << i))                // ak je v N nastavený i-ty bit
          x *= a[i + 1];                  // daj násobenie
        else
          x += a[i + 1];                  // inak daj sčítanie
      if (x == m) ok = true;              // ak som dostal cieľové číslo, som rád 
    }
    if (ok) res += m;                     // zarátam ďalšiu možnosť
  }
  cout << res << endl;
}
