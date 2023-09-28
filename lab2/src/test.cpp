#include <iostream>
 
class Person
{
public:
    static inline unsigned age{1};
    static inline unsigned maxAge{120};     // статическая публичная переменная
    Person(std::string p_name, unsigned p_age)
    {
        ++count;
        name = p_name;
        if(p_age < maxAge)  // если значение не больше максимального
            age = p_age;
    }
    // статическая функция
    static void print_count()
    {
        std::cout << "Created " << count << " objects" << std::endl;
    }
private:
    std::string name;
    
    static inline unsigned count{};  // статическая приватная переменная
};
 
int main()
{
    Person tom{"Tom", 38};
    Person sam{"Sam", 25};
    Person bob{"Bob", 42};
    std::cout << sam.age << std::endl;
    // обращаемся к статической функции print_count
    Person::print_count();
    // обращаемся к статической переменной maxAge
    std::cout << "Max age: " << Person::maxAge << std::endl;
    // изменяем статическую переменную maxAge
    Person::maxAge = 110;
    std::cout << "Max age: " << Person::maxAge << std::endl;
}