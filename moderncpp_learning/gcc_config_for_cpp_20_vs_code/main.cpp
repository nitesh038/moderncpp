#include <iostream>

consteval int get_values() { return 3; }

int main() {
  constexpr int value = get_values();
  std::cout << "Value: " << value << std::endl;
  return 0;
}