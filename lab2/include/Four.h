#ifndef FOUR_CLASS
#define FOUR_CLASS

#include <stdlib.h>
#include <initializer_list>
#include <string>
#include <vector>

class Four
{
public:
    Four();
    Four(const size_t&, unsigned char);
    Four(const std::initializer_list<unsigned char>&);
    Four(const std::string&);
    Four(const Four&);
    void printNubmer();

    void add(const Four&);
    void subtract(const Four&);

    bool lowerThan(const Four&);
    bool lowerThanEq(const Four&);
    bool greaterThan(const Four&);
    bool greaterThanEq(const Four&);
    bool equal(const Four& other);


    // TODO:
    // - noexcept, надо ли в header?
    // - virtual, надо ли в header?
    // Four(Four&&);
    // virtual ~Four();
private:
    std::vector<unsigned char> number;
    

    const unsigned char correctCharacters[4] {'0', '1', '2', '3'}; // сделать единым для класса

    unsigned int charToNum(unsigned char); // В функции
    unsigned char numToChar(unsigned int num); // В функции
    int min(const int,const int); // В функции
    int max(const int,const int); // В функции
    const unsigned int MAX_VALUE = 4; // разобраться с этой константой, как ее сделать отдельной
};

#endif // FOUR_CLASS