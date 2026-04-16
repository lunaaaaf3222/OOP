#include <iostream>
using namespace std;

int main(){
	int n = 4
	int* v = new int[n];
	
	for (int i = 0; i < n; i++){
		v[i] = (i + 1) * 10;
	}
	
	for (int i = 0; i < n; i++){
		cout << v[i] << " ";
 	}
	cout << endl;
	
	delete[] v;
	v = nullptr; 
	
	return 0;
}
