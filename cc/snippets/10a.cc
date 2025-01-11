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

vector<string> in;
int r, s;  // počet riadkov a stĺpcov

int main() {
  string line;
  in.push_back("#");
  while (getline(cin, line)) in.push_back("#" + line + "#");
  in.push_back(string(in.back().size(), '#'));
  in[0] = in.back();
  r = in.size() - 2;     // treba odrátať 2 kvôli zarážke
  s = in[0].size() - 2;

  int res = 0;
  for (int i = 1; i <= r; i++)    // nejdeme od 0 do r-1, ale od 1 do r kvôli zarážke
    for (int j = 1; j <= s; j++)
      if (in[i][j] == '0') {      // potenciálny začiatok 
        vector<set<Pos>> pos(10); // pos[i] je množina pozícií, kam vieme prísť po i krokoch
        pos[0].insert({i, j});    // pos[0] je štartovacia pozícia
        for (int l = 1; l <= 9; l++) {  // pre všetky ďalšie vzdialenosti l
          for (Pos p : pos[l - 1])      // prejdeme všetky pozície, kam sa vieme dostať na l-1 krokov
            for (Pos d : dir) {         // skúsime všetky smery
              Pos q = p + d;
              if (in[q.r][q.s] == l+'0') // ak je v mape políčko l, tak ho pridáme
                pos[l].insert(q);
            }
        }
        res += pos[9].size();    // pridáme počet destinácií z {i,j}
      }
  cout << res << endl;
}
