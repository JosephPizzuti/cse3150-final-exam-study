#include <iostream>

class Shape
{
protected:
  virtual double area() const = 0;
};

class Circle : Shape
{
  double r_;
public:
  Circle(double r = 0.0) : r_(r) {}
  double area() const override
  {
    return r_ * r_ * 3.14;
  }
};

int main()
{
  Circle a(2.0);
  std::cout << a.area() << std::endl;
  return 0;
}
