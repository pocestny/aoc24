vector<vector<int>> in;

string line;
while (cin >> line) {
  in.push_back({});                       // na koniec vložíme nový prázdny riadok
  for (int i = 0; i < line.size(); i++)   // pre všetky znaky vstupu
    in.back().push_back(line[i] - '0');   // na koniec posledného riadka pridáme číslo
}
