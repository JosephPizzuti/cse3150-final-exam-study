#include <iostream>
#include <memory>

class Child;
class Parent
{
public:
  std::unique_ptr<Child> child;
  Parent() : child(std::make_unique<Child>()) {}
};

class Child
{
public:
  std::weak_ptr<Parent> parent;
  Child() = default;
};

int main()
{
  std::shared_ptr<Parent> p = std::make_shared<Parent>();
  p->child->parent = p;
  if (auto locked = p->child->parent.lock()) std::cout << "Parent alive\n";
  else std::cout << "Parent gone\n";
  return 0;
}
