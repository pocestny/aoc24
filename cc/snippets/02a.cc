#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string line;
  int s = 0;                    // tu bude uložený počet dobrých riadokv
  while (getline(cin, line)) {  // vždy prečítam riadok
    stringstream str(line);     // spravím si stream z riadka
    int x;
    vector<int> a;
    while (str >> x) a.push_back(x);  // uložím si čísla do vektora

    if (a[0] == a[1]) continue;  // ak sa prvé dva prvky rovnajú, dobrý riadok to nebude
    if (a[0] > a[1]) reverse(a.begin(), a.end());  // ak je riadok klesajúci, otoč ho a bude rastúci

    bool ok = true;  // zatiaľ sme nenašli problém

    for (int i = 1; ok && (i < (int)a.size()); i++) {  // kým neprejdeme celý zoznam alebo nejájdeme problém
      if (a[i] <= a[i - 1] || a[i] > a[i - 1] + 3)
        ok = false;  // skontroluj dva za sebou idúce prvky
    }
    if (ok) s++;  // ak sa nenašiel problém, bol to dobrý riadok
  }
  cout << s << endl;
}
