#ifndef POLYGON_H
#define POLYGON_H

#include <string>

class Polygon {
public:
    virtual ~Polygon() = default;
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string getName() const = 0;
    virtual void doProcess() = 0; 
};

// --- Triangle Branch ---
class Triangle : public Polygon {
protected:
    double a, b, c;
public:
    Triangle(double s1 = 0, double s2 = 0, double s3 = 0);
    double perimeter() const override;
    double area() const override;
    std::string getName() const override;
    void doProcess() override;
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side = 0);
    std::string getName() const override;
};

// --- Quadrilateral Branch ---
class Rectangle : public Polygon {
protected:
    double width, height;
public:
    Rectangle(double w = 0, double h = 0);
    double perimeter() const override;
    double area() const override;
    std::string getName() const override;
    void doProcess() override;
};

class Square : public Rectangle {
public:
    Square(double side = 0);
    std::string getName() const override;
};

#endif 