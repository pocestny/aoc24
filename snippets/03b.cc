#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  regex mul("(do\\(\\))|(don't\\(\\))|mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
  smatch m;
  string line;
  int res = 0;

  bool enabled = true;
  while (getline(cin, line)) {
    for (string s = line; regex_search(s, m, mul); s = m.suffix()) {
      if (m[1].matched)
        enabled = true;
      else if (m[2].matched)
        enabled = false;
      else if (enabled)
        res += stoi(m[3]) * stoi(m[4]);
    }
  }

  cout << res << endl;
}
