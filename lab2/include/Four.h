#ifndef FOUR_CLASS
#define FOUR_CLASS

#include <stdlib.h>
#include <initializer_list>
#include <string>

class Four
{
public:
    Four();
    Four(const size_t&, unsigned char);
    Four(const std::initializer_list<unsigned char>&);
    Four(const std::string&);
    Four(const Four&);

    // TODO:
    // - noexcept, надо ли в header?
    // - virtual, надо ли в header?
    Four(Four&&);
    virtual ~Four();
};

#endif // FOUR_CLASS