#include <iostream>
using namespace std;

int a;

int pridaj(int i, int j) {
  int x = a + i + j;
  a++;
  return x;
}

int main() {
  a = 42;
  cout << pridaj(2, 3) << endl;
  cout << a << endl;
}
