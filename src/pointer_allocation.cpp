#include <iostream>

int main()
{
  int* a = new int;
  *a = 42;
  std::cout << *a << std::endl;
  delete a;
  return 0;
}
