vector<int> c;

bool inc() {  // vrátim false, ak inkrement pretiekol, t.j. som na konci prezertania               
  int i = 0;
  while (i < c.size() && c[i] == 2) c[i++] = 0; // zápis c[i++] znamená ``vyhodnoť c[i] a potom urob i++''
  if (i == c.size()) return false;              // prišiel som na koniec  
  c[i]++;                                       // prvá nedvojková cifra sa inkrementuje
  return true;          
}

