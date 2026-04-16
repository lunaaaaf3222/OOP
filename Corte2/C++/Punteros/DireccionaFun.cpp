#include <iostream>
using namespace std;

void duplicar (int *p){
	if(p != nullptr){
		*p = (*p) * 2;
	}
}

int main(){
	int numero = 7; 
	duplicar(&numero);
	
	cout << numero << endl;

	return 0;
}
