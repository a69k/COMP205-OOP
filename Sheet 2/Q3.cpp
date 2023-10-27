#include <iostream>
using namespace std;

struct GCD {
  int a, b, c;

void read() {
  do {
    cout << "Enter a positive integer for a: ";
    cin >> a;
    if (a < 0) {
      cout << "It must be a positive integer. Try again." << endl;
    }
  } while (a < 0);

  do {
    cout << "Enter a positive integer for b: ";
    cin >> b;
    if (b < 0) {
      cout << "It must be a positive integer. Try again." << endl;
    }
  } while (b < 0);

  int s = min(a,b);
  for (int i = 1; i <= s; i++) {
    if (a % i == 0 && b % i == 0) {
      c = i;
    }
  }
}

void display() {
  cout << "GCD (" << a << "," <<b << ") = " << c << endl;
}
};

int main() {
  int n;
  GCD A[100];
  cout << "Sheet 2, Question 3" << endl;
  cout << "Enter the number of pairs (n): ";
  cin >> n;


  for (int i = 0; i < n; i++) {
    cout << "Pair " << i + 1 << ":" << endl;
    A[i].read();
  }

  cout << "Results:" << endl;
  for (int i = 0; i < n; i++) {
    A[i].display();
  }

  return 0;
}
