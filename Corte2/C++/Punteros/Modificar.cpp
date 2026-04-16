#include <iostream>
using namespace std;

int main(){
	int x = 25; 
	int* p = &x;
	
	*p = 80;
	
	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;
	
	return 0;
}
