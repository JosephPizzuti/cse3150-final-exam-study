#include <iostream>

// we want in to be const so the function promises not to modify input
// we want out to be non-const so the function can write the result into it
void scale(const int& in, int& out)
{ 
  
  out = in * 3;
}

int main()
{
  int a1 = 3;
  int a2 = 5;

  std::cout << "a1 before: " << a1 << std::endl;
  std::cout << "a2 before: " << a2 << std::endl;

  scale(a1, a2);

  std::cout << "a1 after: " << a1 << std::endl;
  std::cout << "a2 after: " << a2 << std::endl;

  return 0;
}
