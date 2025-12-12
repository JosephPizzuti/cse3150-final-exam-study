#include <iostream>

class Counter
{
  int value;
public:
  Counter(int a = 0) : value(a) {}

  void inc()
  {
    value += 1;
  }

  int get() const
  {
    return value;
  }
};

int main()
{
  Counter a(10);
  a.inc();
  std::cout << a.get() << std::endl;
  a.inc();
  std::cout << a.get() << std::endl;

  return 0;
}
