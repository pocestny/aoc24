#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

int main() {
  regex slovo("\\(([a-z]*)\\)|\\[([a-z]*)\\]");
  smatch match;
  string line = "(mama) a (ema) [mleli] malu (lamu)";
  vector<string> result;

  for (string s = line; regex_search(s, match, slovo); s = match.suffix())
    if (match[1].matched)
      result.push_back(match[1]);
    else {
      string s = match[2];  // match je v skutočnosti niečo zložité, musím si to
                            // dať do stringu, aby som to vedel otočiť
      reverse(s.begin(), s.end());
      result.push_back(s);
    }
  reverse(result.begin(), result.end());

  for (string &s : result)  // iterovanie cez vector
                            // Bez & by v s bola postupne kópia všetkých prvkov z result.
                            // Znak & pred s znamená, že sa pristupuje priamo k tej hodnote,
                            // čo je uložená v result.  pozri str. 129 v tutoriáli
    cout << s << " ";  
}
