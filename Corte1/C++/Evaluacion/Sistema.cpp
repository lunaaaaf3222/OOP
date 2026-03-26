#include <iostream>
#include <string>
using namespace std;

const int MAX_ESTUDIANTES = 10;
const int NUM_EVALUACIONES = 3;

class Estudiante {
private:
    string codigo;
    string nombre;
    int edad;
    float notas[NUM_EVALUACIONES];

public:
    
    Estudiante() {
        codigo = "";
        nombre = "";
        edad = 0;
        for (int i = 0; i < NUM_EVALUACIONES; i++) {
            notas[i] = 0;
        }
    }

    
    Estudiante(string cod, string nom, int ed) {
        codigo = cod;
        nombre = nom;
        edad = ed;
        for (int i = 0; i < NUM_EVALUACIONES; i++) {
            notas[i] = 0;
        }
    }

    
    string getCodigo() { 
	 return codigo; 
	}
	
    string getNombre() {
	 return nombre; 
	}
	
    int getEdad() { 
	 return edad; 
	}

    
    void setNota(int posicion, float nota) {
        if (posicion >= 0 && posicion < NUM_EVALUACIONES) {
            notas[posicion] = nota;
        }
    }

    float getNota(int posicion) {
        if (posicion >= 0 && posicion < NUM_EVALUACIONES) {
            return notas[posicion];
        }
        return 0;
    }

    
    float calcularPromedio() {
        float suma = 0;
        for (int i = 0; i < NUM_EVALUACIONES; i++) {
            suma += notas[i];
        }
        return suma / NUM_EVALUACIONES;
    }

 
    void mostrar() {
        cout << "Código: " << codigo
             << " | Nombre: " << nombre
             << " | Edad: " << edad
             << " | Notas: ";

        for (int i = 0; i < NUM_EVALUACIONES; i++) {
            cout << notas[i] << " ";
        }

        cout << "| Promedio: " << calcularPromedio() << endl;
    }
};


int buscarEstudiante(Estudiante estudiantes[], int totalEstudiantes, string codigo) {
    for (int i = 0; i < totalEstudiantes; i++) {
        if (estudiantes[i].getCodigo() == codigo) {
            return i; 
        }
    }
    return -1; 
}


float leerNota(int numeroNota) {
    float nota;
    do {
        cout << "Nota " << numeroNota << ": ";
        cin >> nota;
        if (nota < 0 || nota > 5) {
            cout << "Nota inválida. Debe estar entre 0 y 5.\n";
        }
    } while (nota < 0 || nota > 5);
    return nota;
}

int main() {
    cout << "=== Bienvenido al Sistema de Gestión de Estudiantes ===" << endl;

    Estudiante estudiantes[MAX_ESTUDIANTES];
    int totalEstudiantes = 0;
    int opcion;

    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1. Registrar estudiante\n";
        cout << "2. Mostrar todos los estudiantes\n";
        cout << "3. Buscar estudiante por código\n";
        cout << "4. Actualizar notas de un estudiante\n";
        cout << "5. Mostrar promedio de un estudiante\n";
        cout << "6. Mostrar estudiantes aprobados y reprobados\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            if (totalEstudiantes < MAX_ESTUDIANTES) {
                string codigo, nombre;
                int edad;

                cout << "Ingrese código: ";
                cin >> codigo;

                if (buscarEstudiante(estudiantes, totalEstudiantes, codigo) != -1) {
                    cout << "Error: Ya existe un estudiante con ese código.\n";
                    continue;
                }

                cout << "Ingrese nombre: ";
                cin.ignore();
                getline(cin, nombre);

                do {
                    cout << "Ingrese edad: ";
                    cin >> edad;
                    if (edad <= 0) {
                        cout << "Edad inválida. Debe ser mayor que 0.\n";
                    }
                } while (edad <= 0);

                estudiantes[totalEstudiantes] = Estudiante(codigo, nombre, edad);

                cout << "Ingrese las " << NUM_EVALUACIONES << " notas (si tiene decimales separelas con puntos):\n";
                for (int i = 0; i < NUM_EVALUACIONES; i++) {
                    float nota = leerNota(i + 1);
                    estudiantes[totalEstudiantes].setNota(i, nota);
                }

                totalEstudiantes++;
                cout << "Estudiante registrado correctamente.\n";

            } else {
                cout << "No se pueden registrar más estudiantes.\n";
            }
        }

        else if (opcion == 2) {
            if (totalEstudiantes == 0) {
                cout << "No hay estudiantes registrados.\n";
            } else {
                cout << "\n=== LISTA DE ESTUDIANTES ===\n";
                for (int i = 0; i < totalEstudiantes; i++) {
                    estudiantes[i].mostrar();
                }
            }
        }

        else if (opcion == 3) {
            string codigo;
            cout << "Ingrese código a buscar: ";
            cin >> codigo;

            int posicion = buscarEstudiante(estudiantes, totalEstudiantes, codigo);

            if (posicion != -1) {
                cout << "\nEstudiante encontrado:\n";
                estudiantes[posicion].mostrar();
            } else {
                cout << "Estudiante no encontrado.\n";
            }
        }

        else if (opcion == 4) {
            string codigo;
            cout << "Ingrese código del estudiante: ";
            cin >> codigo;

            int posicion = buscarEstudiante(estudiantes, totalEstudiantes, codigo);

            if (posicion != -1) {
                cout << "Ingrese las nuevas " << NUM_EVALUACIONES << " notas:\n";
                for (int i = 0; i < NUM_EVALUACIONES; i++) {
                    float nota = leerNota(i + 1);
                    estudiantes[posicion].setNota(i, nota);
                }
                cout << "Notas actualizadas correctamente.\n";
            } else {
                cout << "Estudiante no encontrado.\n";
            }
        }

        else if (opcion == 5) {
            string codigo;
            cout << "Ingrese código del estudiante: ";
            cin >> codigo;

            int posicion = buscarEstudiante(estudiantes, totalEstudiantes, codigo);

            if (posicion != -1) {
                cout << "Promedio de " << estudiantes[posicion].getNombre()
                     << ": " << estudiantes[posicion].calcularPromedio() << endl;
            } else {
                cout << "Estudiante no encontrado.\n";
            }
        }

        else if (opcion == 6) {
            if (totalEstudiantes == 0) {
                cout << "No hay estudiantes registrados.\n";
            } else {
                cout << "\n=== ESTUDIANTES APROBADOS Y REPROBADOS ===\n";
                for (int i = 0; i < totalEstudiantes; i++) {
                    float promedio = estudiantes[i].calcularPromedio();
                    estudiantes[i].mostrar();

                    if (promedio >= 3.0) {
                        cout << "Estado: APROBADO\n";
                    } else {
                        cout << "Estado: REPROBADO\n";
                    }
                    cout << "-------------------------\n";
                }
            }
        }

        else if (opcion == 7) {
            cout << "Gracias por usar este programa nos vemos pronto.\n";
        }

        else {
            cout << "Opción inválida.\n";
        }

    } while (opcion != 7);

    return 0;
}
