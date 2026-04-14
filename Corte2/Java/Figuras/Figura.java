abstract class Figura {
    protected String nombre;

    public Figura(String nombre) {
        this.nombre = nombre;
    }

    // Metodo abstracto: cada figura hija debe implementar su propia formula 
    public abstract double calcularArea();
    public void mostrarInfo() {
        System.out.println("Figura: " + nombre + "| Area:" + calcularArea());
    }
    
}
