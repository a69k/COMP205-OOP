#include <iostream>
#include <cmath>
using namespace std;

class Matrix {
private:
    double M[10][10];
    int n, m;

public:
    Matrix() {
        n = 0;
        m = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                M[i][j] = 0.0;
            }
        }
    }

  bool isPrime(float number) {
    if (number <= 1)
        return false;
    for (int i = 2; i * i <= number; i++) {
        if (fmod(number, i) == 0)
            return false;
    }
    return true;
  }
  
// the read except last column function
    void readMatrix() { // without last column
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                cin>> M[i][j];
            }
            cout << endl;
        }
    }

    void displayMatrix() { 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
    }

    double operator[](int index) {
        if (index >= 0 && index < n) {
            return M[index][m - 1];
        } else {
            return -1.0; 
        }
    }

    Matrix operator*(double constant) {
        Matrix result = *this;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                result.M[i][j] *= constant;
            }
        }
        return result;
    }

// >= for last column function
    bool operator>=(Matrix A) {
        double sumLastCol = 0.0;
        double sumOtherLastCol = 0.0;
        for (int i = 0; i < n; i++) {
            sumLastCol += M[i][m - 1];
            sumOtherLastCol += A.M[i][m - 1];
        }
        return sumLastCol >= sumOtherLastCol;
    }

    int rn(){
      return n;
    }
    int rm(){
      return m;
    }
};

int main() {
    Matrix matrix1, matrix2;
  // just the testing part left here
    return 0;
}
