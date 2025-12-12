#include <iostream>
#include <stdexcept>

int main()
{
  int x;
  std::cout << "10 / ?: ";
  std::cin >> x;

  try
  {
    if (x == 0) throw std::runtime_error("div by zero");
    std::cout << "10 / " << x << " = " << 10 / x << std::endl;
  }
  catch (const std::exception& e)
  {
    std::cout << "Error: division by zero" << std::endl;
    return 1;
  }

  return 0;
}
