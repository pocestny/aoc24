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
  long long res = 0;
  while (get()) {
    long long ax, ay, bx, by, rx, ry;
    sscanf(line[0].c_str(), "Button A: X+%lld, Y+%lld ", &ax, &ay);
    sscanf(line[1].c_str(), "Button B: X+%lld, Y+%lld ", &bx, &by);
    sscanf(line[2].c_str(), "Prize: X=%lld, Y=%lld ", &rx, &ry);
    rx += 10000000000000L;  // L na konci čísla znamená, že to číslo má byť dlhé
    ry += 10000000000000L;  // v opačnom prípade by sa najprv štandardne orezalo
                            // na veľkosť int a až potom by sa skúšalo priradiť
                            // do premennej

    // Cramerovo pravidlo
    long long D = ax * by - ay * bx, Dp = rx * by - ry * bx,
              Dq = ax * ry - rx * ay;
    assert(D != 0);
    long long p = Dp / D, q = Dq / D;

    if (p * D == Dp && q * D == Dq)  // celočíselné riešenie
      res += 3 * p + q;
  }
  cout << res << endl;
}
