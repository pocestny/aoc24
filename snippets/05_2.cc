map<int, bool> jetu;
map<int, int> indeg;
map<int, vector<int>> out;

for (int x : r) jetu[x] = true;

for (int i = 0; i < from.size(); i++)  // prejdem všetkými šípkami
  if (jetu[from[i]] && jetu[to[i]]) {  // ak šípka ide medzi relevantnými stránkami
    out[from[i]].push_back(to[i]);     // zaradím to[i] do out[from[i]]
                                       // out[from[i]] je vector<int>, takže má metódu push_back()
    indeg[to[i]]++;                    // a zvýšim indeg pre to[i]
  }
