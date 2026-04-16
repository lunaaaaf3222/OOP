#include <iostream>
using namespace std;

int main(){
	int v[4] = {10, 20, 30, 40}; 
	
	cout << v[0] << endl;
	cout << *v << endl;
	cout << *(v + 1) << endl;
	cout << *(v + 2) << endl;

	return 0;
}
