#include <sstream>
#include <iostream>
#include <iomanip>
#include <array>
#include <utility>


template <typename TT>
void transpose(TT&,int,int);

template <typename T>
void print_ma(const T&,int,int);

template <typename T>
void print_ar(const T&,int);


int main(int arcg,char const *argv[]){
	
	const size_t N{8};

	std::array<int,N> M{0,1,2,3,4,5,6,7};

	std::size_t rows;
	std::size_t cols;

  	std::istringstream is{argv[1]};
  	is >> rows;
  	std::istringstream is1{argv[2]};
  	is1 >> cols;

	std::cout << rows << "\t" << cols << std::endl;

	print_ar(M,N);
	
	print_ma(M,rows,cols);

	transpose(M,rows,cols);

	print_ma(M,cols,rows);

	print_ar(M,N);
	return 0;
}


//PORCODIOOOOOOOOOOOO

template <typename TT>
void transpose(TT& a, int n_rows, int n_columns){

	for (int i = 0; i < n_rows; ++i){

		for (int j=0; j < std::min(i,n_columns); ++j){

			std::swap(a[i*n_columns+j],a[j*n_rows+i]);
		}
	}

	return;
}

template <typename T>
void print_ma(const T& p, int row, int col) {

	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j)
			std::cout << std::setw(2) << p[i * col + j] << " ";
		std::cout << std::endl;
  	}
	
	std::cout << std::endl;

  	return;
}

template <typename T>
void print_ar(const T& a,int N){

	for (int i = 0; i<N;++i){
		std::cout<<a[i]<<std::endl;
		
	}

	return;

}


