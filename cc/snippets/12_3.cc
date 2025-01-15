void ofarbi(Pos p) {         // políčko p už má nastavené id, idem dofarbiť súvislý úsek
  for (Pos d : dir) {        // pozriem sa na všetkých susedov
    Pos q = p + d;
    if (ch(q) == ch(p) && id(q) == -1) { // ak má rovnaké písmenko a ešte nemá priradené id
      ids[q.r][q.s] = ids[p.r][p.s];     // priradím mu id 
      ofarbi(q);                         // a urobím na ňom to isté
    }
  }
}
