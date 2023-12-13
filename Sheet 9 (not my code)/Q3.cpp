#include <iostream>
using namespace std;

template <class T>
class Matrix {
protected:
    T M[10][10];
    T n, m;

public:
    void read() {
        cout << "Enter rows" << endl;
        cin >> n;
        cout << "Enter number of columns" << endl;
        cin >> m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Enter element M[" << i + 1 << "," << j + 1 << "]: ";
                cin >> M[i][j];
            }
        }
    }

    void display() {
        cout << "Matrix display : " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << " " << M[i][j] << " ";
            cout << endl;
        }
    }

    Matrix<T> prod(Matrix<T> m2) {
        Matrix<T> m1;
        m1.n = n;
        m1.m = m2.m;
        if (m != m2.n)
            cout << "Matrix can not be multiplied" << endl;
        else {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m2.m; j++) {
                    m1.M[i][j] = 0;
                    for (int k = 0; k < m2.n; k++)
                        m1.M[i][j] += M[i][k] * m2.M[k][j];
                }
            }
        }
        return m1;
    }

    T DiagonalSum() {
        T sum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j)
                    sum += M[i][j];
            }
        }
        return sum;
    }

    T max(int index);
    T min(int index);
};

template <typename T>
T Matrix<T>::max(int index) {
    T Maxelement = M[0][index];
    for (int i = 1; i < n; i++) {
        if (M[i][index] > Maxelement) {
            Maxelement = M[i][index];
        }
    }
    return Maxelement;
}

template <typename T>
T Matrix<T>::min(int index) {
    T Minelement = M[0][index];
    for (int i = 1; i < n; i++) {
        if (M[i][index] < Minelement) {
            Minelement = M[i][index];
        }
    }
    return Minelement;
}

template <class T>
class Vector : public Matrix<T> {
    T V[20];

public:
    void set() {
        for (int i = 0; i < this->m; i++)
            V[i] = this->max(i) - this->min(i);
    }

    T Summation() {
        T sum = 0;
        for (int i = 0; i < this->m; i++)
            sum += V[i];
        return sum;
    }

    void display() {
        Matrix<T>::display();
        for (int i = 0; i < this->n; i++)
            cout << " | " << V[i] << endl;
    }
	template <class T>
    friend void compareAndDisplayMaxSum(Vector<T>& v1, Vector<T>& v2);
};

template <class T>
void compareAndDisplayMaxSum(Vector<T>& v1, Vector<T>& v2) {
    T sum1 = v1.Summation();
    T sum2 = v2.Summation();

    if (sum1 > sum2) {
        cout << "Max sum is from Vector 1: " << sum1 << endl;
    } else if (sum2 > sum1) {
        cout << "Max sum is from Vector 2: " << sum2 << endl;
    } else {
        cout << "Both vectors have the same sum: " << sum1 << endl;
    }
}

void main() {
    Vector<int> A1, A2;
    A1.read();
    A1.set();
    A1.display();
    cout << "Summation of the vector is = " << A1.Summation() << endl;

    A2.read();
    A2.set();
    A2.display();
    cout << "Summation of the vector is = " << A2.Summation() << endl;

    compareAndDisplayMaxSum(A1, A2);

    system("pause");
  
}
