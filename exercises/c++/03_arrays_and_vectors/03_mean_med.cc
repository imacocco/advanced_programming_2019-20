#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<double> load(const char*);

template <typename T>
void print_ar(const T&,int);

template <typename T> 
double Mean(const T&,int);

template <typename T>
double Median(T,int);

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(int argc, char const *argv[]){

	std::vector<double> v = load("temperatures.txt");

//	print_ar(v,v.size());

	std::cout << v.size() <<  "mean temperature: " << Mean(v,v.size()) <<  "\nmedian temperature: "	<< Median(v,v.size()) <<std::endl;

//	print_ar(v,v.size());

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

std::vector<double> load(const char* file){

	std::ifstream in;
	in.open(file);
	double temp{0};
	if (!in){
		std::cerr<<"could not open file correctly, abort"<<std::endl;
		abort();
	}

	std::vector<double> v;

	while(!in.eof()){
		in >> temp;
		v.push_back(temp);
//		std::cout << temp << "\t" << v.size() << "\t" << v[v.size()-1] << std::endl;
	}

	return v;		

}


template <typename T>
void print_ar(const T& a,int N){

	for (int i = 0; i<N;++i)
		std::cout<<a[i]<<std::endl;
	
	return;

}

template <typename T> 
double Mean(const T& a,int N){

	double mean{0};

	for (auto& x : a)
		mean+=x;

	return mean/N;
}

template <typename T>
double Median(T v, int dim){

	std::sort( v.begin(), v.end() );

	return v[dim/2];


}