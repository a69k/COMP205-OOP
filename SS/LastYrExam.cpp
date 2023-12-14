#include<iostream>
#include<cmath>
using namespace std;

class Toy {
protected:
	double T[10][10];
	int n;
public:
	void read() {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> T[i][j];
	}
	double product(int i) {
		return (T[i][0] * T[i][n - 1]);
	}

	virtual double prod() {} // pure virtual its only there for pointers for the next classes

	void display() {
		cout << this->prod();
	}
};

class VToy :public Toy {
protected:
	double V[10];
public:
	void set() {
		Toy::read(); // gotta call it here or it cant see the data
		for (int i = 0; i < n; i++)
			V[i] = Toy::product(i);
	}
	double prod() {
		return (V[0] * V[1]);
	}
};

class PToy :public VToy {
	double P[10], t;
public:
	void set() {
		VToy::set(); // gotta call it here or it cant see the data
		do {
			cin >> t;
		} while (t == 0);
		for (int i = 0; i < n; i++)
			P[i] = (pow(t, i) + V[i]) / float(pow(t, i));
	}
	double prod() {
		return (P[n - 1] * P[n - 2]);
	}
};

int main() {
	Toy* p;
	VToy y;
	PToy z;
	p = &y;
	y.set();
	p->display();
	p = &z;
	z.set();
	p->display();
	return 0;
}