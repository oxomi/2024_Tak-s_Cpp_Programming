#include <iostream>

void swap (int &rx, int &ry) {
  int temp;

  temp = rx;
  rx = ry;
  ry = temp;
}

int main() {
  int x = 10, y = 20;
  swap(x, y);
  std::cout << x << " " << y << std::endl;

  return 0;
}