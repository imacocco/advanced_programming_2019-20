#include <iomanip>
#include <iostream>

int main() {
  // size matters!
  int a = 1;
  for (int i = 0; i < 33; ++i) {
    a *= 2;
    std::cout << a << std::endl;
  }

  // never ever use == (or !=) with floating point numbers

  // for (double d = 0.1; d != 1.0; d += 0.1)
  //   std::cout << d << std::endl;

  // in order to compare two float numbers: take their difference and check whether
  // the modulus is lower than a threshold

  // std::cout << std::setprecision(50);
  // double d = 0;
  // for (int i = 0; i < 10; ++i) {
  //   d += 0.1;
  //   std::cout << d << std::endl;
  // }
  return 0;
}
