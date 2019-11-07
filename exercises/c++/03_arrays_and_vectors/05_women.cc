#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <map>
#include <iterator>
#include <unordered_map>
#include <chrono>

using namespace std::chrono;

//DELARATIONS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//VECTOR 
void load_vector(std::vector<std::string>&, const char*);
void print_without_repetitions(std::vector<std::string>& ,const char*);

template <typename T>
void print_ar(const T&,int);


//MAP
template <typename T>
void load_map(T&,const char*);

template <class T>
void print_map(T&,const char*);




//MAIN+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

int main(){

//	VECTOR VERSION

	std::vector<std::string> v;

	auto t0 = high_resolution_clock::now();

	load_vector(v,"LittleWomen_no_intro.txt");
	print_without_repetitions(v,"out_vec.txt");

	auto t1 = high_resolution_clock::now();

	auto elapsed = duration_cast<milliseconds>(t1-t0);
	std::cout << "VECTOR: " << elapsed.count() << " [milliseconds]" << std::endl;

//	ORDERED MAP

	std::map<std::string,int> ord_map;

	t0 = high_resolution_clock::now();

	load_map(ord_map,"LittleWomen_no_intro.txt");
	print_map(ord_map,"out_ord.txt");

	t1 = high_resolution_clock::now();

	elapsed = duration_cast<milliseconds>(t1-t0);
	std::cout << "MAP: " << elapsed.count() << " [milliseconds]" << std::endl;

//	UNORDERED ORDERED MAP

	std::unordered_map<std::string,int> unord_map;

	t0 = high_resolution_clock::now();

	load_map(unord_map,"LittleWomen_no_intro.txt");
	print_map(unord_map,"out_unord.txt");

	t1 = high_resolution_clock::now();

	elapsed = duration_cast<milliseconds>(t1-t0);
	std::cout << "UNORDERED MAP: " << elapsed.count() << " [milliseconds]" << std::endl;
	
	return 0;

}

//DEFINITIONS+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//VECTOR STUFF

void load_vector(std::vector<std::string> &v, const char* file){

//	std::vector<std::string> v;
	std::string appo{0};
	std::ifstream in{file};
//	in.open(file);
//	if (!in.good()){
//		std::cerr << "cannot open file!" << std::endl;
//		abort();
//	}

	while(!in.eof()){
//		std::cout << appo;
		in >> appo;
		// remove punctuations
		appo.erase (std::remove_if (appo.begin (), appo.end (), ispunct), appo.end ());
		// transform to lower case
		std::transform(appo.begin(), appo.end(), appo.begin(),[](unsigned char c){ return std::tolower(c); });

		v.push_back(appo);
	}

//	in.close();
//	std::cout << "number of loaded words:\t" << v.size() << std::endl;

	return;

}

//--------------------------------------------------------------------------------------

void print_without_repetitions(std::vector<std::string> &v, const char* file){

	std::sort( v.begin(), v.end() );
//	std::cout<<"sorted"<<std::endl;

	int counter{1};

	std::ofstream out{file};

	for (unsigned int i = 1; i < v.size(); ++i){
		if (v[i]==v[i-1]){
//			v.erase(v.begin()+i);
			counter+=1;
//			counter.erase(counter.begin()+i);
//			std::cout<<i<<std::endl;
		}
		else{
//			std::cout << i << "\t" << counter << std::endl;
			out << v[i-1] << "\t" << counter << std::endl;
			counter = 1 ;

		}
	}

//	std::cout << v.size() << "\t" << counter.size() << std::endl;

	return;
}

//--------------------------------------------------------------------------------------

template <typename T>
void print_ar(const T& a,int N){

	for (int i = 0; i<N;++i)
		std::cout<<a[i]<<std::endl;
	
	return;

}

//--------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------

//MAP STUFF


template <typename T>
void load_map(T& mappa, const char* filein){


	std::string appo{0};
	std::ifstream in{filein};

	while(!in.eof()){
//		std::cout << appo;
		in >> appo;
		// remove punctuations
		appo.erase (std::remove_if (appo.begin (), appo.end (), ispunct), appo.end ());
		// transform to lower case
		std::transform(appo.begin(), appo.end(), appo.begin(),[](unsigned char c){ return std::tolower(c); });

		mappa[appo]++;
	
	}

	//	std::cout << "number of loaded words:\t" << v.size() << std::endl;

	return;
}

//--------------------------------------------------------------------------------------

template <typename T>
void print_map(T& mappa, const char* fileout){

	std::ofstream out{fileout};

	for(auto cursor = mappa.begin(); cursor!=mappa.end(); cursor++){

		out<<cursor->first;
        out<< '\t'<<cursor->second<<std::endl; 
    }

	return;
}