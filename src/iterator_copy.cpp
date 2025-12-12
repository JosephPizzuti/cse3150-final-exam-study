#include <iostream>
#include <vector>
#include <iterator>

template <typename InputIt, typename OutputIt>
void copy_all(InputIt begin, InputIt end, OutputIt output)
{
  for (; begin != end; ++begin)
  {
    *output ++= *begin;
  }
}

int main()
{
  std::vector<int> a = {1,2,3,4,5};
  std::vector<int> b; 
  copy_all(a.begin(), a.end(), std::back_inserter(b));
  for (int x : b) std::cout << x;
  std::cout << std::endl;
  std::cout << (b.size() % 2 == 0 ? "even" : "odd") << std::endl;
}
