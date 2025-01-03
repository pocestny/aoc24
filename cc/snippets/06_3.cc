bool skus(Pos x) { // zisti, či strážnik chodí do kruhu, ak pridám prekážku na x

  map<Pos, int> m;    //  tu si pamätám smery pre každé políčko
  bool loop = false;  // tu bude výsledok
  Pos p = start;      // start je globálna premenná so štartovacou pozíciou
  int d = 3;          // na začiatku ide hore

  a[x.r][x.s] = '#';  // skúsime pridať prekážku 

  while (true) {
    if ((m[p] & (1 << d)) != 0) { // ak m[p] má nastavený d-ty bit 
      loop = true;                // tak už som zacyklený
      break;
    }
    m[p] |= 1 << d;   // nastav d-ty bit

    Pos pp = p + dir[d];       // pozri sa pred seba
    if (!Valid(pp)) break;     // ak som vyšiel mimo, je koniec
    if (a[pp.r][pp.s] != '#')  // ak nie je prekážka
      p = pp;                  // sprav krok
    else
      d = (d + 1) % 4;         // inak sa otoč
  }

  a[x.r][x.s] = '.';  // nezabudnúť po sebe upratať
  return loop;
}
