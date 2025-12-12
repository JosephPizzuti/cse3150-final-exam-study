#include <iostream>

class Meters
{
  double d_;
public:
  explicit Meters(double d) : d_(d) {}
  double get() const
  {
    return d_;
  }
};

void print(Meters m)
{
  std::cout << m.get() << std::endl;
}

int main()
{
  Meters m(5.0);
  print(m);
  print(Meters(5.0));
  // print(5.0) would fail because of the explicit! need to pass in an object of type Meters
  
  return 0;
}
