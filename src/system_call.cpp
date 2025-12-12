#include <iostream>
#include <cstdlib>

int main()
{
  int rc = std::system("ls");
  std::cout << rc << std::endl;
  return 0;
}
