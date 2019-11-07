#include <iostream>
#include <cstring>
#include <cmath>

int main(){

	double num{0};
	std::string unit;

	do{

	std::cout << "insert the measure with its relative unit (insert 0 0 to exit)" << std::endl;

	std::cin >> num >> unit;

	if (unit=="m"){
		std::cout << num << " m" << std::endl;
	}
	else{if(unit=="dm")
		std::cout << num/10. << " m" << std::endl;
    	else{if(unit=="cm")
		std::cout << num/100. << " m" << std::endl;
    	else{if(unit=="mm")
		std::cout << num/1000. << " m" << std::endl;
    	else{if(unit=="um")
		std::cout << num/1e6 << " m" << std::endl;
    	else{if(unit=="nm")
		std::cout << num/1e9 << " m" << std::endl;
    	else{if(unit=="pm")
		std::cout << num/1e12 << " m" << std::endl;
    	else{if(unit=="dam")
		std::cout << num*10. << " m" << std::endl;
    	else{if(unit=="hm")
		std::cout << num*100. << " m" << std::endl;
    	else{if(unit=="km")
		std::cout << num*1000. << " m" << std::endl;
    	else{if(unit=="Mm")
		std::cout << num*1e6 << " m" << std::endl;
    	else{if(unit=="Gm")
		std::cout << num*1e9 << " m" << std::endl;
    	else{if(unit=="inch")
		std::cout << num*0.0254 << " m" << std::endl;
    	else{if(unit=="ft")
		std::cout << num/3.2808 << " m" << std::endl;
		else{if(unit=="0") break;
    	else{std::cout<<"Choose an appropriate unit of measure!!"<<std::endl;
    	}}}}}}}}}}}}}}}
    }
    while(num!=0);
	
	return 0;
}