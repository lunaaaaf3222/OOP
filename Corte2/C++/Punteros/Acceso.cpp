#include <iostream>
using namespace std;

class Persona {
public:
	string nombre;
	
	void saludar(){
		cout << "Hola, soy " << nombre << endl;
	}
};

int main(){
	Persona* p = new Persona;
	p->nombre = "Ana";
	p->saludar();
	
	delete p;
	p = nullptr;
	return 0; 
	
}
