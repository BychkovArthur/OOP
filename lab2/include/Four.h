#ifndef FOUR_CLASS_H
#define FOUR_CLASS_H

#include "Vector.h"
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
    Four(Four&&);
    virtual ~Four() noexcept;

    Four& operator=(const Four&);
    Four& operator=(Four&&);

    void add(const Four&);
    void subtract(const Four&);

    bool lowerThan(const Four&);
    bool greaterThan(const Four&);
    bool lowerThanEq(const Four&);
    bool greaterThanEq(const Four&);
    bool equal(const Four& other);

    void print();

private:
    Vector number;
    static inline const unsigned char correctCharacters[4] {'0', '1', '2', '3'};
    static const unsigned int MAX_VALUE = 4;
    bool correctCharacter(const unsigned char);
};

#endif // FOUR_CLASS_H