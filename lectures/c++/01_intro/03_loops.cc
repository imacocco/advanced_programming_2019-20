#include <iostream>

int main() {
  for (int i = 0; i < 10; ++i) {
    std::cout << i << " "; // if the action is just one line, {} can be omitted
  
  // for(;;) gives on infinite loop
  // -before the first ; you put operations done only before the first operation
  // -the instruction between the ; ; is checked every loop
  // -the instruction after the second ; is done every loop
  }
  
  // std::cout << i << '\n';	// error, i is out of scope

  std::cout << std::endl;

  int i{}; //initialization to 0

  while (i < 10)
    std::cout << i++ << " ";

  std::cout << "\n after while i is " << i << "\n";

  std::cout << std::endl;


  do {
    std::cout << "inside do \n";
  } while (i < 2); // note ; condition checked at the end of the loop


  // BREAK: exit the innermost loop
  std::cout << "\n break at i=2" << std::endl;

  for (i = 0; i < 5; ++i) {
    if (i == 2)
      break;
    std::cout << i << std::endl;
  }


  // CONTINUE: go to next iteration
  std::cout << "\n continue at i=2" << std::endl;

  for (i = 0; i < 5; ++i) {
    if (i == 2)
      continue;
    std::cout << i << std::endl;
  }

  std::cout << std::endl;
}
