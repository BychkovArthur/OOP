#include "../include/Vector.h"
#include <stdexcept>
#include <iostream>

// TODO
// - move-семантика для переноса данных в векторе

Vector::Vector()
{
    size = 0;
    capacity = 1;
    arr = new unsigned char[capacity];
}

void Vector::pushBack(unsigned char character) 
{
    if (size + 1 <= capacity) {
        arr[size] = character;
    } else {
        capacity *= 2;
        unsigned char* new_arr = new unsigned char[capacity];
        for (int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }
        new_arr[size] = character;
        unsigned char* tmp = arr;
        arr = new_arr;
        delete[] tmp;
        tmp = nullptr;
    }
    ++size;
}

void Vector::popBack()
{
    if (size == 0) {
        throw std::range_error("Array is empty");
    }
    --size;
    arr[size] = (unsigned char) 0;
}

unsigned char& Vector::operator[](unsigned int index) const
{
    if (!(0 <= index && index < size)) {
        throw std::range_error("Index out of range");
    }
    return arr[index];
}

Vector::~Vector()
{
    delete[] arr;
}

void Vector::print() const
{
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

unsigned int Vector::getSize() const
{
    return size;
}