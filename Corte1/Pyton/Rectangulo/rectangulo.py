class Rectangulo: 
    def __init__ (self, b, h):
        self.base = b
        self.altura = h

    def area(self):
        return self.base * self.altura
    
def main():
    r1 = Rectangulo(4.0,3.5)
    print("Base:", r1.base)
    print("Altura:", r1.altura)
    print("Area:", r1.area())
if __name__=="__main__":
    main()
