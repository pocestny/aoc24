#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

vector<int> a;

int nxt(int i, int skip) {   // inteligentný inkrement, ktorý preskakuje skip
  do i++; while (i == skip); // najprv urob i++, potom opakuj kym i==skip 
  return i;
}

bool check(int skip) {     // skontroluj, či riadok bez skip-teho prvku je rastuci
  int j = nxt(-1, skip);   // j je prvy prvok
  int i = nxt(j, skip);    // i je nasledujuci za j

  while (i < a.size()) {   // kym druhy prvok nepride na koniec
    if (a[i] <= a[j] || a[i] > a[j] + 3) return false;  // ak je porušená podmienka, rovno vráť false
    i = nxt(i, skip);      // posuň i aj j na ďalší prvok
    j = nxt(j, skip);
  }
  return true;
}

bool tst() {                // skontroluj check(i) pre všetky možnosti vyhodenia prvku
  for (int i = -1; i < (int)a.size(); i++)
    if (check(i)) return true; // ak sme nejakú našli, riadok bude dobrý
  return false;                // žiadna možnosť nefunguje, je to zlý riadok
}

int main() {
  string line;
  int s = 0; // tu bude uložený výsledok                  

  while (getline(cin, line)) {
    stringstream str(line);
    int x;
    a.clear();                        // pretože a je globálny, tu ho treba vyprázdniť, 
                                      // aby sme nepridávali k predchádzajúcemu riadku
    while (str >> x) a.push_back(x);  // prečítaj riadok

    if (tst())                        // ak bol dobrý, fajn
      s++;
    else {
      reverse(a.begin(), a.end());    // ak nebol dobrý, skús ho otočiť a otestovať znovu
      if (tst()) s++;
    }
  }
  cout << s << endl;                  // vypíšeme výsledok
}
