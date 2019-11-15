#include <iostream>
#include <utility>
#include <memory>
#include "ap_error.h"

//ENUM INESTION METHOD-----------------------------------------------

enum class Insertion_method { push_back, push_front };

//CLASS LIST DECLARATION---------------------------------------------

template <class value_type>
class List {
	
private:
	
	// private struct node with the proper value_type
	struct node {
		std::unique_ptr<node> next;
		value_type value;

		// implement suitable constructor(s) for node
		node(const value_type& v, node* p): next{p}, value{v} {};
		node(value_type& v, node* p): next{p},value{std::move(v)} {};
		node(const std::unique_ptr<node>& p): value{p->value}{
			if (p->next) next = std::make_unique<node>(p->next);
		}
		// copy and move semantics if needed
	
		// destructor
//		~node(){};
	};

	std::unique_ptr<node> head;
//	std::size_t _size;

	// append the newly created node at the end of the list
	void push_back(const value_type& v);
	void push_back(value_type&& v);
	// insert the newly created node in front of the list
	void push_front(const value_type& v);
//	void push_front(value_type&& v);

	node* tail();

public:

	List() noexcept = default;

	//move constructor, no exceptions, it's just a swap
	List(List && l) noexcept = default;

	List& operator=(List&& l) noexcept = default;
	//copy constructor
	List(const List& l);
	//copy assignement
	List& operator=(const List& l);

	// insert a new node with the value v according to the method m
	// this method should be used to fill the list
	void insert(const value_type& v, const Insertion_method m);
	void insert(value_type&& v, const Insertion_method m);

	//i can make the ostram operator friend so that it can access to private members
	//i need to set it as a template as it
	template <class t>
	friend std::ostream& operator<<(std::ostream&, const List<t>&);

	// return the size of the list
//	std::size_t size() const {return _size;}

	// delete all the nodes of the list
	void reset();
	
	// constructor(s) for List
	~List(){}
	// copy semantics
	// move semantics
		
	// destructor
};

//DEFINITIONS-------------------------------------------------------

template <class T>		//since it is a freind i can access private data
std::ostream& operator<<(std::ostream& os, const List<T>& l){
	auto tmp = l.head.get();
	while(tmp){
		os << tmp->value << " ";		//print value
		tmp = tmp->next.get();			//move to next node
	}

	return os;
}


template <class T>
typename List<T>::node* List<T>::tail(){
	auto tmp = head.get();
	while(tmp->next)
		tmp = tmp->next.get();
	
	return tmp;
}


template <class T>
void List<T>::insert(const T& v, const Insertion_method m){

	if (!head){
//		head.reset(new node{v,nullptr});	from c++14 i can use the next line, which uses move assignement
		head = std::make_unique<node>(v,nullptr);
		return;
	}

	switch(m){
		case Insertion_method::push_back:
			push_back(v);
			break;

		case Insertion_method::push_front:
			push_front(v);
			break;

		default:
			AP_ERROR(false) << "Unknown insertion method";
			break;
	}

}


template <class T>
void List<T>::push_back(const T& v){

	node* last = tail();
//	last->next.reset(new node{v,nullptr})		or better:
	last->next = std::make_unique<node>(v,nullptr);

};

template <class T>
void List<T>::push_front(const T& v){
//	auto h = head.release();
//	auto new_node = new node{v,h};
//	head.reset(new_node);

//	head.reset(new node{v, head.release()})

	head = std::make_unique<node>(v.head.release());
};

template <class T>
List<T>::List(const List& l){
//	auto tmp = l.head.get();
//	while(tmp){
//		insert(tmp->value,Insertion_method::push_back);
//		tmp = tmp->next.get();
//	}

	head = std::make_unique<node>(l.head);
}

/*NOTES

-struct node inside class list; useful as it comprehend the same template parameter of List
-

*/


int main(){

	try{

		List<int> l{};

		l.insert(4,Insertion_method::push_back);
		l.insert(5,Insertion_method::push_back);
		l.insert(3,Insertion_method::push_front);

		std::cout << l << std::endl;

		auto ol = l;

		ol.insert(432,Insertion_method::push_front);

	}catch(std::exception& e){
		std::cerr << e.what() << std::endl;

	}catch(...){
		std::cerr << "Unknown exception" << std::endl;
	}

	return 0;
}