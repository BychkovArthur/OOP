#ifndef VECTOR_H
#define VECTOR_H

class Vector
{
public:
    Vector();
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

#endif // VECTOR_H