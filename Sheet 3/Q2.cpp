#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    int R;
    int I;

public:
    Complex(int real = 0, int imag = 0) : R(real), I(imag) {}

    void displayComplex() {
        cout << R << " + " << I << "i" << endl;
    }

    double toReal() {
        return sqrt(R * R + I * I);
    }

    Complex multiply(Complex& X) {
        int realPart = (R * X.R) - (I * X.I);
        int imagPart = (R * X.I) + (I * X.R);
        return Complex(realPart, imagPart);
    }

    Complex divide(Complex& X) {
        int divisor = (X.R * X.R) + (X.I * X.I);
        int realPart = ((R * X.R) + (I * X.I)) / divisor;
        int imagPart = ((I * X.R) - (R * X.I)) / divisor;
        return Complex(realPart, imagPart);
    }

    Complex max(Complex& X) {
        double cmplx1 = (R * R) + (I * I);
        double cmplx2 = (X.R * X.R) + (X.I * X.I);
        if (cmplx1 >= cmplx2)
            return Complex(R, I);
        else
            return Complex(X.R, X.I);
    }

    Complex average(const Complex& X) {
        int avgReal = (R + X.R) / 2;
        int avgImag = (I + X.I) / 2;
        return Complex(avgReal, avgImag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, -2);
    Complex c3(-2, 5);
    Complex c4(0, 1);

    cout << "Complex Number 1: ";
    c1.displayComplex();
    cout << "Complex Number 2: ";
    c2.displayComplex();
    cout << "Complex Number 3: ";
    c3.displayComplex();
    cout << "Complex Number 4: ";
    c4.displayComplex();

    cout << "Real Conversion / Mod of Complex Number 1: " << c1.toReal() << endl;

    Complex product = c1.multiply(c2);
    cout << "Product of complex number 1 and complex number 2: ";
    product.displayComplex();
    cout<<endl;

    Complex division = c1.divide(c2);
    cout << "Division of complex number 1 by complex number 2: ";
    division.displayComplex();
    cout<<endl;

    Complex maxComplex = c1.max(c3);
    cout << "Complex number with maximum (magnitude) from c1 and c3: "; // again noting the use of mod for the max
    maxComplex.displayComplex();
    cout<<endl;

    Complex avg = c1.average(c4);
    cout << "Average of c1 and c4: ";
    avg.displayComplex();
    cout<<endl;

    system("pause");
}
