#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  regex iban("SK[0-9]{2}([0-9]{4})0*([1-9][0-9]*)");
  smatch match;
  string line = "Tu si SKUSME  ukazkovy IBAN:SK6807200002891987426353.";

  for (string s = line; regex_search(s, match, iban); s = match.suffix())
      cout << "banka=" << match[1] << " ucet=" << match[2] << endl;
}
