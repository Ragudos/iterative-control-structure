#include <iostream>

using namespace std;

int main() {
  const int LAYERS = 4;

  int currL = 1;

  do {
    int currNum = 1;

    do {
      cout << currNum << " ";

      currNum += 1;
    } while (currNum <= currL);

    cout << endl;

    currL += 1;
  } while (currL <= LAYERS);

  return 0;
}