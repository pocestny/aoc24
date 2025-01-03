#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> from, to;

int main() {
  string line;

  while (getline(cin, line)) {
    if (line.size() == 0) break;
    replace(line.begin(), line.end(), '|', ' ');
    stringstream str(line);
    int x, y;
    str >> x >> y;
    from.push_back(x);
    to.push_back(y);
  }

  int res = 0;
  while (getline(cin, line)) {
    replace(line.begin(), line.end(), ',', ' ');
    stringstream str(line);
    vector<int> r;
    int x;
    while (str >> x) r.push_back(x);
    bool ok = true;

    for (int i = 0; ok && i < r.size(); i++)
      for (int j = i + 1; ok && j < r.size(); j++)           // pre všetky dvojice pozícií
        for (int k = 0; ok && k < from.size(); k++)          // ... prejdem všetky šípky
          if (from[k] == r[j] && to[k] == r[i]) ok = false;  // ak je tam šípka, už je celý riadok zlý

    if (ok) res += r[r.size() / 2];          // stredný prvok
  }

  cout << res << endl;
}
