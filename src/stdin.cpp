#include <iostream>
#include "string.h"

int main()
{
  std::cout << "What is your favorite color?: ";
  std::string fav_color;
  std::getline(std::cin, fav_color);

  std::cout << "Write a sentence!" << std::endl;
  std::string sentence;
  std::getline(std::cin, sentence);
  std::cout << std::endl;

  std::cout << "Your favorite color is " << fav_color << std::endl;
  std::cout << "Look at this sentence you wrote:\n" << sentence << std::endl;

  return 0;
}
