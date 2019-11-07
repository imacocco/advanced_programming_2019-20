#include <iostream>
#include <utility>
#include <memory>


enum class Insertion_method { push_back, push_front };


template <class value_type>
class List {
 public:
  // insert a new node with the value v according to the method m
  // this method should be used to fill the list
  void insert(const value_type& v, const Insertion_method m);

  // return the size of the list
  std::size_t size() const;

  // delete all the nodes of the list
  void reset();

  // constructor(s) for List
  
  // copy semantics
  // move semantics
  
  // destructor

 private:
 
  // private struct node with the proper value_type
  struct node {
    value_type value;
    std::unique_ptr<node> next;

    // implement suitable constructor(s) for node
    
    // copy and move semantics if needed
    
    // destructor
  };

  // append the newly created node at the end of the list
  void push_back(const value_type& v);

  // insert the newly created node in front of the list
  void push_front(const value_type& v);

  std::unique_ptr<node> head;
  std::size_t size;
};

template <class T>
std::ostream& operator<<(std::ostream& os, const List<T>& l);