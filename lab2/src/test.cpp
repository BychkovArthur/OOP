#include <iostream>
 
class Person
{
public:
    Person(std::string p_name, unsigned p_age)
    {
        ++count;    // при создании нового объекта увеличиваем счетчик
        name = p_name;
        age = p_age;
    }
    void print_count()
    {
        std::cout << "Created " << count << " objects" << std::endl;
    }
private:
    std::string name;
    unsigned age;
    static unsigned count{};  // статическое поле - счетчик объектов Person
};
 
int main()
{
    Person tom{"Tom", 38};
    Person bob{"Bob", 42};
    Person sam{"Sam", 25};
    tom.print_count();
    bob.print_count();
    sam.print_count();
}