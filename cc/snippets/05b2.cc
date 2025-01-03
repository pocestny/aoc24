#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


// Kto je pred kým.
//
// Tento zápis hovorí, že g je vector, ktorého prvky sú typu "vector<bool>"
// Pri vyrábaní sa vyrobí vector veľkosti 100 a každý jeho prvok
// sa nastaví na hodnotu "vector<bool>(100, false)"
// Táto hodnota hovorí, že treba vyrobiť vector dĺžky 100, s hodnotami typu bool
// ktoré budú false. Efektívne sa teda vyrobí tabuľka 100 x 100 hodnôt bool
vector<vector<bool>> g(100, vector<bool>(100, false));  

// Porovnávacia funkcia
bool cmp(int i, int j) { return g[i][j]; }

int main() {
  string line;

  int n = 1;
  while (getline(cin, line)) {
    if (line.size() == 0) break;
    replace(line.begin(), line.end(), '|', ' ');
    stringstream str(line);
    int x, y;
    str >> x >> y;
    g[x][y] = true; // čítame vstup a nastavujeme hodnoty true
                    // (opačný smer je false, lebo sme celú tabuľku inicializovali na false)
  }

  int res = 0;
  while (getline(cin, line)) {
    replace(line.begin(), line.end(), ',', ' '); // prečítame riadok, vyhodím čiarky
    stringstream str(line);                      // spravím z neho stream  
    vector<int> r;                    
    int x;
    while (str >> x) r.push_back(x);             // uložím do r
    vector<int> sorted = r;                      // spravím kópiu   
    sort(sorted.begin(), sorted.end(), cmp);     // utriedim ju pomocou cmp

    if (sorted != r) res += sorted[sorted.size() / 2]; // ak nebol utriedený správne, zoberiem stredný prvok
  }

  cout << res << endl;
}
