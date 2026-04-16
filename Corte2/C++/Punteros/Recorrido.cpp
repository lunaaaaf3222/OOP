#include <iostream>
using namespace std;

int main(){
	int v[5] = {4, 8, 12, 16, 20}; 
	int* p = v;
	
	for(int i = 0; i < 5; i++){
		cout << "Elemento " << i << " = " << *(p + i) << endl;
	}

	return 0;
}
