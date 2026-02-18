
import java.util.Scanner;

public class ejercicio1
{
    //el método main empieza la ejecuición de la aplicación en Java
    public static void main(String[] args)
    {
        Scanner entrada = new Scanner(System.in);
        int numero1;
        int numero2;
        int suma;

        System.out.print("Escriba el primer entero: "); //indicador
        numero1 = entrada.nextInt(); //lee el primer número del usuario

        System.out.print("Escriba el segundo entero: "); //indicador
        numero2 = entrada.nextInt(); //lee el segundo número del usuario

        suma = numero1 + numero2;//suma los números, después almacena el total en suma

        System.out.printf("La suma es %d%n", suma); //muesta la suma
    }//fin del método main
}//fin de la clase suma