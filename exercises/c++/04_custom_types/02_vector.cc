#include <iostream>
#include <vector>

template <typename T>
class Vector {
  T* elem;
  std::size_t _size;

 public:
  Vector(const std::size_t size) : elem{new T[size]}, _size{size} {}

  // automatically release the acquired memory
  ~Vector() { delete[] elem; }

  // try to remove the const and recompile
  auto size() const { return _size; }

  T& operator[](const std::size_t i) { return elem[i]; }

  // try to comment this line and recompile -> in order for the ostream template to work!!
  const T& operator[](const std::size_t i) const { return elem[i]; }

  const T* begin() const { return &elem[0]; }
  T* begin() { return &elem[0]; }

  const T* end() const { return &elem[_size]; }
  T* end() { return &elem[_size]; }
};


template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  for (const auto & i : v)
    os << i << std::endl;
  return os;
}

int main(){

  Vector<int> a{10};
  for (auto & x : a)
    x = 5;

  std::cout << a << std::endl;
}