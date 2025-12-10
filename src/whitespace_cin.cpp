#include <iostream>
#include <string>

int main()
{
  std::cout << "Please enter your date of birth in the following format:\n{day} {month} {year} -> ";
  std::string day, month, year;
  std::cin >> day;
  std::cin >> month;
  std::cin >> year;
  std::cout << "Your birthday is:\n" << month << "/" << day << "/" << year << std::endl;

  return 0;
}
