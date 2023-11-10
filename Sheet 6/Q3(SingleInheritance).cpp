#include <iostream>
using namespace std;

class Level {
protected:
  string Course[5];
  float Dg[5];
  int Credit[5];
public:
  void Read() {
    for (int i = 0; i < 5; i++) {
      cout << "Enter course name: ";
      cin >> Course[i];
      cout << "Enter degree: ";
      cin >> Dg[i];
      cout << "Enter credit: ";
      cin >> Credit[i];
    }
  }

  void Display() {
    cout << "Course\tDegree\tCredit" << endl;
    for (int i = 0; i < 5; i++) {
      cout << Course[i] << "\t" << Dg[i] << "\t" << Credit[i] << endl;
    }
  }
};

class Student : public Level {
private:
  string name;
  int ID;
  float total_d;
  int total_c;
  char GPA;

public:
  void Read() {
    Level::Read();

    cout << "Enter student name: ";
    cin >> name;
    cout << "Enter student ID: ";
    cin >> ID;

    // Calculate total dg and total credit
    total_d = 0;
    total_c = 0;
    for (int i = 0; i < 5; i++) {
      total_d += Dg[i];
      total_c += Credit[i];
    }

    // Calculate GPA
    if (total_d / total_c >= 90) {
      GPA = 'A';
    } else if (total_d / total_c >= 85) {
      GPA = 'B+';
    } else if (total_d / total_c >= 80) {
      GPA = 'B';
    } else if (total_d / total_c >= 75) {
      GPA = 'C+';
    } else if (total_d / total_c >= 65) {
      GPA = 'C';
    } else if (total_d / total_c >= 60) {
      GPA = 'D';
    } else {
      GPA = 'F';
    }
  }

  void Display() {
    cout << name << "\t" << ID << "\t" << total_d << "\t" << total_c << "\t" << GPA << endl;
  }
};

int main() {
  int n;
  cout << "Enter number of students: ";
  cin >> n;

  Student students[n];

  for (int i = 0; i < n; i++) {
    students[i].Read();
  }

  cout << "Student Name\tID\tTotal Dg\tTotal Credit\tGPA" << endl;
  for (int i = 0; i < n; i++) {
    students[i].Display();
  }

  system("pause");
}