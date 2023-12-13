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

    virtual float calculateArea()=0;

    void displayArea()  {
       cout << "Area: " << calculateArea() << endl;
    }
};
class Triangle : public virtual  Shape {
public:
    float calculateArea()  {
        return 0.5 * L * H;
    }
};
class Square : public virtual  Shape {
public:
    float calculateArea()  {
        return L * L;
    }
};

class SqPyramid : public virtual Square,public virtual Triangle {
public:
    float calculateArea(){
		return Square::calculateArea() + Triangle::calculateArea();
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
        shapes[i]->displayArea();
        cout << endl;
    }

  system("pause");
}
