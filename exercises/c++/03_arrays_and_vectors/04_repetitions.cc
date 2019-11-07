#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

//using namespace std;

std::vector<std::string> load();

void print_without_repetitions(std::vector<std::string>);

template <typename T>
void print_ar(const T&,int);


int main(){

	std::vector<std::string> v = load();

	print_ar(v,v.size());

	print_without_repetitions(v);

	return 0;

}



std::vector<std::string> load(){

	std::vector<std::string> v;
	std::string appo{0};
	std::cout << "insert a word (type QUIT to escape)" << std::endl;
	std::cin >> appo;

	while(appo!="QUIT"){
		
		v.push_back(appo);
		std::cout << "insert a word (type QUIT to escape)" << std::endl;
		std::cin >> appo;

	}

	std::cout << "nymber of loaded words:\t" << v.size() << std::endl;

	return v;

}


void print_without_repetitions(std::vector<std::string> v){

	std::sort( v.begin(), v.end() );
	for (unsigned int i = 1; i < v.size(); ++i){
		if (v[i]==v[i-1]){
			v.erase(v.begin()+i);
		}
	}

	print_ar(v,v.size());

	return;
}

template <typename T>
void print_ar(const T& a,int N){

	for (int i = 0; i<N;++i)
		std::cout<<a[i]<<std::endl;
	
	return;

}