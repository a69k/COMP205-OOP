#include <iostream>
using namespace std;

class Product
{
private:
  float P[20];
  int n;
  int a;
  int b;
  float avg;

public:
  Product(){
    n = 0;
    a = 0;
    b = 0;
    avg = 0.0;
    for (int i = 0; i < 20; i++){
      P[i] = 0.0;
    }
  }

  void read(){
    cout << "Enter the number of elements (<= 20): ";
    cin >> n;
    if (n > 20){
      cout << "Invalid Input, Try again!" << endl;
      read();
    }

    for (int i = 0; i < n; i++){
      cout << "Enter element " << i + 1 << " Price: ";
      cin >> P[i];
    }

    cout << "Enter the value of a: ";
    cin >> a;

    do{
      cout << "Enter the value of b (b must be greater than a): ";
      cin >> b;
    } while (b <= a);

    int count = 0;
    float sum = 0.0;
    for (int i = 0; i < n; i++){
      if (P[i] >= a && P[i] <= b){
        sum += P[i];
        count++;
      }
      avg = sum / count;
    }
  }

  Product operator+(float tax){
    Product result = *this;
    for (int i = 0; i < n; i++){
      result.P[i] = result.P[i] + tax * result.P[i];
    }
    return result;
  }

  bool operator>(Product A){
    float sum = 0.0;
    for (int i = 0; i < n; i++){
      sum += P[i];
    }
    return sum > A.avg;
  }

  bool operator<(Product A){
    return avg < A.avg;
  }

  float operator[](int index){
    if (index >= 0 && index < n){
      return P[index];
    }else{
      return -1.0; // not found like we used in comp201
    }
  }

  void display(){
    cout << "n: " << n << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "avg: " << avg << endl;
  }
};

int main(){
  Product product1, product2, product3;

  product1.read();
  product2.read();

  product3 = product1 + 0.1;

  if (product1 > product2){
    cout << "Product 1 has a higher total than Product 2." << endl;
  }else{
    cout << "Product 2 has a higher total than Product 1." << endl;
  }
  if (product1 < product2){
    cout << "Product 1 has a lower average than Product 2." << endl;
  }else{
    cout << "Product 2 has a lower average than Product 1." << endl;
  }

  int index = 1;
  float element = product1[index];
  cout << element;

  cout << "Data members of Product 1:" << endl;
  product1.display();

  system("pause");
}
