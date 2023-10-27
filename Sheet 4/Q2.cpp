#include <iostream>
#include <cmath>
using namespace std;

class series {
private:
	int x[20],n;
	double s[20];

public:
	series(int a) {
		n = a;
	}
	int fact(int x) {
		if (x <= 1) return 1;
		return x * fact(x - 1);
	}
	int combination(int a, int b) {
		return (fact(a) / (fact(a - b) * fact(b)));
	}
	void setx() {
		for (int i = 0;i < n;i++) {
			cout << "X" << i + 1 << " = ";
			cin >> x[i];
		}
	}
	int sum(int i) {
		int sum = 0;
		for (int j = 0;j <= i;j++) {
			sum += combination(i, j) * pow(x[i], j + 1);
		}
	}
	void setS() {
		for (int i = 0;i < n;i++)
			s[i] = sum(i);
	}
	void display() {
		cout << "i || S || X" << endl;
		for (int i = 0;i < n;i++)
			cout << i << " || " << s[i] << " || " << x[i] << endl;
	}
	friend int sumF(series S);
	friend int compare(series X, series Y);
};
int sumF(series S) {
	double max, min;
	max = min = S.s[0];
	for (int i = 0;i < S.n;i++) {
		if (max < S.s[i])max = S.s[i];
		if (min > S.s[i])min = S.s[i];
	}
	return max + min;
}
int compare(series X, series Y) {
	if (sumF(X) > sumF(Y))return sumF(X);
	return sumF(Y);
}

int main() {
	series A(4), B(6);
	A.setx();
	A.setS();
	cout << endl;

	B.setx();
	B.setS();
	
	cout << endl;
	cout << compare(A, B) << endl;
}
