#include <cctype>
#include <iostream>
#include <map>
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

int r, s;
map<char, vector<Pos>> ants;
map<Pos, bool> res;            // sem si uložím výsledok


bool valid(Pos p) {  // zisti, či je p mimo ihriska
  return p.r >= 0 && p.r < r && p.s >= 0 && p.s < s; 
}

int main() {
  string line;                  
  for (r = 0; getline(cin, line); r++)
    for (s = 0; s < line.size(); s++)
      if (isalnum(line[s])) ants[line[s]].push_back({r, s});

  for (auto& x : ants) {            // všetky typy antén
    int n = x.second.size();        
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)  // všetky dvojice antén daného typu
        if (i != j) {
          Pos a = x.second[i], b = x.second[j], c = 2 * b - a;
          if (valid(c)) res[c] = true;
        }
  }
  cout << res.size() << endl;
}
