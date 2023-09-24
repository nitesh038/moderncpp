#include "copy_constructors.hpp"

// Constructors
Person::Person(const std::string& first_name) 
    : Person{first_name,"singh", 30}//m_first_name{first_name}
    {
        std::cout<<"One Parameter Constructor Called\n";
    }

Person::Person(const std::string& first_name, const std::string& last_name)
    : Person{first_name, last_name, 30}//m_first_name{first_name}
      {
        std::cout<<"Two Parameter Constructor Called\n";
      }

//Deep copy for age
Person::Person(const std::string& first_name, const std::string& last_name, std::uint16_t age)
    : m_first_name{first_name},
      m_last_name{last_name},
      m_age{new std::uint16_t (age)}
      {
        std::cout<<"Three Parameter Constructor Called\n";
      }

//Copy Constructor
//Delegate from the copy constructor
Person::Person(const Person& person)
: Person{
    person.get_first_name(),
    person.get_last_name(),
    *(person.get_age())
    }
{
    std::cout<<"Copy Constructor Called.\n";
}


//Destructor
Person::~Person()
{
    delete m_age; // Making sure about no memory leakage
    std::cout<<"Destructor Called.\n";
}
void Person::set_first_name(const std::string& first_name)
{
  m_first_name = first_name;
}

void Person::set_last_name(const std::string& last_name)
{
  m_last_name = last_name;
}

const std::string& Person::get_first_name() const
{
  return m_first_name;
}

const std::string& Person::get_last_name() const
{
  return m_last_name;
}

void Person::set_age(const std::uint16_t age)
{
  *m_age = age;
}

const uint16_t* Person::get_age() const
{
  return m_age;
}