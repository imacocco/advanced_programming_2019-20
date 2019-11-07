#include <iostream>
#include <string>
#include <cmath>

void get_int(double,bool*);

int main(){
	double num{0};
	int temp{0};
	bool check{0};
	while(!(check)){
		while(!(std::cin >> num)){
			std::cin.clear();
			std::cin.ignore();
			std::cerr<<"I want a number, not a string"<<std::endl;
		}
		get_int(num,&check);
//		get_float()
//		temp=num;	
//		if( (num-temp)<10e-6 ){
//			std::cout<<num<<std::endl;
	}	
	std::cout<<num<<std::endl;
	
}

void get_int(double test,bool *a){
	int temp = test;
	double diff = test - double(temp);
	std::cout << test << "\t" << temp << "\t" << diff << std::endl;

	if ( diff < 10e-10){
		*a=1;
	}
	else{
		*a=0;
		std::cerr<<"I want an integer number!!"<<std::endl;
	}
}