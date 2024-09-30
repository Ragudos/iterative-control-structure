#include <iostream>

using namespace std;

int main() {
  const int LAYERS = 4;

  for (int currL = 1; currL <= LAYERS; ++currL) {
    for (int currNum = 1; currNum <= currL; ++currNum) {
      cout << currNum << " ";
    }

    cout << endl;
  }

  return 0;
}
