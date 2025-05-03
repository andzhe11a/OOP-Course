#include <iostream>
#include <cmath>

class Triangle
{
public:
  Triangle(double sideA = 1, double sideB = 1, double sideC = 1)
  {
    setA(sideA);
    setB(sideB);
    setC(sideC);
  }

  void setA(double a)
  {
    this->a = a;
  }

  void setB(double b)
  {
    this->b = b;
  }

  void setC(double c)
  {
    this->c = c;
  }

  double getA() const
  {
    return a;
  }

  double getB() const
  {
    return b;
  }

  double getC() const
  {
    return c;
  }

  double getPerimeter() const
  {
    return a + b + c;
  }

  double getSemiPerimeter() const
  {
    return getPerimeter() / 2;
  }

  double getArea() const
  {
    double p = getSemiPerimeter();
    return sqrt(p * (p - a) * (p - b) * (p - c));
  }

  double getCircumradius() const
  {
    return (a * b * c) / (4 * getArea());
  }

  double getInradius() const
  {
    return getArea() / getSemiPerimeter();
  }

private:
  double a, b, c;
};

int main() {
  Triangle t(3, 4, 5);

  std::cout << "Perimeter: " << t.getPerimeter() << "\n";
  std::cout << "Area: " << t.getArea() << "\n";
  std::cout << "Inradius: " << t.getInradius() << "\n";
  std::cout << "Circumradius: " << t.getCircumradius() << "\n";

  return 0;
}