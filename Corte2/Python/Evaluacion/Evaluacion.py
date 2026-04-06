MAX_ESTUDIANTES = 10
NUM_EVALUACIONES = 3

class Estudiante:
    def __init__(self, codigo="", nombre="", edad=0):
        self.codigo = codigo
        self.nombre = nombre
        self.edad = edad
        self.notas = [0.0] * NUM_EVALUACIONES

    def get_codigo(self):
        return self.codigo

    def get_nombre(self):
        return self.nombre

    def get_edad(self):
        return self.edad

    def set_nota(self, posicion, nota):
        if 0 <= posicion < NUM_EVALUACIONES:
            self.notas[posicion] = nota

    def get_nota(self, posicion):
        if 0 <= posicion < NUM_EVALUACIONES:
            return self.notas[posicion]
        return 0

    def calcular_promedio(self):
        return sum(self.notas) / NUM_EVALUACIONES

    def mostrar(self):
        print(f"Código: {self.codigo} | Nombre: {self.nombre} | Edad: {self.edad} | Notas: {self.notas} | Promedio: {self.calcular_promedio():.2f}")


def buscar_estudiante(estudiantes, codigo):
    for i, est in enumerate(estudiantes):
        if est.get_codigo() == codigo:
            return i
    return -1


def leer_nota(numero_nota):
    while True:
        try:
            nota = float(input(f"Nota {numero_nota}: "))
            if 0 <= nota <= 5:
                return nota
            else:
                print("Nota inválida. Debe estar entre 0 y 5.")
        except ValueError:
            print("Entrada inválida. Debe ser un número.")


def main():
    print("=== Bienvenido al Sistema de Gestión de Estudiantes ===")
    estudiantes = []
    
    while True:
        print("\n--- MENÚ PRINCIPAL ---")
        print("1. Registrar estudiante")
        print("2. Mostrar todos los estudiantes")
        print("3. Buscar estudiante por código")
        print("4. Actualizar notas de un estudiante")
        print("5. Mostrar promedio de un estudiante")
        print("6. Mostrar estudiantes aprobados y reprobados")
        print("7. Salir")

        try:
            opcion = int(input("Seleccione una opción: "))
        except ValueError:
            print("Opción inválida.")
            continue

        if opcion == 1:
            if len(estudiantes) < MAX_ESTUDIANTES:
                codigo = input("Ingrese código: ")
                if buscar_estudiante(estudiantes, codigo) != -1:
                    print("Error: Ya existe un estudiante con ese código.")
                    continue

                nombre = input("Ingrese nombre: ")
                edad = 0
                while edad <= 0:
                    try:
                        edad = int(input("Ingrese edad: "))
                        if edad <= 0:
                            print("Edad inválida. Debe ser mayor que 0.")
                    except ValueError:
                        print("Entrada inválida. Debe ser un número entero.")

                nuevo_est = Estudiante(codigo, nombre, edad)
                print(f"Ingrese las {NUM_EVALUACIONES} notas:")
                for i in range(NUM_EVALUACIONES):
                    nota = leer_nota(i + 1)
                    nuevo_est.set_nota(i, nota)

                estudiantes.append(nuevo_est)
                print("Estudiante registrado correctamente.")
            else:
                print("No se pueden registrar más estudiantes.")

        elif opcion == 2:
            if not estudiantes:
                print("No hay estudiantes registrados.")
            else:
                print("\n=== LISTA DE ESTUDIANTES ===")
                for est in estudiantes:
                    est.mostrar()

        elif opcion == 3:
            codigo = input("Ingrese código a buscar: ")
            pos = buscar_estudiante(estudiantes, codigo)
            if pos != -1:
                print("\nEstudiante encontrado:")
                estudiantes[pos].mostrar()
            else:
                print("Estudiante no encontrado.")

        elif opcion == 4:
            codigo = input("Ingrese código del estudiante: ")
            pos = buscar_estudiante(estudiantes, codigo)
            if pos != -1:
                print(f"Ingrese las nuevas {NUM_EVALUACIONES} notas:")
                for i in range(NUM_EVALUACIONES):
                    nota = leer_nota(i + 1)
                    estudiantes[pos].set_nota(i, nota)
                print("Notas actualizadas correctamente.")
            else:
                print("Estudiante no encontrado.")

        elif opcion == 5:
            codigo = input("Ingrese código del estudiante: ")
            pos = buscar_estudiante(estudiantes, codigo)
            if pos != -1:
                print(f"Promedio de {estudiantes[pos].get_nombre()}: {estudiantes[pos].calcular_promedio():.2f}")
            else:
                print("Estudiante no encontrado.")

        elif opcion == 6:
            if not estudiantes:
                print("No hay estudiantes registrados.")
            else:
                print("\n=== ESTUDIANTES APROBADOS Y REPROBADOS ===")
                for est in estudiantes:
                    est.mostrar()
                    estado = "APROBADO" if est.calcular_promedio() >= 3.0 else "REPROBADO"
                    print(f"Estado: {estado}")
                    print("-------------------------")

        elif opcion == 7:
            print("Gracias por usar este programa. ¡Nos vemos pronto!")
            break

        else:
            print("Opción inválida.")


if __name__ == "__main__":
    main()