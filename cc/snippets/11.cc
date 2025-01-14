#include <cmath>
#include <cstdint>
#include <iostream>
#include <map>
using namespace std;
using Int = uint64_t;

pair<Int, Int> split(Int x) {                     // rozdelíme číslo na dve
  Int y = 0, r = 1;
  for (int i = (1 + log10(x)) / 2; i > 0; i--) {  // zopakujeme polovicu dĺžky krát
    y += r * (x % 10);                            // poslednú cifru z x pripíšeme na začiatok y
    x /= 10;
    r *= 10;
  }
  return {x, y};
}

int main() {
  map<Int, Int> num[2];  // vždy z jednej mapy čítame a do druhej zapisujeme
  int curr = 0;          // čítam z nnum[curr] a píšem do num[1 - curr]
                         // keď potom spravím curr = 1 - curr, tak sa vlastne vymenia
  Int x;
  while (cin >> x) num[curr][x]++;  // prečítam vstup

  for (int cnt = 0; cnt < 75; cnt++) {
    num[1 - curr].clear();          // vyčistím zapisovaciu mapu
    for (auto& it : num[curr]) {    // prejdem cez všetky kamene v mape
      if (it.first == 0)            // všetky nulové kamene sa stanú jednotkovými
        num[1 - curr][1] += it.second;
      else if ((int)(log10(it.first)) % 2 == 1) {  // kamene s párnym počtom cifier sa rozpadnú na dva
        auto p = split(it.first);
        for (Int i : {p.first, p.second}) num[1 - curr][i] += it.second;
      } else                        // ostatné kamene sa prenásobia 2024
        num[1 - curr][it.first * 2024] += it.second;
    }
    curr = 1 - curr;                // vymením čítaciu a zapisovaciu mapu
  }

  Int res = 0;                      // na záver len spočítame, koľko kameňov máme
  for (auto& it : num[curr]) res += it.second;
  cout << res << endl;
}
