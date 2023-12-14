#include <iostream>
#include <string>
using namespace std;

struct TTax {
    float price;
    float tax;
};
struct Toy {
  string Tname;
  TTax Tprice;
  float Net_price;

  void setData() {
    cout << "Enter toy name: ";
    cin >> Tname;
    cout << "Enter the price: ";
    cin >> Tprice.price;
    cout << "Enter the tax rate (in decimal or %): ";
    cin >> Tprice.tax;
    if (Tprice.tax > 1.0) {
        Tprice.tax /= 100; 
    }
    Net_price = Tprice.price * (1.0 + Tprice.tax);
  }

  void display() {
    cout << "Toy Name: " << Tname << endl;
    cout << "Price: " << Tprice.price << endl;
    cout << "Tax Rate: " << Tprice.tax << endl;
    cout << "Net Price: " << Net_price << endl;
  }
};


int main() {
    int n;
    cout << "Enter the number of toys: "<<endl;
    cin >> n;

    TTax::Toy toys[n];

    for (int i = 0; i < n; i++) {
      toys[i].setData(); 
    }

    cout << "Toys with Net Price > 50:"<<endl;
    for (int i = 0; i < n; i++) {
      if (toys[i].Net_price > 50) {
        toys[i].display();
      }
    }

  system("pause");
}
