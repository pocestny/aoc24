#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// ------------------------ copy & paste -------------------------
struct Pos { int r, s; void operator+=(Pos a) {r += a.r; s += a.s;}};
bool operator==(Pos a, Pos b) {return a.r == b.r && a.s == b.s;}
bool operator!=(Pos a, Pos b) {return !(a == b);}
Pos operator+(Pos a, Pos b) {return {a.r + b.r, a.s + b.s};}
bool operator<(Pos a, Pos b) {if (a.r != b.r) return a.r < b.r; else return a.s < b.s;}
const vector<Pos> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
// ---------------------------------------------------------------

vector<string> a;    // mapa
int r, s;            // a jej rozmery

bool Valid(Pos p) {  // Je p v mape ?
  if (p.r < 0 || p.r >= r || p.s < 0 || p.s >= s) return false;
  return true;
}

int main() {
  string line;

  while (getline(cin, line)) a.push_back(line); // prečítam vstup
  r = a.size();
  s = a[0].size();

  Pos p;  
  int d = 3;

  for (int i = 0; i < r; i++)           // nájdem, kde je na začiatku
    for (int j = 0; j < s; j++)
      if (a[i][j] == '^') p = {i, j};

  map<Pos, bool> m;

  while (true) {
    m[p] = true;               // zapamätám si, že som tu bol
    Pos pp = p + dir[d];       // toto je políčko o krok pred mnou
    if (!Valid(pp)) break;     // ak som vyšiel von, koniec
    if (a[pp.r][pp.s] != '#')  // ak tam nie je prekážka
      p = pp;                  // tak spravím krok
    else
      d = (d + 1) % 4;         // inak sa otočím
  }

  cout << m.size() << endl;
}
