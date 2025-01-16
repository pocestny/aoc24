#include <cstdio>    // tu je definovaná funkcia sscanf()
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
  while (get()) {
    int ax, ay, bx, by, rx, ry;
    sscanf(line[0].c_str(), "Button A: X+%d, Y+%d ", &ax, &ay);
    sscanf(line[1].c_str(), "Button B: X+%d, Y+%d ", &bx, &by);
    sscanf(line[2].c_str(), "Prize: X=%d, Y=%d ", &rx, &ry);

    // nejak spracujeme ax, ay, bx, by, rx, ry
  }
}
