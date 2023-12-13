#include <iostream>
using namespace std;

class Student {
protected :
	string name;
	float age;
	int ID;
public:
	void Read() {
		cout << "name : ";
		cin >> name;
		cout << "age : ";
		cin >> age;
		cout << "ID : ";
		cin >> ID;
		cout << endl;
	}
	void Write() {
		cout << "name : " << name << endl
			<< "age : " << age << endl
			<< "ID : " << ID << endl;
	}
};
class Math : virtual public Student {
protected:
	string MC[3];
	double D[3],sum;
public:
	Math() { D[1] = D[2] = D[3] = sum = 0; }
	void Read() {
		for (int i = 0;i < 3;i++) {
			cout << "MC[" << i + 1 << "] : ";
			cin >> MC[i];
			cout << "D[" << i + 1 << "] (%)= ";
			cin >> D[i];
			sum += D[i];
		}
	}
	void Write() {
		for (int i = 0;i < 3;i++) {
			cout << "MC[" << i + 1 << "] : " << MC[i] << endl
				<< "D[" << i + 1 << "] = " << D[i] << endl
				<< "sum = " << sum << endl;
		}
	}

};
class CS : virtual public Student {
protected:
	string CSC[5];
	double D[5],sum;
public:
	CS() {
		for (int i = 0;i < 5;i++) {
			D[i] = 0;
		}
		sum = 0;
	}
	void Read() {
		for (int i = 0;i < 5;i++) {
			cout << "CSC[" << i + 1 << "] : ";
			cin >> CSC[i];
			cout << "D[" << i + 1 << "] (%)= ";
			cin >> D[i];
			sum += D[i];
		}
	}
	void Write() {
		for (int i = 0;i < 5;i++) {
			cout << "CSC[" << i + 1 << "] : " << CSC[i] << endl
				<< "D[" << i + 1 << "] = " << D[i] << endl
				<< "sum = " << sum << endl;
		}
	}
};
class Result : public Math, public CS {
	double Total;
	char GPA;
  
public:
	Result() { Total = 0; }
	void Read() {
		Student::Read();
		Math::Read();
		CS::Read();
		Total = Math::sum + CS::sum;
		Total /= 8;
		(Total >= 90) ? GPA = 'A' :
			(Total < 90 && Total >= 85) ? GPA = 'B+' :
			(Total < 85 && Total >= 80) ? GPA = 'B'  :
			(Total < 80 && Total >= 70) ? GPA = 'C+' :
			(Total < 70 && Total >= 65) ? GPA = 'C'  :
			(Total < 65 && Total >= 60) ? GPA = 'D'  :
			GPA = 'F';
	}
	void Write() {
		cout << "Total (%)= " << Total << endl
			<< "GPA :" << GPA << endl;
	}
};
void main() {
	Result X;
	X.Read();
	X.Student::Write();
	X.Math::Write();
	X.CS::Write();
}