while (zero.size() > 0) {  // kým je nejaká stránka, do ktorej nevedie žiadna šípka
  int u = zero.back();     // zober jednu takú
  zero.pop_back();         // vyhoď ju zo zoznamu zero 
  sorted.push_back(u);     // a pridaj na koniec sorted

  for (int w : out[u]) {   // teraz prejdi všetky relevantné šípky, ktoré odchádzajú z u
    indeg[w]--;            // keď vyhadzujem u, w má o 1 vchádzajúcu šípku menej
    if (indeg[w] == 0) zero.push_back(w);  // vznikla nová stránka, do ktorej nikto nejde
  }
}
