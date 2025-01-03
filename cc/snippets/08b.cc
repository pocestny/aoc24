#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int r, s;
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

map<char, vector<Pos>> ants;
map<Pos, bool> res;  // sem si uložím výsledok

bool valid(Pos p) {  // zisti, či je p mimo ihriska
  return p.r >= 0 && p.r < r && p.s >= 0 && p.s < s;
}

// najväčší spoločný deliteľ p.x a p.y
// to by sa dalo zrátaľ oveľa efektívnejšie (https://en.wikipedia.org/wiki/Greatest_common_divisor)
// ale keďže moje čísla sú malé, tak som lenivý a jednoducho skúšam všetky
int gcd(Pos p) {
  if (p.r == 0) return p.s;
  if (p.s == 0) return p.r;
  for (int x = min(p.r, p.s); x > 1; x--)       // idem od najvačšieho možného; 
                                                // min() a max()  sú definované v knižnici algorithm
    if (p.r % x == 0 && p.s % x == 0) return x; // ak je to spoločný deliteľ, tak je najväčší
  return 1;
}

int main() {
  string line;
  for (r = 0; getline(cin, line); r++)
    for (s = 0; s < line.size(); s++)
      if (isalnum(line[s])) ants[line[s]].push_back({r, s});

  for (auto& x : ants) {  // všetky typy antén
    int n = x.second.size();
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)  // všetky dvojice antén daného typu
        if (i != j) {
          Pos a = x.second[i], b = x.second[j], u = b - a;
          int z = gcd(u); // normalizujem si vektor 
                          // (v mojom vstupe to ani nebolo treba, všetky antény mali súradnice u nesúdeliteľné)
          u.r /= z;
          u.s /= z;
          for (Pos c = a; valid(c); c += u) res[c] = true; // skáčeme cez všetky pozície až kým 
                                                           // neprídeme mimo ihriska
        }
  }
  cout << res.size() << endl;
}
