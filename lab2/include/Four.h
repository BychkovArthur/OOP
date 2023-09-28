#ifndef FOUR_CLASS_H
#define FOUR_CLASS_H

#include "../include/Vector.h"
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
    virtual ~Four() noexcept;

    void print();

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
private:
    Vector number;
    static inline const unsigned char correctCharacters[4] {'0', '1', '2', '3'};
    static const unsigned int MAX_VALUE = 4;
    bool correctCharacter(const unsigned char);
};

#endif // FOUR_CLASS_H