int r, s;
map<char, vector<Pos>> ants;

string line;
for (r = 0; getline(cin, line); r++)  // po skončení budú nastavené aj globálne
  for (s = 0; s < line.size(); s++)   // premenné r a s
    if (isalnum(line[s])) ants[line[s]].push_back({r, s});
