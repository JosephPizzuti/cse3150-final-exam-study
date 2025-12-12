#include <iostream>
#include <vector>

int main()
{
  for (int i = 0; i < 3; ++i)
  {
    if (i == 0) std::cout << i;
    else std::cout << ", " << i;
  }
  std::cout << std::endl;

  std::vector<int> vec = {1,2,3,4,5};
  for (auto ele : vec)
  {
    if (ele == 1) continue;
    if (ele == 5) break;
    std::cout << ele;
  }
  std::cout << std::endl;

  return 0;
}
