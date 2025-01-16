#include <cassert>  // tu je definovaná funkcia assert()
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string line[4];

bool get() {
  for (int i = 0; i < 4; i++)
    if (!getline(cin, line[i])) return false;
  return true;
}

int main() {
  int res = 0;
  while (get()) {
    int ax, ay, bx, by, rx, ry;
    sscanf(line[0].c_str(), "Button A: X+%d, Y+%d ", &ax, &ay);
    sscanf(line[1].c_str(), "Button B: X+%d, Y+%d ", &bx, &by);
    sscanf(line[2].c_str(), "Prize: X=%d, Y=%d ", &rx, &ry);

    // Cramerovo pravidlo
    int D = ax * by - ay * bx, Dp = rx * by - ry * bx, Dq = ax * ry - rx * ay;
    assert(D != 0);  // assert skončí program s chybou, ak nie je splnená podmienka
                     // je to dobré na to, aby sme vedeli identifikovať chybu hneď na tom mieste,
                     // kde sa vyskytne; ak program dobehne do konca, znamená to, že nikdy
                     // nebolo D == 0
    int p = Dp / D, q = Dq / D;

    if (p * D == Dp && q * D == Dq)  // celočíselné riešenie
      res += 3 * p + q;
  }
  cout << res << endl;
}
