#include <iostream>
#include <cmath>

using namespace std;
struct Series {
	int n;
	float x;
	double S1, S2;

int factorial() {
	int Fn=1;
	for (int i = 1;i <= n;i++)
		Fn *= i;
	return Fn;
}

void read() {
	int m=1;
	cout << endl << "n : ";
	cin >> n;
	cout << "x :";
	cin >> x;
	S1 = 0;
	S2 = 0;
	for (int i = 1;i <= n;i++) {
		int Fi = factorial();
		if (i % 2 == 1) {
			S1 += m * (Fi / (pow(pow(x, i) + i, 0.5)));
			m *= -1;
		}
		if (i % 2 == 0) S2 += m * (Fi / (pow(pow(x, i) + i, 0.5)));
		Fi = 1;
		m *= -1;
	}
}

void display() {
	cout << "n : " << n << " & x : " << x << " <<^>> S1 : " << S1 << " & S2 :" << S2 << endl << endl;
}
};

int main() {
	Series A[3];
	for (int i=0; i<3; i++)
		A[i].read();
	for (int i=0; i<3; i++)
		A[i].display();

    system("pause");
}