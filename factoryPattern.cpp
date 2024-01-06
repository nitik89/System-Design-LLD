#include<iostream>
#include<string>
using namespace std;
class Shape{
    public:
    virtual void draw()=0;
};

class Rectangle : public Shape {
public:
    void draw() {
        std::cout << "Drawing a Rectangle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw()  {
        std::cout << "Drawing a Square." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw()  {
        std::cout << "Drawing a Circle." << std::endl;
    }
};

class ShapeFactory{
    public:
    Shape* getShape(string shape){
        Shape * shapeFactory=NULL;
            if (shape == "CIRCLE") {
            shapeFactory = new Circle();
        } else if (shape == "RECTANGLE") {
            shapeFactory = new Rectangle();
        } else if (shape == "SQUARE") {
            shapeFactory = new Square();
        } else {
            cout << "Invalid shape type." << std::endl;
        
        }
        if(shapeFactory){
            shapeFactory->draw();
        }
        return shapeFactory;
    }
};

int main(){
    ShapeFactory shape;
    shape.getShape("CIRCLE");
    shape.getShape("RECTANGLE");
    shape.getShape("SQUARE");
}
