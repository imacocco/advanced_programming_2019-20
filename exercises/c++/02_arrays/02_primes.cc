#include <iostream>

using namespace std;

int main(){
	
	int dim{100};
	int allocated{1};
	int* primes{new int[100]};
	primes[0]=2;
	int candidate{3};
	bool found;
	unsigned int remainder{0};

	while(allocated<101){

		for (int i = 0; i < allocated; ++i){
			remainder=candidate%primes[i];
			if (remainder==0){
//				candidate+=2;
				found = 0;
				break;
			}
			else{
				found = 1;
			}	

		}
		if (found){
			
			primes[allocated]=candidate;
			allocated++;
		}

		candidate+=2;

	}

	for (int i = 0; i < dim; ++i){
		cout << primes[i] << endl;
	}

	return 0;
}