// unfinished

#include <iostream>
#include <cmath>

using namespace std;

class GCD {
private:
    float X[20];
    float Y[20];
    int n;
    int G[20];

public:
    GCD() {
        for (int i = 0; i < 20; i++) {
            X[i] = 0.0;
            Y[i] = 0.0;
            G[i] = 0;
        }
        n = 0;
    }

    int calcGCD(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return calcGCD(b, a % b);
        }
    }

    void read() {
        cout << "Enter the number of elements (n, <= 20): ";
        cin >> n;

        if (n < 0 || n > 20) {
            cout << "Invalid number of elements. Please enter a value between 0 and 20." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            cout << "Enter X[" << i << "]: ";
            cin >> X[i];

            cout << "Enter Y[" << i << "]: ";
            cin >> Y[i];

            if (X[i] <= 0 || Y[i] <= 0) {
                cout << "X[" << i << "] and Y[" << i << "] must be positive integers. Please enter valid values." << endl;
                i--;
            } else {
                G[i] = calcGCD(static_cast<int>(X[i]), static_cast<int>(Y[i]));
            }
        }
    }

    void displayData() {
        cout << "Index\tX\tY\tGCD" << endl;
        for (int i = 0; i < n; i++) {
            cout << i << "\t" << X[i] << "\t" << Y[i] << "\t" << G[i] << endl;
        }
    }

    int minGCD() {
        if (n == 0) {
            return 0;
        }

        int min = G[0];
        for (int i = 1; i < n; i++) {
            if (G[i] < min) {
                min = G[i];
            }
        }
        return min;
    }

    void displayMin(const GCD& other) {
        int minThis = minGCD();
        int minOther = other.minGCD();

        if (minThis < minOther) {
            cout << "This object has the minimum GCD: " << minThis << endl;
        } else if (minOther < minThis) {
            cout << "Other object has the minimum GCD: " << minOther << endl;
        } else {
            cout << "Both objects have the same minimum GCD: " << minThis << endl;
        }
    }
};

int main() {
    GCD gcd1,gcd2;

    cout << "Enter data for Object 1:" << endl;
    gcd1.read();

    cout << "Enter data for Object 2:" << endl;
    gcd2.read();

    cout << "Data for Object 1:" << endl;
    gcd1.displayData();

    cout << "Data for Object 2:" << endl;
    gcd2.displayData();

    gcd1.displayMin(gcd2);

    return 0;
}
