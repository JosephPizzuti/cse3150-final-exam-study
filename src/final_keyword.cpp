#include <iostream>

class A
{
public:
  virtual void f(){};
};

class B : public A
{
public:
  void f() final override
  {
    std::cout << "F" << std::endl;
  }
};

int main()
{
  A* wow = new B;
  wow->f();
  return 0;
}
