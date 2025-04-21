#include "Vector.h"

// Resizes the vector's capacity to a new value
template <typename T>
void Vector<T>::resize(size_t new_capacity)
{
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity); // Allocate new array
    std::move(data.get(), data.get() + size, new_data.get());            // Move old data to new array
    data = std::move(new_data);                                          // Update pointer to new array
    capacity = new_capacity;                                             // Update capacity
}

// Default constructor
template <typename T>
Vector<T>::Vector() : size(0), capacity(2)
{
    data = std::make_unique<T[]>(capacity); // Allocate initial memory
}

// Constructor with initial size and value
template <typename T>
Vector<T>::Vector(size_t n, const T &value) : size(n), capacity(n)
{
    data = std::make_unique<T[]>(capacity);          // Allocate memory
    std::fill(data.get(), data.get() + size, value); // Initialize all elements with the given value
}

// Constructor with initial size (default values)
template <typename T>
Vector<T>::Vector(size_t n) : size(n), capacity(n)
{
    T val;                                         // Default value for elements
    data = std::make_unique<T[]>(capacity);        // Allocate memory
    std::fill(data.get(), data.get() + size, val); // Initialize all elements with default values
}

// Copy constructor
template <typename T>
Vector<T>::Vector(const Vector &other) : size(other.size), capacity(other.capacity)
{
    data = std::make_unique<T[]>(capacity);                           // Allocate memory
    std::move(other.data.get(), other.data.get() + size, data.get()); // Copy elements from other vector
}

// Move constructor
template <typename T>
Vector<T>::Vector(Vector &&other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data))
{
    other.size = 0;     // Reset the size of the moved vector
    other.capacity = 0; // Reset the capacity of the moved vector
}

// Constructor from an input iterator range
template <typename T>
template <typename InputIterator>
Vector<T>::Vector(InputIterator first, InputIterator last) : size(std::distance(first, last)), capacity(size)
{
    data = std::make_unique<T[]>(capacity); // Allocate memory
    std::move(first, last, data.get());     // Initialize with elements from the range
}

// Adds a new element at the end of the vector
template <typename T>
void Vector<T>::push_back(T &&value)
{
    if (size >= capacity)
    {
        resize(capacity * 2); // Double the capacity if needed
    }
    data[size++] = std::move(value); // Add the new element
}

// Removes the last element of the vector
template <typename T>
void Vector<T>::pop_back()
{
    if (size == 0)
    {
        throw std::out_of_range("Vector is empty"); // Throw exception if no elements
    }
    --size; // Decrease the size
}

// Access operator (non-const version)
template <typename T>
T &Vector<T>::operator[](size_t index)
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range"); // Throw exception for invalid index
    }
    return data[index];
}

// Access operator (const version)
template <typename T>
const T &Vector<T>::operator[](size_t index) const
{
    if (index >= size)
    {
        throw std::out_of_range("Index out of range"); // Throw exception for invalid index
    }
    return data[index];
}

// Copy assignment operator
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &other)
{
    if (this != &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = std::make_unique<T[]>(capacity);                           // Allocate memory
        std::move(other.data.get(), other.data.get() + size, data.get()); // Copy elements
    }
    return *this;
}

// Move assignment operator
template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&other) noexcept
{
    if (this != &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = std::move(other.data); // Transfer ownership of data
        other.size = 0;               // Reset the other vector's size
        other.capacity = 0;           // Reset the other vector's capacity
    }
    return *this;
}

// Returns the number of elements in the vector
template <typename T>
size_t Vector<T>::get_size() const
{
    return size;
}

// Returns the capacity of the vector
template <typename T>
size_t Vector<T>::get_capacity() const
{
    return capacity;
}

// Checks if the vector is empty
template <typename T>
bool Vector<T>::empty() const
{
    return size == 0;
}

// Clears all elements from the vector
template <typename T>
void Vector<T>::clear()
{
    size = 0;
}

// Destructor (default implementation)
template <typename T>
Vector<T>::~Vector() = default;
