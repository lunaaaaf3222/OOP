#include <iostream>
#include <string>
using namespace std;

class Persona{
public:
  string nombre;
  int edad;
  
  void saludar(){
    cout << "Hola,soy " << nombre << " y tengo " << edad << " años.\n";
}
};
int main(){

 Persona p1;
 Persona p2;
 Persona p3;

 p1.nombre = "Luna";
 p1.edad = 17;
 p2.nombre = "Mary";
 p2.edad = 48;
 p3.nombre = "Juan";
 p3.edad = 23;

 p1.saludar();
 p2.saludar();
 p3.saludar();
 return 0;
}