public class Vista {

    public Vista() {
    }
    
    public void mostrarTitulo(){
         System.out.println("Programa para sumar dos números enteros");
    }

    public void mostrarnumero(){
        System.out.println("Digite número");
    }

    public void mostrarsalida(Numero suma){
        System.out.println(suma.getNumero());
    }
}
