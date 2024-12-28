#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> a, b;  // vyrobíme si dva zoznamy ...
  int x, y;          // ... a dve premenné na čítanie zo vstupu

  while (cin >> x >> y) {  // prečítame dve čísla, kým sa dá
    a.push_back(x);        // uložíme si ich na koniec zoznamov
    b.push_back(y);
  }
  sort(a.begin(), a.end());  // obidva zoznamy si utriedime
  sort(b.begin(), b.end());

  int res = 0;                             // sem si budeme ukladať výsledok
  for (int i = 0; i < (int)a.size(); i++)  // prejdeme v sykle cez celý zoznam
    res += abs(a[i] - b[i]);               // prirátame absolútnu hodnotu rozdielu

  cout << res << endl;  // nakoniec vypíšeme výsledok
}
