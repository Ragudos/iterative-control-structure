#include <iostream>

using namespace std;

int main() {
  const int LAYERS = 4;

  int currL = 1;

  while (currL <= LAYERS) {
    int currNum = 1;

    while (currNum <= currL) {
      cout << currNum << " ";

      currNum += 1;
    }

    cout << endl;

    currL += 1;
  }

  return 0;
}