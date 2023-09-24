#include <iostream>
#include <string>

class Person
{
    public:
        Person() = default;
        Person(const std::string first_name);
        Person(std::string first_name, std::string last_name);
        Person(std::string first_name, std::string last_name, std::uint8_t age);

        void set_first_name(const std::string& name);
        const std::string get_first_name();
        void set_last_name(const std::string& name);
        const std::string get_last_name();
        void set_age(const std::uint16_t age);
        const std::uint16_t get_age();
        ~Person();

    private:
        std::string m_first_name{};
        std::string m_last_name{};
        std::uint16_t m_age{};
};
