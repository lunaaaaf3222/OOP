class Rectangulo {
 public double base;
 public double altura;
 public Rectangulo(double b, double h) {
 base = b;
 altura = h;
 }

 public double area() {
 return base * altura;
 }
 }
public class MainRectangulo {
 public static void main(String[] args) {
 Rectangulo r1 = new Rectangulo(3.0, 2.0);

 System.out.println("Base = " + r1.base);
 System.out.println("Altura = " + r1.altura);
 System.out.println("Area = " + r1.area());
 }
}
