#include <iostream>
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

vector<string> in;          // vstup
vector<vector<int>> ids;    // identifikátory pozemkov
int r, s;                   // rozmery

// je daná pozícia na mape?
bool valid(Pos p) { return !(p.r < 0 || p.r >= r || p.s < 0 || p.s >= s); }

// Aké je písmeko na pozícii p?
char ch(Pos p) {
  if (valid(p)) return in[p.r][p.s];
  else return '#';
}

// Aký je identifikátor na pozícii p?
int id(Pos p) {
  if (valid(p)) return ids[p.r][p.s];
  else return -1;
}

int main() {
  string line;

  while (cin >> line) // prečítam vstup
    in.push_back(line);
  
  // nastavím rozmery
  r = in.size();
  s = in[0].size();

  // nastavím ids na správnu veľkosť: bude mať r prvkov, každý z nich bude 
  // s.prvkový vector<int> s hodnotami -1
  ids.resize(r, vector<int>(s, -1));
}
