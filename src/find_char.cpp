#include <iostream>
#include <string>

int main()
{
  std::string s = "galaxy";
  size_t find_pos = s.find('x');

  if (find_pos == std::string::npos)
  {
    std::cout << "Not found" << std::endl;
  }
  else
  {
    std::cout << "chacter index: " << find_pos << std::endl;
  }


  std::string s1 = "hyperspace";
  std::string s2 = s1.substr(5);
  std::cout << s1 << "->" << s2 << std::endl;

  return 0;
}
