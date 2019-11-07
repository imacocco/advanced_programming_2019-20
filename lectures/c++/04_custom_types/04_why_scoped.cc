#include <iostream>

enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

using namespace std;

int main() {
  cout << nov << endl;
  // cout << dec << endl;		if i uncomment this line i cannot compile 
  // as ambiguity as dec is defined  also in namespace std! PANIC

 // in order to avoid using std::cout everytime, in this case i can do:
  // using std::cout
  // using std::endl

// now i do no need anymore std::cout everytime

  return 0;
}
