#include "../include/Vector.h"
#include <stdexcept>
#include <iostream>

Vector::Vector() : size(0), capacity(1), arr(new unsigned char[capacity]) { }

Vector::Vector(const Vector& copy) : size(copy.size), capacity(copy.capacity), arr(new unsigned char[capacity])
{
    for (unsigned int i = 0; i < size; ++i) {
        arr[i] = copy.arr[i];
    }
}

Vector::Vector(Vector&& moved) : size(moved.size), capacity(moved.capacity), arr(moved.arr)
{
    moved.size = 0;
    moved.capacity = 1;
    moved.arr = new unsigned char[capacity]; // Чтобы при удалении moved не было double free
}

Vector& Vector::operator=(const Vector& copy)
{
    if (this != &copy) {
        delete[] arr;
        size = copy.size;
        capacity = copy.capacity;
        arr = new unsigned char[capacity];
        for (unsigned int i = 0; i < size; ++i) {
            arr[i] = copy.arr[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& moved)
{
    if (this != &moved) {
        delete[] arr;
        size = moved.size;
        capacity = moved.capacity;
        arr = moved.arr;

        moved.size = 0;
        moved.capacity = 1;
        moved.arr = new unsigned char[capacity];
    }
    return *this;
}

void Vector::pushBack(const unsigned char character) 
{
    if (size + 1 <= capacity) {
        arr[size] = character;
    } else {
        capacity *= 2;
        unsigned char* new_arr = new unsigned char[capacity];
        for (unsigned int i = 0; i < size; ++i) {
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

Vector::~Vector() {delete[] arr; }

void Vector::print() const
{
    for (unsigned int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

unsigned int Vector::getSize() const
{
    return size;
}
