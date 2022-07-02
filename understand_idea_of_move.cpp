/*
How to think about std::move
Think about ownership
Entity owns a variable if it deletes it, e.g.
A function scope owns a variable defined in it
An object of a class owns its data members
Moving a variable transfers ownership
of its resources to another variable
When designing your program think
“who should own this thing?”
Runtime: better than copying, worse than
passing by reference
*/

#include <iostream>
#include <string>

class Printer {
public:
  void Print(const std::string &s) {
    std::cout << "Lvalue " << s << std::endl;
    str_ = s;
  }

  void Print(std::string &&s) {
    std::cout << "Rvalue " << s << std::endl;
    // Now, hello variable memory got transferred to str_
    str_ = std::move(s);
  }

private:
  std::string str_;
};

int main() {
  Printer printer;
  std::string blah{"BLAHHH !"};
  printer.Print(blah);
  printer.Print("Hello");
  // we are saying we know it's l-value but treat it as rvlaue
  printer.Print(std::move(blah));
  // We should nver do anything like below, it has undefined behaviour
  std::cout << "After Move: " << blah << std::endl;
  return 0;
}