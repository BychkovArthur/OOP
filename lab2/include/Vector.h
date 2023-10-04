#pragma once
#include <cstddef>

class Vector
{
public:
    Vector();
    Vector(const Vector&);
    Vector(Vector&&);
    Vector& operator=(const Vector&);
    Vector& operator=(Vector&&);
    void pushBack(unsigned char);
    void popBack();
    unsigned char& operator[](unsigned int) const;
    size_t getSize() const;
    ~Vector();
    void print() const;
    
private:
    size_t size;
    size_t capacity;
    unsigned char* arr;
};
