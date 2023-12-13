#include <iostream>
#include <cmath>
using namespace std;

class Base {
protected:
    double A[30], B[30], x;
    int n;

public:
    double fact(int num) {
        if (num <= 1)
            return 1;
        else
            return num * fact(num - 1);
    }
    double nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;  // invalid dr completely missed this check
        }
        double result = fact(n) / (fact(r) * fact(n - r));
        return result;
    }
    void read() {
        cout << "Enter Number Of Elements in Array A:" << endl;
        cin >> n;
        cout << "Enter X:" << endl;
        cin >> x;
        for (int i = 0; i < n; i++) {
            cout << "Enter Array A Element {" << i + 1 << "}:" << endl;
            cin >> A[i];
            B[i] = nCr(A[i], x);
        }
    }
    double maxB() {
        double max = B[0];
        for (int i = 1; i < n; i++) {
            if (B[i] > max)
                max = B[i];
        }
        return max;
    }
    double minB() {
        double min = B[0];
        for (int i = 1; i < n; i++) {
            if (B[i] < min)
                min = B[i];
        }
        return min;
    }
    virtual double diff() {
        return maxB() - minB();
    }

    void display() {
        cout << "Difference : " << this->diff() << endl;
    }
};
class Drive1 : virtual public Base {
protected:
    double D1[30];

public:
    void set() {
        for (int i = 0; i < n; i++) {
            if (fmod(A[i], 2) == 0)
                D1[i] = B[i] - A[i];
            else
                D1[i] = B[i] + A[i];
        }
    }
    double diff(){
        int m= n/2;
        if (n % 2 == 0) 
            return D1[m];
        else 
            return D1[m] - D1[m+1];
    }
};
class Drive2 : virtual public Base {
protected:
    int D2[30];

public:
    void set() {
        for (int k=0; k<30; k++)
            D2[k]=1;
        for (int i = 0; i < n; i++) {
            if (fmod(A[i], 2) == 0)
                for (int j = 1; j < i + 1; j++)
                    D2[i] *= (B[j] + A[j]);
            else
                for (int j = 1; j < i + 1; j++)
                    D2[i] *= (B[j] - A[j]);
        }
    }
    double diff() {
        return D2[0] - D2[n - 1];
    }
};
class Drive : public Drive1, public Drive2 {
    int D[30];

public:
    void set() {
        for (int i = 0; i < n; i++) {
            D[i] = (A[i] * D1[i]) + (B[i] * D2[i]);
        }
    }

    double diff() {
        double diffSum = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diffSum += D[i] - D[j];
            }
        }
        return abs(diffSum);
    }
};

int main(){
    Base b,*dr1,*dr2,*dr;
	Drive1 d1;
	Drive2 d2;
	Drive d;
	
	d.read();
	d.Drive1::set();
	d.Drive2::set();
	d.set();

	cout<<"Base Class "<<endl;
    b=d1;
	b.display();

	cout<<"Drive1 Class "<<endl;
    d1=d;
    dr1=&d1;
	dr1->display();

	cout<<"Drive2 Class:"<<endl;
    d2=d;
	dr2=&d2;
	dr2->display();

	cout<<"Drive Class:"<<endl;
	dr=&d;
	dr->display();

	system("pause");
}