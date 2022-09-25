
#include <algorithm>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

class ExampleGood {
  ExampleGood(ExampleGood &&rhs) noexcept
      : vec(std::move(rhs.vec)), str(std::move(rhs.str)) {}
  std::vector<int> vec;
  std::string str;
};

class ExampleBad {
  ExampleBad(ExampleBad &&rhs)
      : vec(std::move(rhs.vec)), str(std::move(rhs.str)) {}
  std::vector<int> vec;
  std::string str;
};

using namespace std;

int main() {
  cout << boolalpha << is_nothrow_move_constructible_v<ExampleGood> << endl;
  cout << is_nothrow_move_constructible_v<ExampleBad> << endl;
}