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

vector<string> a;  // mapa
int r, s;          // a jej rozmery

bool Valid(Pos p) {  // Je p v mape ?
  if (p.r < 0 || p.r >= r || p.s < 0 || p.s >= s) return false;
  return true;
}

Pos start;
map<Pos, int> m;  // mapa je teraz globálna premenná, aby som ju mohol čítať v hlavnom programe

bool skus(Pos x) {
  bool loop = false;
  Pos p = start;
  int d = 3;

  m.clear();      // tu ju treba vyčistiť

  if (Valid(x)) a[x.r][x.s] = '#'; // nedávaj prekážku, ak sa spustil s divnou hodnotou
  while (true) {
    if ((m[p] & (1 << d)) != 0) {
      loop = true;
      break;
    }
    m[p] |= 1 << d;
    Pos pp = p + dir[d];
    if (!Valid(pp)) break;
    if (a[pp.r][pp.s] != '#')
      p = pp;
    else
      d = (d + 1) % 4;
  }
  if (Valid(x)) a[x.r][x.s] = '.';
  return loop;
}

int main() {
  string line;

  while (getline(cin, line)) a.push_back(line);
  r = a.size();
  s = a[0].size();

  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
      if (a[i][j] == '^') start = {i, j};

  skus({-1, -1});  // raz sa spustím bez uloženia prekážky
  vector<Pos> a;   // sem si uložím políčka, ktoré sa prešli

  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
      if (m[{i, j}] > 0) a.push_back({i, j});

  int res = 0;
  for (Pos p : a) if (skus(p)) res++;  // skúšam iba tie, ktoré môžu pripadať do úvahy

  cout << res << endl;
}
