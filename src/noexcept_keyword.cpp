#include <iostream>

int safe_add(int a, int b) noexcept
{
  return a + b;
}

int main()
{
  // if safe_add were to throw, it would terminate the program through std::terminate()
  std::cout << safe_add(3,4) << std::endl;
  return 0;
}
