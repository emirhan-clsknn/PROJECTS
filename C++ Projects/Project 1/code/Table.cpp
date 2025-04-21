#include <iostream>
#include <memory>
#include <stdexcept>
#include <algorithm> // std::copy, std::fill

template <typename T>
class Vector
{
private:
    std::unique_ptr<T[]> data;
    size_t size;
    size_t capacity;

    // Kapasiteyi iki katına çıkarır
    void resize(size_t new_capacity)
    {
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);
        std::copy(data.get(), data.get() + size, new_data.get());
        data = std::move(new_data);
        capacity = new_capacity;
    }

public:
    // Varsayılan Yapıcı
    Vector() : size(0), capacity(2)
    {
        data = std::make_unique<T[]>(capacity);
    }

    // Boyut ve değerle yapıcı
    Vector(size_t n, const T &value) : size(n), capacity(n)
    {
        data = std::make_unique<T[]>(capacity);
        std::fill(data.get(), data.get() + size, value);
    }

    // Kopya Yapıcı
    Vector(const Vector &other) : size(other.size), capacity(other.capacity)
    {
        data = std::make_unique<T[]>(capacity);
        std::copy(other.data.get(), other.data.get() + size, data.get());
    }

    // Taşıma Yapıcı
    Vector(Vector &&other) noexcept : size(other.size), capacity(other.capacity), data(std::move(other.data))
    {
        other.size = 0;
        other.capacity = 0;
    }

    // Başlangıç İteratörü ile Yapıcı
    template <typename InputIterator>
    Vector(InputIterator first, InputIterator last) : size(std::distance(first, last)), capacity(size)
    {
        data = std::make_unique<T[]>(capacity);
        std::copy(first, last, data.get());
    }

    // Eleman Ekleme
    void push_back(const T &value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    // Eleman Çıkarma
    void pop_back()
    {
        if (size == 0)
        {
            throw std::out_of_range("Vector is empty");
        }
        --size;
    }

    // Eleman Erişimi
    T &operator[](size_t index)
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= size)
        {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Kopyalama Operatörü
    Vector &operator=(const Vector &other)
    {
        if (this != &other)
        {
            size = other.size;
            capacity = other.capacity;
            data = std::make_unique<T[]>(capacity);
            std::copy(other.data.get(), other.data.get() + size, data.get());
        }
        return *this;
    }

    // Taşıma Operatörü
    Vector &operator=(Vector &&other) noexcept
    {
        if (this != &other)
        {
            size = other.size;
            capacity = other.capacity;
            data = std::move(other.data);
            other.size = 0;
            other.capacity = 0;
        }
        return *this;
    }

    // Boyut (Size)
    size_t size() const
    {
        return size;
    }

    // Kapasite
    size_t capacity() const
    {
        return capacity;
    }

    // Boşluk Kontrolü
    bool empty() const
    {
        return size == 0;
    }

    // Temizleme
    void clear()
    {
        size = 0;
    }

    // Yıkıcı (Destructor)
    ~Vector() = default;
};
