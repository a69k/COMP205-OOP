#include <iostream>
#include <string>
using namespace std;

struct Data {
  string name;
  float salary;
  float tax;
};

class Employee {
private:
  Data E[10];
  int n;

public:
  void readData() {
    cout << "Enter the number of employees (<= 10): ";
    cin >> n;
    for (int i = 0; i < n; i++) {
      cout << "Enter name for employee " << i + 1 << ": ";
      cin >> E[i].name;
      cout << "Enter salary for employee " << i + 1 << ": ";
      cin >> E[i].salary;
      cout << "Enter tax for employee " << i + 1 << ": ";
      cin >> E[i].tax;
      // 3shan lw in % not decimal
      if (E[i].tax > 1)
        E[i].tax /= 100;
    }
  }
  void displayData() {
    for (int i = 0; i < n; i++) {
      cout << "Employee " << i + 1 << " - Name: " << E[i].name << ", Salary: " << E[i].salary << ", Tax: " << E[i].tax << endl;
    }
  }

  friend class NS;
};

class NS {
private:
    float NSL[10];

public:
  void setNetSalaries(Employee X) {
    for (int i = 0; i < X.n; i++) {
      NSL[i] = X.E[i].salary - (X.E[i].tax * X.E[i].salary);
    }
  }

  float sumNetSalaries(Employee X) {
    float total = 0;
    for (int i = 0; i < X.n; i++) {
      total += X.E[i].salary - (X.E[i].tax * X.E[i].salary) ;
    }
    return total;
  }
  void compareAndDisplayMax(Employee X, Employee Y) {
    float nsTotal1 = sumNetSalaries(X);
    float nsTotal2 = sumNetSalaries(Y);

    if (nsTotal1 > nsTotal2) {
      cout << "Employee 1 has a higher net salary." << endl;
      cout << "Total net salary for Employee 1 object: " << nsTotal1 << endl;
    } else if (nsTotal1 < nsTotal2) {
        cout << "Employee 2 has a higher net salary." << endl;
        cout << "Total net salary for Employee 2  object: " << nsTotal2 << endl;
    } else {
        cout << "Both employees have the same net salary." << endl;
    }
  }
};

int main() {
  Employee X, Y;
  NS ns;

  cout << "Enter data for object Employee 1:" << endl;
  X.readData();
  cout << "Enter data for object Employee 2:" << endl;
  Y.readData();

  X.displayData();
  Y.displayData();

  ns.setNetSalaries(X);
  ns.setNetSalaries(Y);
  ns.compareAndDisplayMax(X, Y);
  
  system("pause");
}