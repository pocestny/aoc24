#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
  string line;

  while (getline(cin, line)) {    // čítam riadky zo začiatku
    if (line.size() == 0) break;  // prázdny riadok znanená prechod na druhú časť vstupu
    replace(line.begin(), line.end(), '|', ' ');  // zmením oddeľovač
    stringstream str(line);                       // vyrobím si z riadku stream
    int i, j;
    str >> i >> j;
    ... // tu nejak spracujem šípku i->j
  }

  while (getline(cin, line)) {        // druhá časť vsrupu sú riadky
    replace(line.begin(), line.end(), ',', ' ');
    stringstream str(line);           // vyrobím si stream z riadku
    vector<int> r;
    int x;
    while (str >> x) r.push_back(x);  // uložím si obsah riadku do vectora
    ... // tu nejak skontrolujem riadok
  }
}
