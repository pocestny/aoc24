#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  regex cislo("[1-9][0-9]*");
  smatch match;
  string line = "ked12som 093isiel4040cez000891horu0808";

  for (string s = line; regex_search(s, match, cislo); s = match.suffix())
    cout << match[0] << endl;
}
