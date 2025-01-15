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

vector<string> in;
vector<vector<int>> ids;
int r, s;

bool valid(Pos p) { return !(p.r < 0 || p.r >= r || p.s < 0 || p.s >= s); }

char ch(Pos p) {
  if (valid(p)) return in[p.r][p.s];
  else return '#';
}

int id(Pos p) {
  if (valid(p)) return ids[p.r][p.s];
  else return -1;
}

void ofarbi(Pos p) {
  for (Pos d : dir) {
    Pos q = p + d;
    if (ch(q) == ch(p) && id(q) == -1) {
      ids[q.r][q.s] = ids[p.r][p.s];
      ofarbi(q);
    }
  }
}

int main() {
  string line;
  while (cin >> line) {
    in.push_back(line);
  }
  r = in.size();
  s = in[0].size();

  ids.resize(r, vector<int>(s, -1));

  int max_id = 0;
  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++)
      if (ids[i][j] == -1) {
        ids[i][j] = max_id++;
        ofarbi({i, j});
      }

  vector<int> sz(max_id, 0), o(max_id, 0);

  for (int i = 0; i < r; i++)
    for (int j = 0; j < s; j++) {
      Pos p = {i, j};
      sz[id(p)]++;
      for (int d = 0; d < 4; d++) {
        if (id(p + dir[d]) != id(p) &&
            (id(p + dir[(d + 1) % 4]) != id(p) ||  // toto je jediná zmena oproti prvej časti
             id(p + dir[(d + 1) % 4] + dir[d]) == id(p)))
          o[id(p)]++;
      }
    }

  int res = 0;
  for (int i = 0; i < max_id; i++) res += sz[i] * o[i];
  cout << res << endl;
}
