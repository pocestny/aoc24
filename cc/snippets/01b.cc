#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;
int main() {
  vector<int> a;              // a[i] je i-ty prvok z prvého zoznamu
  unordered_map<int, int> b;  // b[i] je počet výskytov čísla i v druhom zozname
  int x, y;

  while (cin >> x >> y) {
    a.push_back(x);  // x pridáme na koniec
    b[y]++;  // Ak sa kľúč y zatiaľ nevyskytol, vyrobí sa s hodnotou 0. V každom
             // prípade sa počet výskytov o 1 zväčší
  }

  int res = 0;  // tu bude výsledok
  for (int i = 0; i < (int)a.size(); i++)
    res += a[i] * b[a[i]];  //  hodnota i-teho prvku * počet jeho výskytov v
                            //  druhom zozname

  cout << res << endl;
}
