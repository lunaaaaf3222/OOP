public class Proyecto2 {
    public static void main(String[] args) {
        String base = "Hola,soy %s y tengo %s.";
        
        String persona1 = String.format(base, "Luna", "17");
        String persona2 = String.format(base, "Mary", "48");
        String persona3 = String.format(base, "Juan", "23");

        System.out.println(persona1);
        System.out.println(persona2);
        System.out.println(persona3);
    }
}