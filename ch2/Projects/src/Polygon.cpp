#include "../include/Polygon.h"
#include <iostream>
#include <cmath>

// --- Triangle Implementation ---
Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}
double Triangle::perimeter() const { return a + b + c; }
double Triangle::area() const {
    double s = perimeter() / 2;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
std::string Triangle::getName() const { return "General Triangle"; }
void Triangle::doProcess() {
    std::cout << "Enter 3 sides of the triangle: ";
    std::cin >> a >> b >> c;
    std::cout << getName() << " -> Area: " << area() << ", Perimeter: " << perimeter() << "\n";
}

EquilateralTriangle::EquilateralTriangle(double side) : Triangle(side, side, side) {}
std::string EquilateralTriangle::getName() const { return "Equilateral Triangle"; }

// --- Rectangle Implementation ---
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
double Rectangle::perimeter() const { return 2 * (width + height); }
double Rectangle::area() const { return width * height; }
std::string Rectangle::getName() const { return "Rectangle"; }
void Rectangle::doProcess() {
    std::cout << "Enter width and height: ";
    std::cin >> width >> height;
    std::cout << getName() << " -> Area: " << area() << ", Perimeter: " << perimeter() << "\n";
}

Square::Square(double side) : Rectangle(side, side) {}
std::string Square::getName() const { 
    return "Square"; 
}