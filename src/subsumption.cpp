#include <iostream>

class Animal
{
public:
  virtual void speak() { std::cout << "?"; }
};

class Cat : public Animal
{
public:
  void speak() override { std::cout << "meow"; }
};

int main()
{
  Animal* cat = new Cat;
  cat->speak();
  std::cout << std::endl;
  delete cat;
  return 0;
}
