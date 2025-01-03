#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> a;

int main() {
  string line;
  getline(cin, line);  // prečítam zo vstupu celý riadok

  int n = 0;
  for (char c : line) n += c - '0';  // zrátam si jeho dĺžku po rozbalení

  a.resize(n, -1);  // vector a nastavím na vyrátanú veľkosť a zaplním -1

  int id = 0,   // id je prvé voľné id súboru
      pos = 0;  // pos je pozícia v a, kde práve píšem

  for (int i = 0; i < line.size(); i++) {  // prechádzam cez vstup
    int l = line[i] - '0';  // dĺžka aktuálneho bloku (súboru alebo voľného miesta)

    if (l == 0) continue;  // nulová dĺžka sa v mape neprejaví

    if (i % 2 == 0) {  // na párnych pozíciách je súbor
      for (int j = 0; j < l; j++)
        a[pos++] = id;  // zapíšem id do a; zápis a[pos++] znamená  "použi a[pos] a potom urob pos+=1"
                        // a[++pos] by znamenalo "najprv urob pos+=1 a potom použi a[pos]"
      id++;             // nastav ďalšie  voľné id
    } else
      pos += l;  // bolo to prázdne miesto, len posuň pos
  }

  // tu si len pre kontrolu vypíšem rozbalený vstup
  for (int i = 0; i < a.size(); i++)
    if (a[i] < 0)
      cout << ".";
    else
      cout << a[i];
  cout << endl;
}
