#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Bl {          // tu si pamätám id, pozíciu začiatku a dĺžku bloku
  int id, pos, len;
};

vector<Bl> b;        // zoznam všetkých blokov

int main() {
  string line;
  getline(cin, line); // prečítam vstupný riadok

  int id = 0, pos = 0;   
  for (int i = 0; i < line.size(); i++) {  // naplním si vector b
    int l = line[i] - '0';
    if (l == 0) continue;
    b.push_back({-1, pos, l});             // pozíciu začiatku si priebežne upravujem
    pos += l;
    if (i % 2 == 0) b.back().id = id++;    // párne bloky majú id, nepárne sú prázdne
  }

  for (int i = b.size() - 1; i >= 0; i--)  // ozdadu prechádzam
    if (b[i].id > 0) {                     // ... plné bloky 
      for (int j = 0; j < i; j++)          // spredu k nemu hľadám
        if (b[j].id == -1 && b[j].len >= b[i].len) {  // prvý prázdny blok, kam sa zmestí
          b[i].pos = b[j].pos;                        // poznačím si, kam som ho presunul
          b[j].pos += b[i].len;                       // skrátim prázdny blok
          b[j].len -= b[i].len;
          break;
        }
    }

  int64_t res = 0;        // tu bude výsledok
  for (Bl x : b)
    if (x.id > 0)         // prejdem všetky plné bloky 
      for (int i = x.pos; i < x.pos + x.len; i++) res += i * x.id;

  cout << res << endl;
}
