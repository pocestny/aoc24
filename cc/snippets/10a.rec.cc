#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;


// ----------------------------- copy & paste ------------------------------
struct Pos {
  int r, s;
  void operator+=(Pos a) { r += a.r;s += a.s; }
  void operator*=(int a) { r *= a;s *= a; }
};
bool operator==(Pos a, Pos b) { return a.r == b.r && a.s == b.s; }
bool operator!=(Pos a, Pos b) { return !(a == b); }
Pos operator+(Pos a, Pos b) { return {a.r + b.r, a.s + b.s}; }
Pos operator-(Pos a, Pos b) { return {a.r - b.r, a.s - b.s}; }
Pos operator*(int a, Pos b) { return {a * b.r, a * b.s}; }
bool operator<(Pos a, Pos b) { if (a.r != b.r) return a.r < b.r; else return a.s < b.s; }
const vector<Pos> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// -------------------------------------------------------------------------

vector<vector<int>> in;
int r, s;

int Get(Pos p) {
  if (p.r >= 0 && p.r < r && p.s >= 0 && p.s < s) return in[p.r][p.s];
  return -1;
}

set<Pos> tr;  // funkcia test sem bude ukladať výsledok

void test(Pos p) {           // rekurzívna funkcia
  int v = Get(p);            // pozri sa, kde stojíš
  if (v == 9) tr.insert(p);  // ak stojíš na deviatke, ulož si ďalšiu nájdenú destináciu
  else for (Pos d : dir)     // inak sa pozri na všetky smery
    if (Get(p + d) == v + 1) // ak tam je správne číslo
      test(p + d);           // tak tam skús ísť
}

int main() {
  string line;
  while (cin >> line) {
    in.push_back({});
    for (int i = 0; i < line.size(); i++) in.back().push_back(line[i] - '0');
  }
  r = in.size();
  s = in[0].size();

  int res = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
      if (in[i][j] == 0) {  // pre všetky políčka, na ktorých je nula
        tr.clear();         // vyčistíme destinácie   
        test({i, j});       // rekurzívne všetky nájdeme
        res += tr.size();
      }
  cout << res << endl;
}
