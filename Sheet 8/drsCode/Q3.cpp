#include <iostream>
using namespace std;
class Shape{
protected:
    float L;
    float H;

public:
    void read() {
        cout << "Enter length: ";
        cin >> L;
        cout << "Enter height: ";
        cin >> H;
    }

    virtual float area()=0;

    void display()  {
       cout << "Area: " << this->area() << endl;
    }
};
class Triangle : virtual public Shape {
public:
    float area()  {
        return 0.5 * L * H;
    }
};
class Square : virtual public Shape {
public:
    float area()  {
        return L * L;
    }
};

class SqPyramid : virtual public Square, virtual public Triangle {
public:
    float area(){
		return Square::area() + (4*Triangle::area());
    }
};

void main() {
    
    Shape* shapes[3];

    Square square;
    Triangle triangle;
    SqPyramid sqPyramid;

    shapes[0] = &square;
    shapes[1] = &triangle;
    shapes[2] = &sqPyramid;

    for (int i = 0; i < 3; ++i) {
        shapes[i]->read();
        shapes[i]->display();
        cout << endl;
    }

  system("pause");
}
