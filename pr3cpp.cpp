#include <iostream>
#include <cmath>
using namespace std;

class Shape {
private:
    string color;
    double area;

protected:
    void setArea(double a) {
        area = a;
    }

public:
    void setColor(const string& c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    double getArea() const {
        return area;
    }

    virtual void calculateArea() = 0;  
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r, const string& color) {
        radius = r;
        setColor(color);
    }

    void calculateArea() override {
        double area = M_PI * radius * radius;
        setArea(area);
    }
};
class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w, const string& color) {
        length = l;
        width = w;
        setColor(color);
    }

    void calculateArea() override {
        double area = length * width;
        setArea(area);
    }
};


int main() {
    Circle c(5.0, "Red");
    c.calculateArea();
    cout << "Circle - Color: " << c.getColor() << ", Area: " << c.getArea() << endl;

    Rectangle r(4.0, 6.0, "Blue");
    r.calculateArea();
    cout << "Rectangle - Color: " << r.getColor() << ", Area: " << r.getArea() << endl;

    
}
/*
output:
Circle - Color: Red, Area: 78.5398
Rectangle - Color: Blue, Area: 24
*/