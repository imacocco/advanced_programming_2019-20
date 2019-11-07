#include <iostream>
#include <cstring>

using namespace std;

template <typename type>
type* intialise(const unsigned int);

template <typename T>
void reverse(const unsigned int, T*);

//--------------------------------------------------------------------

int main(){

	unsigned int N;
	cout << "inserisci dimensione del vettore" << endl;
	cin >> N;
	double* vect = intialise<double>(N);	

	for (size_t i = 0; i < N; ++i){
		cout << vect[i] << endl;
	}

	reverse(N, vect);

	delete[] vect;

	return 0;

}

//--------------------------------------------------------------------

template <typename type>
type* intialise(const unsigned int dim){

	type temp{0};
	type* v{new type[dim]};

	for (size_t i = 0; i < dim; ++i){
		cout<<"insert " << i+1 <<"th element"<<endl;
		cin >> temp;
		v[i]=temp;
	}

	return v;

}

template <typename T>
void reverse(const unsigned int dim, T* v){

	for (size_t i = 0; i < dim; ++i){

		cout <<dim-i-1<<"\t"<< v[dim-i-1] << endl;
	}

}