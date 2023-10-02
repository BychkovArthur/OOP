#pragma once

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
    unsigned int getSize() const;
    ~Vector();
    void print() const;
    
private:
    unsigned int size;
    unsigned int capacity;
    unsigned char* arr;
};
