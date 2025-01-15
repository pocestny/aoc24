int main() {  
  string line;            // prečítam vstup
  while (cin >> line) 
    in.push_back(line);
  r = in.size();
  s = in[0].size();

  ids.resize(r, vector<int>(s, -1));  // vyrobím pole ids
  int max_id = 0;                     // prvé voľné id
  for (int i = 0; i < r; i++)         // prejdem po mape
    for (int j = 0; j < s; j++)
      if (ids[i][j] == -1) {          // ak nájdem nepriradené id
        ids[i][j] = max_id++;         // nastavím ho 
        ofarbi({i, j});               // a ofarbím pozemok
      }

  vector<int> sz(max_id, 0), o(max_id, 0); // pre každý pozemok si pamätám veľkosť a obvod

  for (int i = 0; i < r; i++)        // prechádzam po mape 
    for (int j = 0; j < s; j++) {
      Pos p = {i, j};
      sz[id(p)]++;                   // zarátam jednotku do veľkosti pozemku s mojím id
      for (Pos d : dir)              // pozriem všetkých susedov 
        if (id(p + d) != id(p))      // ak má rôzne id (alebo je mimo ihriska)
          o[id(p)]++;                // zarátam jednotku do obvodu
    }

  int res = 0;
  for (int i = 0; i < max_id; i++)   // nakoniec len sčítam výsledok
    res += sz[i] * o[i]; 
  cout << res << endl;

}
