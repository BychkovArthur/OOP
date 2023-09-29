#include "../include/Vector.h"
#include <stdexcept>
#include <iostream>

// TODO
// - move-семантика для переноса данных в векторе

Vector::Vector()
{
    ++count;
    id = count;
    std::cout << "Создан по-умолчанию: " << id << std::endl;

    size = 0;
    capacity = 1;
    arr = new unsigned char[capacity];
}

Vector::Vector(const Vector& copy)
{
    ++count;
    id = count;
    std::cout << "Данные из " << copy.id << " скопированы в новый " << id << std::endl;

    size = copy.size;
    capacity = copy.capacity;
    arr = new unsigned char[capacity];
    for (int i = 0; i < size; ++i) {
        arr[i] = copy.arr[i];
    }
}

Vector::Vector(Vector&& moved)
{
    ++count;
    id = count;
    std::cout << "Данные из " << moved.id << " ПЕРЕНЕСЕНЫ в новый " << id << std::endl;

    size = moved.size;
    capacity = moved.capacity;
    arr = moved.arr;

    moved.size = 0;
    moved.capacity = 1;
    moved.arr = new unsigned char[capacity]; // Чтобы при удалении moved не было double free
}

Vector& Vector::operator=(const Vector& copy)
{
    std::cout << "Вызвано copy " << id << " = " << copy.id << std::endl;

    if (this != &copy) {
        delete[] arr;
        size = copy.size;
        capacity = copy.capacity;
        arr = new unsigned char[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = copy.arr[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& moved)
{
    std::cout << "Вызвано moved " << id << " = " << moved.id << std::endl;
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
    std::cout << "Удален: " << id << std::endl;
    --count;

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

// int main() {
//     Vector v1;
//     for (int i = 0; i < 10; ++i) {
//         v1.pushBack('0' + i);
//     }
//     Vector v2(v1);

//     std::cout << "V1: ";
//     v1.print();
//     std::cout << "V2: ";
//     v2.print();

//     std::cout << "\n\n\n";
//     Vector v3 = std::move(v2);
//     v2.pushBack('#');

//     std::cout << "V3: ";
//     v3.print();
//     std::cout << "V2: ";
//     v2.print();
// }