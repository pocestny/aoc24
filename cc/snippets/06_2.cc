struct Pos {
  int r, s;

  // toto je metóda typu, píšeme ju vovnútri definíce typu a 
  // môže pristupovať k jeho premenným
  void operator+=(Pos a) { r += a.r; s += a.s; } 
};

bool operator==(Pos a, Pos b) { return a.r == b.r && a.s == b.s; }
bool operator!=(Pos a, Pos b) { return !(a == b); }

Pos operator+(Pos a, Pos b) { return {a.r + b.r, a.s + b.s}; }

bool operator<(Pos a, Pos b) {
  if (a.r != b.r) return a.r < b.r;
  else return a.s < b.s;
}

const vector<Pos> dir{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
