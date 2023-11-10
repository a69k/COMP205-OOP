#include <iostream>
#include <cmath>
using namespace std;

class Datal {
protected:
  string ND1;
  int D1[20];
  int n;

public:
  void Read() {
    cout << "Enter name of data set 1: ";
    cin >> ND1;
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
      cout << "Enter data element "<< i + 1 << ": ";
      cin >> D1[i];
    }
  }

  int Total() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      for(int j=1; j<i+1; j++){
        if (D1[i] % 2 == 0) {
        sum += pow(D1[i],2*j);
        } else {
        sum += 1;
        }
      }
    }
    return sum;
  }

  void Print() {
    cout << "Name of data set 1: " << ND1 << endl;
    cout << "Number of elements: " << n << endl;

    for (int i = 0; i < n; i++) {
      cout << "Data array element " << i + 1 << ": " << D1[i] << endl;
    }
  }
};

class Data2 {
protected:
  string ND2;
  int D2[20];
  int m;

public:
  void Read() {
    cout << "Enter name of data set 2: ";
    cin >> ND2;
    cout << "Enter number of elements: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
      cout << "Enter data element " << i + 1 << ": ";
      cin >> D2[i];
    }
  }

  int Total() {
    int sum = 0;
    for (int i = 0; i < m; i++) {
      for(int j=1; j<i+1; j++){
        if (D2[i] < 0) {
        sum += pow(D2[i],2*j);
        } else {
        sum += 1;
        }
      }
    }
    return sum;
  }

  void Print() {
    cout << "Name of data set 2: " << ND2 << endl;
    cout << "Number of elements: " << m << endl;

    for (int i = 0; i < m; i++) {
      cout << "Data array element " << i + 1 << ": " << D2[i] << endl;
    }
  }
};

class Data: public Datal, public Data2 {
private:
  string ND;
  int Tsum;

 public:
  void SetData(Datal d1, Data2 d2) {
    cout<<"Enter name of the Inherited Data Class:"<<endl;
    cin>>ND;
    Tsum = d1.Total() + d2.Total();
  }

  void Print() {
    cout << "Name of data set: " << ND << endl;
    cout << "Total sum: " << Tsum << endl;
  }
};

int main() {
  Datal d1;
  Data2 d2;

  d1.Read();
  d2.Read();

  Data d;

  d.SetData(d1, d2);

  d.Print();

  system("pause");
}