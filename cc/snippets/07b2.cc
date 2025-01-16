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

vector<Int> a;

bool test(Int m, Int acc = a[0], int i = 1) {
  // tento zápis s '=' značí 'default' hodnotu: ak pri volaní parameter nie je
  // uvedený, bude mať túto hodnotu

  if (i >= a.size()) return acc == m;
  if (test(m, acc + a[i], i + 1)) return true;
  if (test(m, acc * a[i], i + 1)) return true;
  if (test(m, comb(acc, a[i]), i + 1)) return true;
  return false;
}

int main() {
  string line;
  Int res = 0;
  while (getline(cin, line)) {
    replace(line.begin(), line.end(), ':', ' ');
    stringstream ss(line);
    Int m, x;
    ss >> m;
    a.clear();
    while (ss >> x) a.push_back(x);
    if (test(m)) res += m;
  }
  cout << res << endl;
}
