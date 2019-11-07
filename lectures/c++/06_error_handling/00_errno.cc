#include <cmath>
#include <iostream>

int main() {
  double d = std::sqrt(4);
  std::cout << d << " " << errno << std::endl;
//	errno is an existing variable defined on the cmath library that is 0 by default
//	and changes at each operation. each value means a different error
// 	i would be happier to see the precise kind of error
  d = std::sqrt(-4);
  std::cout << d << " " << errno << std::endl;

  return 0;
}
