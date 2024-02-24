#include <iostream>
using namespace std;

class data{
  private:
    string name;
    float price;
    int code;
  public:
   friend istream& operator>>(istream&in,data d){
    cout<<"Enter Name:"<<endl;
    in>>d.name;
    cout<<"Enter Price:"<<endl;
    in>>d.price;
    cout<<"Enter Code:"<<endl;
    in>>d.code;
    return in;
   }

   float rPrice(){
    return price;
   }
};

class product : public data{
  private:
  data P[30];
  int n;
  public:
  product(){
    n=0;
  }
  product (const product&A){
    for(int i=0;i<n;i++)
      P[i]=A.P[i];
    n=A.n;
  }
  void read(){
    for(int i=0; i<n; i++)
      cin>>P[i];
  }
  product operator++(){
    for(int i=0; i<n; i++)
      P[i].price++;
    n++;
      return *this;
  }
  product operator++(int){
    product t= *this;
    for(int i=0; i<n; i++)
      P[i].price++;
    n++;
      return t;
  }

  operator double(){
    double sum=0;
    for(int i=0; i<n; i++)
      sum += double(P[i].rPrice());
    return sum/n;
  }
  bool operator!= (product p){
    return rPrice() != p.rPrice();
  }
  bool operator> (product p){
    return rPrice() > p.rPrice();
  }
  product operator[] (int i){
    return P[i].price;
  }
};

int main(){
  data d;
  product p,a(p);
  p.read();
  a++;
  ++a;
  cout<< p>a;
  cout<< p!=a;
  cout<< p[2];

}