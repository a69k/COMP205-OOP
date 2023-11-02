#include <iostream>
#include <cmath>
using namespace std;

class Data
{
private:
  double D1[20];
  double D2[20];
  int n;

public:
  Data(){
    n = 0;
    for (int i = 0; i < 20; i++)
    {
      D1[i] = 0.0;
      D2[i] = 0.0;
    }
  }

  void readData(){
    cout << "Enter the number of elements (<= 20): ";
    cin >> n;

    for (int i = 0; i < n; i++){
      cout << "Enter the element " << i + 1 << " of D1: ";
      cin >> D1[i];
      for (int j = 0; j < i; j++){
        if (D1[j] < 0)
          D1[j] *= -1;

        D2[i] = (1 / pow(2, j)) * D1[j];
      }
    }
  }

  Data operator+=(Data D){
    Data result;
    result.n = n;
    for (int i = 0; i < n; i++){
      result.D1[i] = D1[i] + D.D1[i];
      result.D2[i] = D2[i] + D.D2[i];
    }
    return result;
  }

  Data operator++(int)
  {
    Data result = *this;
    for (int i = 0; i < n; i++){
      D1[i]++;
      D2[i]++;
    }
    return result;
  }

  Data &operator++()
  {
    for (int i = 0; i < n; i++){
      D1[i]++;
      D2[i]++;
    }
    return *this;
  }

  bool operator>(Data D){
    double sumD2 = 0.0;
    double sumOtherD2 = 0.0;
    for (int i = 0; i < n; i++){
      sumD2 += D2[i];
      sumOtherD2 += D.D2[i];
    }
    return sumD2 > sumOtherD2;
  }

  double operator[](int index){
    if (index >= 0 && index < n){
      return D2[index];
    }else{
      return -1.0;
    }
  }
  friend void compareAndDisplayMin(Data data1, Data data2);
};

void compareAndDisplayMin(Data data1, Data data2)
{
  double sumD2a = 0.0;
  double sumD2b = 0.0;
  for (int i = 0; i < data1.n; i++){
    sumD2a += data1.D2[i];
  }
  for (int i = 0; i < data2.n; i++){
    sumD2b += data2.D2[i];
  }

  if (sumD2a < sumD2b){
    cout << "Object 1 has a smaller sum of D2 elements." << endl;
  }else if (sumD2a > sumD2b){
    cout << "Object 2 has a smaller sum of D2 elements." << endl;
  }else{
    cout << "Both objects have the same sum of D2 elements." << endl;
  }
}

int main()
{
  Data data1, data2, result;

  cout << "Enter data for Object 1:" << endl;
  data1.readData();

  cout << "Enter data for Object 2:" << endl;
  data2.readData();

  result = data1 += data2;

  // Postfix ++
  data1++;
  data2++;

  // Prefix ++
  ++data1;
  ++data2;

  // Greater than (>) for D2
  if (data1 > data2)
  {
    cout << "Object 1 has a larger sum of D2 elements." << endl;
  }
  else
  {
    cout << "Object 2 has a larger sum of D2 elements." << endl;
  }

  // operator [] for D2
  int index = 1; // you can change index to see others
  double element = data1[index];
}
