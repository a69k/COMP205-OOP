#include <iostream>
using namespace std;

class Rectangle {
protected:
  float RD[10][2];
  int n;

public:
  //constructor
  Rectangle() {
    n = 0;
  }

  void read() {
    cout << "Enter Number of Rectangles:" << endl;
    cin >> n;

    for (int i = 0; i < n; i++) {
      cout << "Enter length of rectangle " << i + 1 << ": ";
      cin >> RD[i][0];
      cout << "Enter width of rectangle " << i + 1 << ": ";
      cin >> RD[i][1];
    }
  }

  float area(int i) {
    return RD[i][0] * RD[i][1];
  }
};

class RArea : public Rectangle {
protected:
  float RA[10];

public:
  //constructor
  RArea() {
    for (int i = 0; i < n; i++) {
      RA[i] = area(i);
    }
  }

  void printRA() {
    for (int i = 0; i < n; i++) {
      cout << "Area of Rectangle " << i + 1 << ": " << RA[i] << endl;
    }
  }
};

class PVolume : public RArea {
private:
  float H[10];
  float V[10];

public:
  //constructor
  PVolume() {
    for (int i = 0; i < n; i++) {
        cout << "Enter height of cuboid " << i + 1 << ": ";
        cin >> H[i];
        V[i] = RA[i] * H[i];
    }
  }

  void printV() {
    for (int i = 0; i < n; i++) {
        cout << "Volume of Cuboid " << i + 1 << ": " << V[i] << endl;
    }
  }
};

int main() {
  Rectangle r;
  RArea a;
  PVolume v;

  r.read();

  cout << "The area of each rectangle is:" << endl;
  a.printRA();

  cout << "The volume of each cuboid is:" << endl;
  v.printV();

  system("pause");
}

