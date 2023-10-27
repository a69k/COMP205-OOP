#include <iostream>
using namespace std;
struct student {
    string name;
    float age;
    int ID;
    float grades[10];
    float avg;

    void read() {
        cout << "Enter Student's Name: ";
        cin >> name;
        cout << "Enter Student's Age: ";
        cin >> age;
        cout << "Enter 10 grades for the student: ";
        for (int i = 0; i < 10; i++) {
            cin >> grades[i];
        }
        cout << "Enter Student's ID: ";
        cin >> ID;
        float gSum = 0;   //gSum means gradeSum
        for (int i = 0; i < 10; i++) {
            gSum += grades[i];
        }
        avg = gSum / 10;
    }

    void write() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << ID << endl;
        cout << "Average Grade: " << avg << endl;
    }
};

int main() {
  int n;
  cout << "Enter the number of students: ";
  cin >> n;

  student students[n];
  student highestAvgStudent = students[0];
  student lowestAvgStudent = students[0];

  for (int j = 0; j < n; j++) {
      students[j].read();

      if (students[j].avg >= highestAvgStudent.avg) {
          highestAvgStudent = students[j];
      }

      if (students[j].avg <= lowestAvgStudent.avg) {
          lowestAvgStudent = students[j];
      }
  }

  cout << "Student with the highest average grade:\n";
  highestAvgStudent.write();
  cout<<endl;
  cout << "Student with the lowest average grade:\n";
  lowestAvgStudent.write();

  system("pause");
}
