#include <iostream>
using namespace std;

void functionB(int n, int A[]) {
  cout << endl;
  for (int i = 0; i < n; i++) {
      cout << "A[" << i + 1 << "] = " << A[i] << endl;
  }
}

void functionC(int n, int A[]) {
  int j = n - 1, B[100];
  for (int i = 0; i < n; i++) {
    B[j] = A[i];
    j--;
  }
  for (int i = 0; i < n; i++) {
    A[i] = B[i];
  }
  cout << endl << "Done\n";
}

void functionD(int n, int A[]) {
  int B[100], counter = 0, m = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m + 1; j++) {
      if (m != 0) {
          if (A[i] == B[j]) {
              counter = 1;
          }
        }
      }
      if (counter != 0) continue;
      for (int j = 0; j < n; j++) {
        if (i == j) continue;
        if (A[i] == A[j]) counter++;
      }
      if (counter != 0) {
        cout << "Number " << A[i] << " occurs " << counter + 1 << " times \n";
        B[m] = A[i];
        m++;
      }
    counter = 0;
  }
}

void functionE(int n, int A[]) {
    int B[100], sum = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= i; j++) {
        sum += A[j];
        }
      B[i] = sum;
      sum = 0;
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
      cout << "B[" << i + 1 << "] = " << B[i] << endl;
    }
}

void functionA(int n, int A[]) {
    int x;
    for (int i = 0; i < n; i++) {
      cout << "A[" << i + 1 << "] = ";
      cin >> A[i];
    }
    do {
        cout << "Which function do you want to use?\n"
          << "1-b (Display)\n"
          << "2-c (Reverse)\n"
          << "3-d (Return the occurrence for every number)\n"
          << "4-e (Sum)" << endl;
        cin >> x;
        switch (x) {
          case 1: functionB(n, A); break;
          case 2: functionC(n, A); break;
          case 3: functionD(n, A); break;
          case 4: functionE(n, A); break;
        }
    } while (true);
    cout << endl;
}

int main() {
  int n, A[100];
  cout << "Q3\n" << "Enter array length...\n" << "N = ";
  cin >> n;
  cout << endl;
  functionA(n, A);
  return 0;
}
