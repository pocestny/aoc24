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

vector<string> in;
int r, s;

int main() {
  string line;
  in.push_back("#");
  while (getline(cin, line)) in.push_back("#" + line + "#");
  in.push_back(string(in.back().size(), '#'));
  in[0] = in.back();
  r = in.size() - 2;
  s = in[0].size() - 2;

  int64_t res = 0;
  for (int i = 1; i <= r; i++)
    for (int j = 1; j <= s; j++)
      if (in[i][j] == '0') {
        vector<map<Pos, int>> pos(10);
        pos[0][{i, j}] = 1;
        for (int l = 1; l <= 9; l++) {
          for (auto &it : pos[l - 1])
            for (Pos d : dir) {
              Pos q = it.first + d;
              if (in[q.r][q.s] == l + '0') pos[l][q] += it.second;
            }
        }
        for (auto &it : pos[9]) res += it.second;
      }
  cout << res << endl;
}
