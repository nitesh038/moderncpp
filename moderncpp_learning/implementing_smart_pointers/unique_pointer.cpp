#include"unique_ptr.hpp"

int main()
{
    
    Unique_Ptr<int> P2(new int(10));//Parameterised Ctr 
    Unique_Ptr<int> P3 = new int(20);//Parameterised Ctr

   // Unique_Ptr<int>P4(P3);//Copy Ctr -- not allowed - compilation error
    
   //P5 = P2;//copy assignment operator -- not allowed - compilation error

    Unique_Ptr<int>P6(std::move(P2));//Move Constructor
    P2 = std::move(P3); //Move Assignment Operator


    std::cout << "*P2 : " << *P2 << std::endl;

    //pointer->func() // -> is overloaded to call function
    std::cout << "P2.get() : " << P2.get() << std::endl;
    P2.reset(new int(40));
    
    return 0;
}