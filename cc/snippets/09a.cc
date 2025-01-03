#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string line;
  getline(cin, line);
  int n = 0;
  for (char c : line) n += c - '0';
  vector<int> a(n, -1);
  int id = 0, pos = 0;
  for (int i = 0; i < line.size(); i++) {
    int l = line[i] - '0';
    if (l == 0) continue;
    if (i % 2 == 0) {
      for (int j = 0; j < l; j++) a[pos++] = id;
      id++;
    } else
      pos += l;
  }

  for (int l = 0, r = n - 1; l < r;) {    // idem, kým sa l a r nestretnú
                                          // tretia časť for cyklu je prázdna, aktualizácia
                                          // l a r sa deje v tele cyklu

    while (l < n && a[l] >= 0) l++;       // nájdem si prvý voľný blok
    while (r >= 0 && a[r] == -1) r--;     // nájdem si posledný zaplnený blok

    if (l < r) swap(a[l], a[r]);          // ak som sa nezrazil, tak ich vymením
                                          // swap je definovaný v <algorithm>
  }

  int64_t res = 0;                // tu už len spočítam výsledok           
  for (int i = 0; i < n; i++)
    if (a[i] > 0) res += i * a[i];
  cout << res << endl;
}
