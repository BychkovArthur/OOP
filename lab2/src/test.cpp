#include <iostream>
 
class Person
{
public:
    Person(std::string p_name)
    {
        name = p_name;
        std::cout << "Person " << name << " created" << std::endl;
    }
    ~Person()
    {
        std::cout << "Person " << name << " deleted" << std::endl;
    }
private:
    std::string name;
};
 
int main()
{
    unsigned char a = '0' + -1;
    std::cout << a << std::endl;
}