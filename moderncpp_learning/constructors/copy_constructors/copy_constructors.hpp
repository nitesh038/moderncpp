#include <iostream>
#include <string>

class Person
{
    public:
        //Constructors
        Person() = default;
        Person(const std::string& first_name);
        Person(const std::string& first_name, const std::string& last_name);
        Person(const std::string& first_name, const std::string& last_name, std::uint16_t age);
        //Copy Constructor
        Person(const Person& person);

        void set_first_name(const std::string& name);
        const std::string& get_first_name() const;
        void set_last_name(const std::string& name);
        const std::string& get_last_name() const;
        void set_age(const std::uint16_t age);
        const std::uint16_t* get_age() const ;
        ~Person();

    private:
        std::string m_first_name{};
        std::string m_last_name{};
        std::uint16_t *m_age{};
};
