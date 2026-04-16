#include <iostream>
using namespace std;

int main(){
	int* p = new int;
	
	*p = 55;
	cout << *p << endl;
	
	delete p;
	p = nullptr

	return 0;
}
