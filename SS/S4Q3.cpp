#include <iostream>
#include <cmath>
using namespace std;

class XD{
  float X[10];
  int n;

public:
	bool isPrime(float n) {
    if (n == 0 || n == 1) {
      return false;
    }
    for (int i = 2; i <= n / 2; i++) {
      if (fmod(n , i) == 0) {
        return false;
        break;
      }
    }
    return true;
  }

  void read(){
    cout<<"How many elements are in the array X? "<<endl;
    cin>>n;
    for (int i=0; i<n; i++){
    cout<<"Enter Element {"<<i+1<<"}:\n";
    cin>>X[i];
  }}

  float avgPrime(){
    float sum = 0.0;
    float count = 0.0;
    for (int i=0; i<n; i++){
      if (isPrime(X[i])){
        sum+=X[i];
        count++;
      }
    }
    if (count > 0)
    return sum/count;
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
    cout<<"Average of Prime Numbers in X[]:"<<avgPrime()<<endl;
    cout << endl;
  }
  class YD;

  friend void compareAvgAndDisplayMax(XD x,YD y);
  friend void retSumMax(XD x,YD y);
};

class YD{
  float Y[10],a;
  int m;

public:
  void read(){
    cout<<"Enter A:"<<endl;
    cin>>a;
    cout<<"How many elements are in the array Y? "<<endl;
    cin>>m;
    for (int i=0; i<m; i++){
    cout<<"Enter Element {"<<i+1<<"}:\n";
    cin>>Y[i];
  }}

  float avgDivByA(){
    float sum = 0.0;
    float count = 0.0;
    for (int i=0; i<m; i++){
      if(fmod(Y[i],a)==0)
        sum+= Y[i];
        count++;
    }
    if (count > 0)
    return sum/count;
  }

  float maxDivByA(){
    float max=0.0;
    for (int i=0; i<m; i++){
      if (fmod(Y[i],a)==0 && Y[i]>max)
        max = Y[i];
    }
    return max;
  }
  void display() {
    cout << "Elements in YD: ";
    for (int i = 0; i < m; i++) {
      cout << Y[i] << " ";
    }
    cout<< "Avg of Elements Divisible by "<<a<<" in Y[]: "<<avgDivByA()<<endl;
    cout<< "Max Element Divisible by "<<a<<" in Y[]: "<<maxDivByA()<<endl;
    cout << endl;
  }
  friend void compareAvgAndDisplayMax(XD x,YD y);
  friend void retSumMax(XD x,YD y);
};

void compareAvgAndDisplayMax(XD x,YD y){
  (x.avgPrime() > y.avgDivByA()) ? x.display(): y.display();
}
void retSumMax(XD x,YD y){
  cout<<"Maximum Prime Number in X[] (XD):"<<x.maxPrime()<<endl<<"Maximum Element Divisible by a in Y[] (YD):"<<y.maxDivByA()<<endl;
}

int main(){
  XD x;
  YD y;

  x.read();
  y.read();

  x.display();
  y.display();

  compareAvgAndDisplayMax(x,y);
  retSumMax(x,y);
}