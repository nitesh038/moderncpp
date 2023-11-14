#include"shared_pointer.hpp"

int main()
{
    SharedPointer<int> S1;//default constructor
    SharedPointer<int> S2(new int(10));//parameterised constructor
    SharedPointer<int> S3 = S2;//parameterised constructor
    SharedPointer<int> S4(S2);//copy constructor
    S4 = S3;//copy assignment operator

    SharedPointer<int> S5(std::move (S2));//move constructor

    S4 = std::move(S3); //move assignment operator
    
    S4.get();
    
    S4.get_count(); // number of objects pointing to same resource
    
    S4.reset(new int(50)); 
    //pointer->func();



    std::cout<<"*S4: "<< *S4 << std::endl;

    return 0;
}