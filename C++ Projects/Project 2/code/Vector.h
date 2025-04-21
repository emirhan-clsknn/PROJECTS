#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm>

// Template-based dynamic array class
template <typename T>
class Vector
{
private:
    std::unique_ptr<T[]> data; // Dynamically allocated array for storing elements
    size_t size;               // Current number of elements in the vector
    size_t capacity;           // Total capacity of the vector (allocated memory)

    // Private helper method to resize the vector's capacity
    void resize(size_t new_capacity);

public:
    // Default constructor
    Vector();

    // Constructor with initial size and value for all elements
    Vector(size_t n, const T &value);

    // Constructor with initial size (elements are default-initialized)
    Vector(size_t n);

    // Copy constructor
    Vector(const Vector &other);

    // Move constructor
    Vector(Vector &&other) noexcept;

    // Constructor from an input iterator range
    template <typename InputIterator>
    Vector(InputIterator first, InputIterator last);

    // Adds a new element to the end of the vector
    void push_back(T &&value);

    // Removes the last element of the vector
    void pop_back();

    // Access operator (non-const version)
    T &operator[](size_t index);

    // Access operator (const version)
    const T &operator[](size_t index) const;

    // Copy assignment operator
    Vector &operator=(const Vector &other);

    // Move assignment operator
    Vector &operator=(Vector &&other) noexcept;

    // Returns the number of elements in the vector
    size_t get_size() const;

    // Returns the total capacity of the vector
    size_t get_capacity() const;

    // Checks if the vector is empty
    bool empty() const;

    // Clears all elements from the vector
    void clear();

    // Destructor (default implementation)
    ~Vector();
};

// Include the implementation file to handle templates
#include "Vector.cpp"

#endif // VECTOR_H
