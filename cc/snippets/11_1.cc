void mult(vector<int> &a, int x) {
  int cr = 0;         // 'prenos' (v našom prípade môže byť aj väčší ako 10)
  for (int &v : a) {  // ideme cez všetky cifry z poľa/čísla a
                      // v cykle máme int &, preto meníme priamo cifry z poľa
    cr += v * x;      // cifru v prenásobíme x a prirátam prenos
    v = cr % 10;      // zvyšok je nová cifra
    cr /= 10;         // a to, čo bolo nad 10 je prenos
  }
  while (cr > 0) {  // cifry, čo ostali v cr pridáme
    a.push_back(cr % 10);
    cr /= 10;
  }
}
