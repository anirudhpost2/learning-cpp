#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <vector>
#include <stdexcept>

// The blueprint for Complex
class Complex {
public:
    double r, i;
    Complex();
    Complex(double real);
    Complex(double real, double imag);

    Complex operator+(const Complex& o) const;
    Complex operator-(const Complex& o) const;
    Complex operator*(const Complex& o) const;
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};

// Template class implementation STAYS in the header
template <typename T>
class MathVector {
private:
    std::vector<T> data;
public:
    MathVector(size_t size) : data(size, T(0)) {}
    void set(size_t index, T value) { data.at(index) = value; }
    T get(size_t index) const { return data.at(index); }
    size_t size() const { return data.size(); }

    MathVector<T> operator+(const MathVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Size mismatch");
        MathVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result.set(i, data[i] + other.data[i]);
        return result;
    }

    MathVector<T> operator-(const MathVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Size mismatch");
        MathVector<T> result(size());
        for (size_t i = 0; i < size(); ++i) result.set(i, data[i] - other.data[i]);
        return result;
    }

    T dotProduct(const MathVector<T>& other) const {
        if (size() != other.size()) throw std::invalid_argument("Size mismatch");
        T total = T(0);
        for (size_t i = 0; i < size(); ++i) total = total + (data[i] * other.data[i]);
        return total;
    }

    void print() const {
        std::cout << "[ ";
        for (const auto& val : data) std::cout << val << " ";
        std::cout << "]\n";
    }
};

#endif