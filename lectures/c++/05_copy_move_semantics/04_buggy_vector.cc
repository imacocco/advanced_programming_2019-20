#include <iostream>

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

 public:
  explicit Vector(const std::size_t length)
      : elem{new T[length]{}}, _size{length} {}
// T[length] would do malloc, T[length]{} initialize all values to 0
// 
  ~Vector() { delete[] elem; }

// overloading of [], with and without const:
  const T& operator[](const std::size_t& i) const { return elem[i]; }
  T& operator[](const std::size_t& i) { return elem[i]; }

  std::size_t size() const { return _size; }

// range-for loop, since c++11
  const T* begin() const { return elem; }
  T* begin() { return elem; }

  const T* end() const { return elem + size(); }
  T* end() { return elem + size(); }
};

void print(const Vector<int> & v){
  for(auto x: v)
    std::cout << x << std::endl;
}

int main() {
  Vector<int> v1{3};
  v1[0] = 1;
  v1[1] = 2;
  v1[2] = 3;

  {
    auto it = v1.begin();
    auto stop = v1.end();
    for (; it!=stop; ++it)
    {
      const auto x = *it;
    }
  }

  //print(5); // do compile and works if I don't put explicit to the vector constructor
  // it construct an element vector on the fly

  // this for loop can shortly be written as following one

  std::cout << "v1: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  Vector<int> v2{v1};  // default copy constructor

  std::cout << "v2 after default copy ctor: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v1[0] = 99;

  std::cout << "v2 after v1 has been changed: ";
  for (const auto x : v2)
    std::cout << x << " ";
  std::cout << std::endl;

  v2[1] = -999;

  std::cout << "v1 after v2 has been changed: ";
  for (const auto x : v1)
    std::cout << x << " ";
  std::cout << std::endl;

  return 0;
}
