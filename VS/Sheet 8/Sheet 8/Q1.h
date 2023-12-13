using namespace std;

class Base {
protected:
    double B[30][30], x;
    int n;

public:
    Base() {
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++)
                B[i][j] = 0;
        }
        n = 0;
        x = 0;
    }
    void read() {
        //this reads data members except the last row of B
        cout << "Enter Matrix Dimension:" << endl; //nxn matrix
        cin >> n;
        cout << " Enter X:" << endl;
        cin >> x;
        cout << "Fill The Matrix: " << endl;
        for (int i = 0; i < (n - 1); i++) {
            for (int j = 0; j < n; j++) {
                cout << "Enter Matrix Element (" << i + 1 << "," << j + 1 << ")" << endl;
                cin >> B[i][j];
            }
        }
        setLR();
    }
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    double maxColGCD(int colNo) {
        double maxGCD = gcd(B[0][colNo], x);

        for (int i = 1; i < (n - 1); i++) {
            double currentGCD = gcd(B[i][colNo], x);
            maxGCD = max(maxGCD, currentGCD);
        }
        return maxGCD;
    }
    void setLR() {
        for (int i = 0; i < n; i++) {
            B[n - 1][i] = maxColGCD(i);
        }
    }
    double rLR(int i) {
        return B[n - 1][i];
    }
    virtual double avg() {
        double sumLR = 0;
        for (int i = 0; i < n; i++) {
            sumLR += B[n - 1][i];
        }
        return (sumLR / n);
    }
    void display() {
        cout << this->avg() << endl;
    }
};
class Drive : public Base {
    double D[30];
public:
    Drive() {
        for (int i = 0; i < 30; i++)
            D[i] = 0;
        setD();
    }
    double fact(double num) {
        if (num == 0 || num == 1) {
            return 1;
        }
        return num * fact(num - 1);
    }
    void setD() {
        for (int i = 0; i < n; i++) {
            D[i] = fact(rLR(i));
        }
    }
    double avg() {
        return (D[0] + D[n - 1]) / 2;
    }
    
};
int main() {
    Base* p, X;
    Drive Y;

    p = &X;
    p->read();
    p->display();

    p = &Y;
    p->display();

    return 0;
}
