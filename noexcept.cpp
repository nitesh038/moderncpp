//https://www.learncpp.com/cpp-tutorial/exception-specifications-and-noexcept/
//https://www.modernescpp.com/index.php/c-core-guidelines-the-noexcept-specifier-and-operator
//https://akrzemi1.wordpress.com/2014/04/24/noexcept-what-for/

#include<iostream>

void foo() {throw -1;}
void boo() {};
void goo() noexcept {};
struct S{};

int main()
{
    constexpr bool b1{ noexcept(5 + 3) }; // true; ints are non-throwing
    constexpr bool b2{ noexcept(foo()) }; // false; foo() throws an exception
    constexpr bool b3{ noexcept(boo()) }; // false; boo() is implicitly noexcept(false)
    constexpr bool b4{ noexcept(goo()) }; // true; goo() is explicitly noexcept(true)
    constexpr bool b5{ noexcept(S{}) };   // true; a struct's default constructor is noexcept by default
    std::cout << "b1: " << b1 << std::endl;
    std::cout << "b2: " << b2 << std::endl;
    std::cout << "b3: " << b3 << std::endl;
    std::cout << "b4: " << b4 << std::endl;
    std::cout << "b5: " << b5 << std::endl;
    
    return 0;
}