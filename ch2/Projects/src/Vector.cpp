#include "../include/Vector.h"
#include <iostream>

// DO NOT write "class Complex {" here. Just define the methods:

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