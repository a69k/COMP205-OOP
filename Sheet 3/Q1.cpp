#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    float age;
    int id;
    double tenMarks[10];
    double avg;

public:
    Student(string n = "no data", float a = 0.0, int i = 0, double m = 0.0) {
        name = n;
        age = a;
        id = i;
        avg = m / 10;
    }

    Student(Student& X) {
        name = X.name;
        age = X.age;
        id = X.id;
        avg = X.avg;
        for (int i = 0; i < 10; i++) {
            tenMarks[i] = X.tenMarks[i];
        }
    }

    void read() {
        cout << "Enter name: " << endl;
        cin >> name;
        cout << "Enter age: " << endl;
        cin >> age;
        cout << "Enter id: " << endl;
        cin >> id;
        for (int i = 0; i < 10; i++) {
            cout << "Enter Grade For Subject (" << i << "): ";
            cin >> tenMarks[i]; 
            avg += tenMarks[i];
        }
        avg /= 10;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
        cout << "Ten Marks: ";
        for (int i = 0; i < 10; i++) {
            cout << tenMarks[i] << " ";
        }
        cout << endl;
        cout << "Average: " << avg << endl;
    }
};

int main() {
    Student student1;
    student1.read();

    Student student2 = student1;

    cout << "Student 1 Information:" << endl;
    student1.display();

    cout << "\nStudent 2 Information (copied from Student 1):" << endl;
    student2.display();

    return 0;
}
