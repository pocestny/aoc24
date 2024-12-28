#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
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
      for (int j = i + 1; ok && j < r.size(); j++)
        for (int k = 0; ok && k < from.size(); k++)
          if (from[k] == r[j] && to[k] == r[i]) ok = false;

    if (!ok) {
      unordered_map<int, bool> jetu;
      unordered_map<int, int> indeg;
      vector<int> zero, sorted;
      unordered_map<int, vector<int>> out;

      for (int x : r) jetu[x] = true;

      for (int i = 0; i < from.size(); i++)
        if (jetu[from[i]] && jetu[to[i]]) {
          out[from[i]].push_back(to[i]);
          indeg[to[i]]++;
        }

      for (int x : r)
        if (indeg[x] == 0) zero.push_back(x);

      while (zero.size() > 0) {
        int u = zero.back();
        zero.pop_back();
        sorted.push_back(u);
        for (int w : out[u]) {
          indeg[w]--;
          if (indeg[w] == 0) zero.push_back(w);
        }
      }

      res += sorted[sorted.size() / 2];
    }
  }

  cout << res << endl;
}
