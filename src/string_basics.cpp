#include <iostream>
#include <string>

int main()
{
  std::string my_string;
  std::cout << "Enter a string:" << std::endl;
  std::getline(std::cin, my_string);

  std::string to_find;
  std::cout << "Enter a substring:" << std::endl;
  std::getline(std::cin, to_find);

  size_t char_pos = my_string.find(to_find);
  if (char_pos == std::string::npos)
  {
    std::cout << "Character not found :(" << std::endl;
  }
  else
  {
    std::cout << '"' << to_find << '"' << " was found!" << std::endl;
  }

  if (my_string.size() > 2)
  {
    std::string three_chars = my_string.substr(0, 3);
    std::cout << "The first 3 characters in your string are: " << '"' << three_chars << '"' << std::endl;
  }
  else
  {
    std::cout << "The first " << my_string.size() << " characters in your string are: " << '"' << my_string << '"' << std::endl;
  }

  return 0;
}
