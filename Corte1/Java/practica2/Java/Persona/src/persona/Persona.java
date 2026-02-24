package persona;

public class Persona {
    public String nombre;
    public int edad;
    
    
    public void saludar(){
        System.out.println("Hola soy " + nombre + " y tengo " + edad + "años");
    }

    public static void main(String[] args) {
        Persona p1 = new Persona();
        Persona p2 = new Persona();
        
        p1.nombre = "Luna";
        p1.edad = 17;
        p2.nombre = "Henry";
        p2.edad = 48;
        
        p1.saludar();
        p2.saludar();
    }
    
}
