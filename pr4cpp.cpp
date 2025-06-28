#include <iostream>
using namespace std;

class Shape
 {
private:
    string color;
    int area;

public:
    Shape() : color("undefined"), area(0) {	}

    void setColor(const string& c) {
        color = c;
    }

    string getColor() const {
        return color;
    }

    int getArea() const {
        return area;
    }

    void setArea(int a) {
        area = a;
    }

    virtual void calculateArea() = 0; 

    virtual void display()  = 0; 

   
};

class Circle : public Shape
{
private:
    int radius;

public:
    Circle() : radius(0) {}

    void setRadius(int r) 
	{
        radius = r;
    }

    void calculateArea() 
	 {
        const int PI = 3.14;
        int a = PI * radius * radius;
        setArea(a);
    }

    void display() 
	 {
        cout << "Circle:" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
 {
private:
    int width;
    int height;

public:
    Rectangle() : width(0), height(0) {	}

    void setWidth(int w) {
        width = w;
    }

    void setHeight(int h) {
        height = h;
    }

    void calculateArea() 
	{
        int a = width * height;
        setArea(a);
    }

    void display() 
	 {
        cout << "Rectangle:" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Width: " << width << " Height: " << height << endl;
        cout << "Area: " << getArea() << endl;
        
    }
};

int main() 
{
     Circle c;
    c.setColor("pink");
    c.setRadius(10);
    c.calculateArea();

    Rectangle r;
    r.setColor("yellow");
    r.setWidth(34);
    r.setHeight(6);
    r.calculateArea();

    Shape* shapes[2] = { &c, &r };

    for (int i = 0; i < 2; ++i)
	 {
        shapes[i]->display();  
    }

    
}
/*output:
Circle:
Color: pink
Radius: 10
Area: 300
Rectangle:
Color: yellow
Width: 34 Height: 6
Area: 204
*/