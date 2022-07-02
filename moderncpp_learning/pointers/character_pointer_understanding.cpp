#include <iostream>

void understand_char_pointer() {
  const char *p_char{"Hello World!"};
  std::cout << p_char
            << std::endl; // prints whole string , << is overloaded operator ,
                          // it dereferences till null character
  std::cout << *p_char << std::endl; // prints 1 char of string, here H

  const char *names[] = {"Nitesh", "Sujit", "Vivek", "Umang", "Khan"};

  std::cout << names[0] << std::endl; // prints Nitesh
  std::cout << names[1] << std::endl; // prints Sujit
  std::cout << names[2] << std::endl; // prints Vivek
  std::cout << names[3] << std::endl; // prints Umang
  std::cout << names[4] << std::endl; // prints Khan

  std::cout << *names << std::endl;    // prints Nitesh
  std::cout << **names << std::endl;   // prints N
  std::cout << *names[0] << std::endl; // prints N
  std::cout << *names[1] << std::endl; // prints S
  const char *exp = names[0];

  std::cout << exp << std::endl;  // prints Nitesh
  std::cout << *exp << std::endl; // prints N

  const char **exp1 = names;
  std::cout << exp1 << std::endl; // prints 0x7fffffffd6b0 - since we are passing pointer to pointer to be derefernced here
  std::cout << *exp << std::endl; // prints N
  const char **exp2 = exp1;
  *exp2++; // Nitesh
  *exp2++; // Sujit
  *exp2++; // Vivek
  *exp2++; // Umang
}

int main() {
  understand_char_pointer();
  return 0;
}