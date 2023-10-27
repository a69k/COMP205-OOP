#include <iostream>
using namespace std;

class product{
  string name;
  float price;
  int serial;
  static int Pserial;

  public:
  product(){
    serial = Pserial;
    Pserial -= 10;
  }
  void read(){
    cout<<"Enter Product Name: "<<endl;
    cin>>name;
    cout<<"Enter Product Price: "<<endl;
    cin>>price;
  }
  void display(){
    cout<<"Product Name: "<<name<<endl;
    cout<<"Product Net Price: "<<price<<endl;
    cout<<"Product Serial Number: "<<serial<<endl;
  }
  void displayPSerial(){
    cout<<"Pserial: "<< Pserial <<endl;
  }
};

int product::Pserial = 10000;

int main(){
  product x, y, z;
	x.read();
	y.read();
	z.read();
	cout << endl;
	x.display();
	y.display();
	z.display();
	cout << endl;
	x.displayPSerial();
}