#include <iostream>
#include <cmath>
using namespace std;

class XD {
private:
  float X[10];
  int n;

public:
  void read() {
    cout << "Enter the number of elements (<= 10): ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> X[i];
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

  float avgPrimes() {
    float sum = 0;
    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(X[i])) {
          sum += X[i];
          primeCount++;
        }
    }
    return (primeCount > 0) ? (sum / primeCount) : 0;
  }

  float maxPrime() {
    float maxPrime = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(X[i]) && X[i] > maxPrime) {
          maxPrime = X[i];
        }
    }
    return maxPrime;
  }

  void display() {
    cout << "Elements in XD: ";
    for (int i = 0; i < n; i++) {
      cout << X[i] << " ";
    }
    cout << endl;
  }
  class YD;
  friend void compareAndDisplayMax(XD xd, YD yd);
  friend float sumOfMax(XD xd, YD yd);
};

class YD {
private:
  float Y[10];
  int m;
  int a;

public:
  void read() {
    cout << "Enter the number of elements (<= 10): ";
    cin >> m;
    cout << "Enter the elements: ";
    for (int i = 0; i < m; i++) {
        cin >> Y[i];
    }
    cout << "Enter the value of 'a': ";
    cin >> a;
  }

  float averageDivisibleByA() {
    float sum = 0;
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (fmod(Y[i], a) == 0) {
          sum += Y[i];
          count++;
        }
    }
    if (count > 0) {
        return sum / count;
    }
    return 0;
  }

  float maxDivbyA() {
    float maxElem = 0;
    for (int i = 0; i < m; i++) {
        if (fmod(Y[i], a) == 0 && Y[i] > maxElem) {
          maxElem = Y[i];
        }
    }
    return maxElem;
  }

  void display() {
    cout << "Elements in YD: ";
    for (int i = 0; i < m; i++) {
      cout << Y[i] << " ";
    }
    cout << endl;
  }

  friend void compareAndDisplayMax(XD xd,YD yd);
  friend float sumOfMax(XD xd, YD yd);
};

void compareAndDisplayMax(XD xd, YD yd) {
  float avgXD = xd.avgPrimes();
  float avgYD = yd.averageDivisibleByA();

  cout << "Average of prime elements in XD: " << avgXD << endl;
  cout << "Average of elements divisible by 'a' in YD: " << avgYD << endl;

  if (avgXD > avgYD) {
      xd.display();
  } else if (avgXD < avgYD) {
      yd.display();
  } else {
      cout << "XD and YD have the same average." << endl;
  }
}

float sumOfMax(XD xd, YD yd) {
  float maxPrimeXD = xd.maxPrime();
  float maxElemYD = yd.maxDivbyA();
  return maxPrimeXD + maxElemYD;
}


int main() {
  XD xd;
  YD yd;

  xd.read();
  yd.read();

  compareAndDisplayMax(xd, yd);

  system("pause");
}
