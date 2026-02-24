package intento;
import java.util.Scanner;
public class Intento {

    public static void main(String[] args) {
       Scanner recibe = new Scanner (System.in);
       
       System.out.println("Ingrese su nombre: ");
       String name = recibe.next(); 
       
       System.out.println("Ingrese su edad: ");
       int num = recibe.nextInt();
       
       System.out.println("Hola, usted es " + name + " y tiene " + num + "años.");
       
       recibe.close();
    }

    
}
