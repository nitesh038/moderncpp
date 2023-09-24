#include "initialize_in_constructors_through_initialiser_list.hpp"

Person::Person(std::string first_name) 
    : m_first_name{first_name}
    {}

Person::Person(std::string first_name, std::string last_name)
    : m_first_name{first_name},
      m_last_name{last_name}
      {}

Person::Person(std::string first_name, std::string last_name, std::uint8_t age)
    : m_first_name{first_name},
      m_last_name{last_name},
      m_age{age}
      {}

void Person::set_first_name(const std::string& first_name)
{
  m_first_name = first_name;
}

void Person::set_last_name(const std::string& last_name)
{
  m_last_name = last_name;
}

const std::string Person::get_first_name()
{
  return m_first_name;
}

const std::string Person::get_last_name()
{
  return m_last_name;
}

void Person::set_age(const std::uint16_t age)
{
  m_age = age;
}

const uint16_t Person::get_age()
{
  return m_age;
}