#include<iostream>

void dereference_1(int *num1)
{
    std::cout << "dereference_1 called " << std::endl;
    std::cout << "num1: " << num1 << std::endl;
    std::cout << "&num1: " << &num1 << std::endl;
    std::cout << "*num1: " << *num1 << std::endl; 
}

void dereference_2(int **num2)
{
    std::cout << "dereference_2 called " << std::endl;
    std::cout << "num2: " << num2 << std::endl; 
    std::cout << "&num2: " << &num2 << std::endl; // Address of num2 .
    std::cout << "*num2: " << *num2 << std::endl; //Address of the pointer pointed by num2
    std::cout << "**num2: " << **num2 << std::endl;  // Value at the Address of the pointer pointed by num2
}

void dereference_3(int &num3)
{
    std::cout << "dereference_3 called " << std::endl;
    std::cout << "num3: " << num3 << std::endl;
    std::cout << "&num3: " << &num3 << std::endl;
    //std::cout << "*num3: " << *num3; // compile time error - operand of '*' must be a pointer but has type "int"C/C++(75)
}

void dereference_4(const char *p_char)
{
    
}

void dereference_5(const char **p_char)
{
    
}

void dereference_6(const char &p_char)
{
    
}

int main()
{
    int num1 = 7;
    int *p_num = &num1;
    int **pp_num = &p_num;

    const char *p_char {"Nitesh"};
    const char **pp_char = &p_char;

    dereference_1(p_num);
    //dereference_1(&p_num); //compile time error - argument of type "int **" is incompatible with parameter of type "int *"C/C++(167)
    //dereference_1(num1);//compile time error
    dereference_1(&num1);
    //dereference_2(p_num);//compile time error
    //dereference_2(num1); //compile time error
    //dereference_2(*p_num); //compile time error
    //dereference_2(**p_num); //compile time error
    //dereference_2(***p_num); //compile time error
    //dereference_2(&(*p_num)); //compile time error
    dereference_2(pp_num);
    //dereference_2(&pp_num);  //compile time error - argument of type "int ***" is incompatible with parameter of type "int **"C/C++(167)
    dereference_2(&p_num);

    dereference_3(num1);
    //dereference_3(p_num); //compile time error - a reference of type "int &" (not const-qualified) cannot be initialized with a value of type "int *"C/C++(434)
    dereference_3(*p_num);

    dereference_4(p_char);
    //dereference_4(&p_char);//compile time error - argument of type "const char **" is incompatible with parameter of type "const char *"C/C++(167)
    dereference_4("Nitesh");

    dereference_5(pp_char);
    dereference_5(&p_char);//compile time error - argument of type "const char **" is incompatible with parameter of type "const char *"C/C++(167)
    //dereference_5("Nitesh"); //compile time error - argument of type "const char *" is incompatible with parameter of type "const char **"C/C++(167)

    //dereference_6(p_char); //compile time error - argument of type "const char *" is incompatible with parameter of type "const char &"C/C++(167)
    //dereference_6(&p_char);//compile time error - argument of type "const char **" is incompatible with parameter of type "const char *"C/C++(167)
    //dereference_6("Nitesh"); //argument of type "const char *" is incompatible with parameter of type "const char &"C/C++(167)
    dereference_6(*p_char);

    return 0;
}