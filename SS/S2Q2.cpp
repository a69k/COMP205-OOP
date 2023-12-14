//Struct example
#include <iostream>
using namespace std;

struct TTax{
  float price;
  float tax;
};
struct Toy{
  string Tname;
  TTax Tprice;
  float Net_Price;

  void set(){
    cout<<"Enter Toy Name:"<<endl;
    cin>>Tname;
    cout<<"Enter Toy Price:"<<endl;
    cin>>Tprice.price;
    cout<<"Enter Toy Tax:"<<endl;
    cin>>Tprice.tax;
    if (Tprice.tax >= 1)
     Tprice.tax /=100;
    Net_Price= Tprice.price - (Tprice.price * Tprice.tax);
  }

  void display(){
    cout<<"Toy Name: "<<Tname<<endl;
    cout<<"Toy Price: "<<Tprice.price<<endl;
    cout<<"Toy Tax: "<<Tprice.tax<<endl;
    cout<<"Toy Net Price: "<<Net_Price<<endl;
  }
};
int main(){
  Toy toys[50];
  int n;
  cout<<"Enter number of toys:\n";
  cin>>n;
  
  for (int i=0; i<n; i++)
    toys[i].set();

  for(int i=0; i<n; i++)
  if(toys[i].Net_Price > 50)
   toys[i].display();
  else 
    return 0;
}