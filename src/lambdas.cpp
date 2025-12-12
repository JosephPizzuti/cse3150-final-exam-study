#include <iostream>

int main()
{
  int x = 10;
  auto fun = [x](int a) -> int
  {
    return a * x; 
  };

  std::cout << fun(10) << std::endl;
  return 0;
}
