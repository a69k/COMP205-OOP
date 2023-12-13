using namespace std;

class Base {
protected:
    double A[30], B[30], x;
    int n;

public:
    double fact(int num) {
        if (num == 0 || num == 1) {
            return 1;
        }
        return num * fact(num - 1);
    }

    double nCr(int n, int r) {
        if (r < 0 || r > n) {
            return 0;  // invalid 
        }
        double result = fact(n) / (fact(r) * fact(n - r));
        return result;
    }

    virtual void read() {
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

    double maxB() const {
        double max = B[0];
        for (int i = 1; i < n; i++) {
            if (max < B[i])
                max = B[i];
        }
        return max;
    }

    double minB() const {
        double min = B[0];
        for (int i = 1; i < n; i++) {
            if (B[i] < min)
                min = B[i];
        }
        return min;
    }

    virtual double diff() const {
        return maxB() - minB();
    }

    void display() const {
        cout << "Difference : " << diff() << endl;
    }
};

class Drive1 : virtual public Base {
protected:
    double D1[30];

public:
    void setD1() {
        for (int i = 0; i < n; i++) {
            if (fmod(A[i], 2) == 0)
                D1[i] = B[i] - A[i];
            else
                D1[i] = B[i] + A[i];
        }
    }

    double diff() const override {
        int m1, m2;
        if (n % 2 == 0) {
            m1 = n / 2;
            return D1[m1];
        }
        else {
            m1 = (n / 2);
            m2 = (n / 2) + 1;
            return D1[m1] - D1[m2];
        }
    }
};

class Drive2 : virtual public Base {
protected:
    int D2[30];

public:
    Drive2() {
        for (int i = 0; i < 30; i++)
            D2[i] = 1;
    }

    void setD2() {
        for (int i = 0; i < n; i++) {
            if (fmod(A[i], 2) == 0)
                for (int j = 1; j < i + 1; j++)
                    D2[i] *= (B[j] + A[j]);
            else
                for (int j = 1; j < i + 1; j++)
                    D2[i] *= (B[j] - A[j]);
        }
    }
};

class Drive : public Drive1, public Drive2 {
    int D[30];

public:
    void setD() {
        for (int i = 0; i < n; i++) {
            D[i] = (A[i] * D1[i]) + (B[i] * D2[i]);
        }
    }

    double diff() const override {
        double diffSum = 0.0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                diffSum += D[i] - D[j];
            }
        }
        return abs(diffSum);
    }
};

int main() {
    Drive1 d1;
    Drive2 d2;
    Drive d;
    Base* b1, * b2, * b3, * b4;

    d.read();
    d.Drive1::setD1();
    d.Drive2::setD2();
    d.setD();

    cout << "First Class " << endl;
    d.display();

    b1 = &d1;
    b1->display();

    cout << "Second Class " << endl;
    b1->diff();
    b1->display();

    d2 = d;
    b2 = &d2;

    cout << "Third Class " << endl;
    b2->diff();
    b2->display();

    cout << "Fourth Class" << endl;
    b4 = &d;
    b4->diff();
    b4->display();

    return 0;
}
