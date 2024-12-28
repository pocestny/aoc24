#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main() {
  regex mul("mul\\(([0-9]{1,3}),([0-9]{1,3})\\)");
  smatch m;
  string line;
  int res = 0;

  while (getline(cin, line)) {
    for (string s = line; regex_search(s, m, mul); s = m.suffix())
      res += stoi(m[1]) * stoi(m[2]);
  }

  cout << res << endl;
}
