#include <iostream>

class Adder
{
  int a_;
  int b_;
public:
  Adder(int a=0, int b=0) : a_(a), b_(b) {}
  void sum() const;
};

void Adder::sum() const
{
  std::cout << a_ + b_ << std::endl;
}

int main()
{
  Adder a(5,5);
  a.sum();
  return 0;
}
