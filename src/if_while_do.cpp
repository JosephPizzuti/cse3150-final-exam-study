#include <iostream>

int main()
{
  int x = 1;
  if (x > 0) std::cout << "positive" << std::endl;

  int i = 0;
  while (i < 3)
  {
    i += 1;
    std::cout << i << std::endl;
  }

  do
  {
    std::cout << "go!" << std::endl;
  }
  while (false);

  return 0;
}
