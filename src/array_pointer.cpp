#include <iostream>

int main()
{
  int* arr = new int[3];
  for (int i = 0; i < 3; i++)
  {
    // writing to arr[3] is buffer overflow because we allocated only 3 blocks of memory, while arr[3] would require 4
    // in other words, index 3 is out of range
    arr[i] = (i*10)+10;
  }
  int* p = new int;
  *p = arr[1];

  for (int i = 0; i < 3; i++)
  {
    std::cout << arr[i] << std::endl;
  }
  std::cout << *p << std::endl;

  delete[] arr;
  delete p;

  return 0;
}
