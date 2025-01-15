void ofarbi(Pos p) {
  vector<Pos> stack;         // zásoba políčok, ktoré ešte treba spracovať
  stack.push_back(p);        // na začiatku iba p

  while (stack.size() > 0) { // kým mám nejaké políčka na spracovanie
    Pos pp = stack.back();   // vyberiem jedno
    stack.pop_back();

    for (Pos d : dir) {      // pozriem sa na všetkých jeho susedov
      Pos q = pp + d;
      if (ch(q) == ch(p) && id(q) == -1) { // ak majú rovnaké písmenko a ešte nepriradené id
        ids[q.r][q.s] = ids[p.r][p.s];     // priradím id
        stack.push_back(q);                // a uložím si do zásobníka na spracovanie
      }
    }
  }
}
