#include <iostream>
#include <string>

int main()
{
	int count{1};
	std::string appo;
	std::getline(std::cin,appo);	
//	std::string line;
	for(std::string line; std::getline(std::cin,line);){
		if (line==appo){
			count++;
//			std::cout << line << std::endl;
		}
		else{
			std::cout << "\t" << count << " " << appo << std::endl;;
			appo=line;
			count = 1;
		}
	}


//	std::cout << line << std::endl;
	return 0;
}