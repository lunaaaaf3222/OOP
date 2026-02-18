import java.util.Scanner;

public class App {

// lógica del programa

    public static void main(String[] args)  {
        Numero numero1 = new Numero();
        Numero numero2 = new Numero();
        Numero suma = new Numero();
        Scanner teclado = new Scanner(System.in);
        Vista vista = new Vista();
        vista.mostrarTitulo();
        vista.mostrarnumero();
        int n1 = teclado.nextInt();
        numero1.setNumero(n1);
        vista.mostrarnumero();
        int n2 = teclado.nextInt();
        numero2.setNumero(n2);
    
        int s = numero1.getNumero() +numero2.getNumero();
        suma.setNumero(s);
        vista.mostrarsalida(suma);
        teclado.close();
    }
}
