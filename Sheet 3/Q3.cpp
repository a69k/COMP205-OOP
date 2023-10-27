#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Num {
private:
  float N[10];
  int m;
  string T[10];

public:
  Num() {
    for (int i = 0; i < 10; i++) {
        N[i] = 0.0;
        T[i] = "";
    }
    m = 0;
  }

  int factorial(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
  }

  bool isPrime(int num) {
    if (num <= 1)
        return false;
    if (num <= 3)
        return true;
    if (num % 2 == 0 || num % 3 == 0)
        return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
  }

  void read() {
    cout << "Enter the number of elements (m, <= 10): ";
    cin >> m;

    if (m < 0 || m > 10) {
        cout << "Invalid number of elements. Please enter a value between 0 and 10." << endl;
        return;
    }

    for (int i = 0; i < m; i++) {
        cout << "Enter N[" << i << "]: ";
        cin >> N[i];
        if (N[i] <= 0 || N[i] != floor(N[i])) {
            cout << "N[" << i << "] must be a positive integer. Please enter a valid value." << endl;
            i--;
        } else {
            if (isPrime(floor(N[i]))) {
                T[i] = "prime";
            } else {
                T[i] = "not prime";
            }
        }
    }
  }

  void display() {
    cout << "Index\tN\tT" << endl;
    for (int i = 0; i < m; i++) {
        cout << i << "\t" << N[i] << "\t" << T[i] << endl;
    }
  }

  int sumofPrimeFact() {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        if (T[i] == "prime") {
            sum += factorial(floor(N[i]));
        }
    }
    return sum;
  }

  float nonPrimeAvg() {
    float sum = 0.0;
    int count = 0;
    for (int i = 0; i < m; i++) {
        if (T[i] == "not prime") {
            sum += N[i];
            count++;
        }
    }
    if (count == 0)
        return 0;
    return sum / count;
  }
};
// note for using floor its because you have to floor to search primes anyway, also for factorials so the input should be an integer.
int main() {
  Num number;
  number.read();
  number.display();

  int sumofPrimeFact = number.sumofPrimeFact();
  float nonPrimeAvg = number.nonPrimeAvg();

  cout << "Sum of factorials of prime numbers: " << sumofPrimeFact << endl;
  cout << "Average of not prime numbers: " << nonPrimeAvg << endl;

  return 0;
}
