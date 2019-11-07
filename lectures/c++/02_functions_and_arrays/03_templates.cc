#include <iostream>

template <typename T>
T dwim(const T a, const T b);

int main() {
  int a{5}, b{7};
  double c{3.332}, d{7.7};
  float e{23.4}, f{3.34e2};
  char g{'0'}, h{'6'};

  std::cout << dwim<int>(a, b) << '\n'    
  //when i call the function i can declare the type explicitly (usually the compiler is able to do it)
            << dwim(c, d) << '\n'
            << dwim(e, f) << '\n'
            << dwim(g, h) << std::endl;
  return 0;
}

template <typename T>
T dwim(const T a, const T b) {
  return a + b;
}
