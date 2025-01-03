#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  map<int, string> m;
  m[42] = "kapybara";
  m[12] = "krab";

  for (int i = 0; i < 2; i++)
    for (auto x : m) {
      cout << x.first << " " << x.second << "! ";
      x.second[0] = 'S';
      x.second.pop_back();
    }
}
