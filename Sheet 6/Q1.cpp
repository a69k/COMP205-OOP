#include <iostream>
#include <cmath>

using namespace std;

class Data {
    double A[20],B[20];
    int n;

public:
    friend istream &operator>>(istream &input, Data &D) {
        input >> D.n;
        for (int i = 0; i < D.n; i++)
            input >> D.A[i];
        return input;
    }
    friend ostream &operator<<(ostream &out, Data &D){
        for (int i = 0; i < D.n; i++)
          out << D.A[i];
        return out;
    }
    double Af(){
      double fSum=0;
      for (int i=0; i<n; i++){
        for(int j=1; j<i+1; j++){
          fSum += (A[i],j);
          }
      }
    }
    double sumB(){
      double sumB=0;
      for (int i=0; i<n; i++)
      sumB += B[i];
      return sumB;
    }

    double operator[](int index){
    if (index >= 0 && index < n){
      return B[index];
    }else{
      return -1.0;
    }
  }
  bool operator<(Data D){
    double sum = 0.0;
    double sumOther = 0.0;
    for (int i = 0; i < n; i++){
      sum += A[i];
      sumOther += D.A[i];
    }
    return sum < sumOther;
  }
   bool operator==(Data D) {
    if(sumB()==D.sumB())
    return true;
    return false;
  }
};

int main() {
    Data data1, data2;
    cout << "Enter data for the first object:" << endl;
    cin >> data1;
    cout << "Enter data for the second object:" << endl;
    cin >> data2;

    cout << "Data for the first object: " << data1 << endl;
    cout << "Data for the second object: " << data2 << endl;

    // the formula function for A[n] for data 1 obj
    cout << "Af() for the first object: " << data1.Af() << endl;

    // the sum of B[n] for data 1 obj
    cout << "Sum of B for the first object: " << data1.sumB() << endl;

    //operator[] function to search at index
    int index = 2;
    cout << "Value at index " << index << " in B for the first object: " << data1[index] << endl;

    // operator< to compare between the arrays A[n] for the two objects
    if (data1 < data2) {
        cout << "The first object is less than the second object." << endl;
    } else {
        cout << "The first object is not less than the second object." << endl;
    }

    // operator== to check if 
    if (data1 == data2) {
        cout << "The first object is equal to the second object." << endl;
    } else {
        cout << "The first object is not equal to the second object." << endl;
    }

    system ("pause");
}


