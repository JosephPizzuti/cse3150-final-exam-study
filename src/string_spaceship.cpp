#include <iostream>
#include <string>

int main()
{
  std::string s = "spaceship";

  std::cout << s.size() << std::endl;
  std::cout << s[2] << std::endl;
  // std::cout << s.substr(2,1) << std::endl;
  std::cout << s + "-warp" << std::endl;

  return 0;
}
