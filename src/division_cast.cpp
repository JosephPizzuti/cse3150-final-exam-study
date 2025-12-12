#include <iostream>

int main()
{
  int a = 3, b = 2;
  std::cout << a / b << std::endl;
  std::cout << static_cast<double>(a) / b << std::endl;
  std::cout << a / static_cast<double>(b) << std::endl;
  std::cout << static_cast<double>(a) / static_cast<double>(b) << std::endl;

  return 0;
}
