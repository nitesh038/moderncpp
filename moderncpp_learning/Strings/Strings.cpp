
#include "Strings.hpp"

std::ostream& operator<< (std::ostream& out, const String& res)
{
    out << res.res;
    return out; // for chaining
}


std::istream& operator>> (std::istream& in, const String& res)
{
    in >> res.res;
    return in; // for chaining
}

int main()
{
    String S1;//default constructor
    String S2 = "Helo World";//Parameterised Constructor
    String S3("Helo Hello World!");//Parameterised Constructor
    String S4(S2); //Copy Constructor
    String S5 = S2;//Copy Constructor
    String S6 = "Move now"; 

    S3 = S2;//Copy Assignment Operator // copy assignment operator gets called. 
    //this will refer to S3

    String S7(std::move(S4));
   // S4 = std::move(S2);// will have amibugous cimpile time error as copy and move bith are viable option
    std::cout<< std::endl<< S2 << std::endl << S3 << std::endl;
    //std::cin>> S4;
    
    std::cout << S2.len();


    return 0;

}