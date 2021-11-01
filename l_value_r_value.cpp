#include<iostream>
#include<string>

void Print(const std::string& s)
{
    std::cout << "Lvalue" << std::endl;
}

void Print(std::string&& s)
{
    std::cout << "Rvalue" << std::endl;
}

int main()
{
    std::string blah{"BLAHHH !"};
    Print(blah);
    Print("Hello");
    Print(std::move(blah)); // we are saying we know it's l-value but treat it as rvlaue
    return 0;
}