#include <iostream>
#include <cmath>

class Circle {
private:
  double radius;
  double x, y;

public:
  Circle(double r, double centerX, double centerY) {
    if (r <= 0) {
      radius = 1;
    } else {
      radius = r;
    }
    x = centerX;
    y = centerY;
  }

  void setX(double x)
  {
    this->x = x;
  }

  void setY(double y)
  {
    this->y = y;
  }

  double getRadius() const
  {
    return radius;
  }
  double getX() const
  {
    return x;
  }
  double getY() const
  {
    return y;
  }

  bool containsPoint(double px, double py) const {
    double dx = px - x;
    double dy = py - y;
    double distanceSquared = dx * dx + dy * dy;
    return distanceSquared <= radius * radius;
  }
};

int main() {
  Circle c(2, 5, 5);

  double px, py;
  std::cout << "Enter coordinates of point: ";
  std::cin >> px >> py;

  if (c.containsPoint(px, py)) {
    std::cout << "Point is inside or on the circle.\n";
  } else {
    std::cout << "Point is outside the circle.\n";
  }

  return 0;
}