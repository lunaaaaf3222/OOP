#include <iostream>
using namespace std;

void intercambiar (int *a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int x = 3; 
	int y = 9;
	
	intercambiar(&x, &y);
	cout << "x = " << x << " , y = " << y << endl;

	return 0;
}
