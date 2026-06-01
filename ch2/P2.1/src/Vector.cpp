#include "Vector.h"
#include <iostream>

Complex::Complex() : r(0.0), i(0.0) {}
Complex::Complex(double real) : r(real), i(0.0) {}
Complex::Complex(double real, double imag) : r(real), i(imag) {}

Complex Complex::operator+(const Complex& o) const { 
    return Complex(r + o.r, i + o.i); 
}
Complex Complex::operator-(const Complex& o) const { 
    return Complex(r - o.r, i - o.i); 
}
Complex Complex::operator*(const Complex& o) const { 
    return Complex(r * o.r - i * o.i, r * o.i + i * o.r); 
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.r << " + " << c.i << "i)";
    return os;
}

template <typename T>
class LocalVector {
public:
    explicit LocalVector(size_t count)
        : size_(count), data_(count ? new T[count]() : nullptr) {}
    ~LocalVector() { delete[] data_; }

    void set(size_t index, const T& value) {
        if (index < size_) {
            data_[index] = value;
        }
    }

    void print() const {
        std::cout << "[";
        for (size_t i = 0; i < size_; ++i) {
            std::cout << data_[i];
            if (i + 1 < size_) {
                std::cout << ", ";
            }
        }
        std::cout << "]\n";
    }

    T dotProduct(const LocalVector& other) const {
        T result;
        size_t limit = size_ < other.size_ ? size_ : other.size_;
        for (size_t i = 0; i < limit; ++i) {
            result = result + (data_[i] * other.data_[i]);
        }
        return result;
    }

private:
    size_t size_;
    T* data_;
};

int doProcess() {
    LocalVector<Complex> cv(2);
    cv.set(0, Complex(2, 3));
    cv.set(1, Complex(1, 2));

    std::cout << "Complex Vector: ";
    cv.print();
    std::cout << "Self Dot Product: " << cv.dotProduct(cv) << "\n";
    return 0;
}