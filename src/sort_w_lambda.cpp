#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
  std::vector<std::pair<std::string, int>> v =
  {
    {"apple",5}, {"banana",2}, {"cherry",9}, {"date",3}
  };
  // you could also use auto for these types!
  auto price = [](const std::pair<std::string, int>& pair1, const std::pair<std::string, int>& pair2) -> bool
  {
    return pair1.second < pair2.second;
  };
  
  std::sort(v.begin(), v.end(), price);
  // you could also pass the pair itself and use .first and .second!
  for (const auto& [name,val] : v)
  {
    std::cout << name << ", " << val << std::endl;
  }
  return 0;
}
