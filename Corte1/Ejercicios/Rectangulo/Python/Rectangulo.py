class Rectangulo:
 def __init__(self, base, altura):
  self.base = base
  self.altura = altura

 def area(self):
  return self.base * self.altura


r1 = Rectangulo(3.0, 2.0)

print("Base =", r1.base)
print("Altura =", r1.altura)
print("Area =", r1.area())