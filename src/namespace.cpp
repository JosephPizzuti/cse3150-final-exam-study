#include <iostream>

namespace mathutils
{
  int add(int a, int b)
  {
    return a + b;
  }
  void print_hello()
  {
    std::cout << "Hello there!" << std::endl;
  }
}


int main()
{
  std::cout << "5 + 3 = " << mathutils::add(5, 3) << std::endl;
  mathutils::print_hello();

  using mathutils::add;
  std::cout << "10 + 20 = " << add(10,20) << std::endl;

  return 0;
}
