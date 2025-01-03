for (pair<char, vector<Pos>> x : ants) {
  cout << x.first << ": ";
  for (Pos y : x.second) cout << "[" << y.r << ", " << y.s << "] ";
  cout << endl;
}
