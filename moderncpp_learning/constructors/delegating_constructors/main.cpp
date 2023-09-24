#include "delegating_constructors.hpp"

int main()
{
    Person P1{"Nitesh"};
    Person P2{"Vivek", "Singh"};
    Person P3{"Dinesh", "KumarSingh", 61};

    std::cout<< "First Name, Last Name and Age of P1 while creating it: "<< P1.get_first_name() << " " << P1.get_last_name() << " " << P1.get_age() << std::endl;
    std::cout<< "First Name, Last Name and Age of P2 while creating it: "<< P2.get_first_name() << " " << P2.get_last_name() << " " << P2.get_age() << std::endl;
    std::cout<< "First Name, Last Name and Age of P3 while creating it: "<< P3.get_first_name() << " " << P3.get_last_name() << " " << P3.get_age() << std::endl;

    P1.set_last_name("Singh");
    P1.set_age(33);

    P2.set_age(30);
    P3.set_last_name("kumar Singh");

    std::cout<< "First Name, Last Name and Age of P1 after modifying it again: "<< P1.get_first_name() << " " << P1.get_last_name() << " " << P1.get_age() << std::endl;
    std::cout<< "First Name, Last Name and Age of P2 after modifying it again: "<< P2.get_first_name() << " " << P2.get_last_name() << " " << P2.get_age() << std::endl;
    std::cout<< "First Name, Last Name and Age of P3 after modifying it again: "<< P3.get_first_name() << " " << P3.get_last_name() << " " << P3.get_age() << std::endl;


    return 0;
}
