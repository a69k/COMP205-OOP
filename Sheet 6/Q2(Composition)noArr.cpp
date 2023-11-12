#include <iostream>
using namespace std;

class Data{
  string name;
  float age;
  int ID;
  float salary;
  float tax;

  public:
    friend istream &operator>>(istream &input, Data &D) {
      cout<<"Enter name:"<<endl;
      input >> D.name;
      cout<<"Enter age:"<<endl;
      input >>D.age;
      cout<<"Enter ID:"<<endl;
      input>> D.ID;
      cout<<"Enter Salary:"<<endl;
      input >> D.salary;
      cout<<"Enter Tax:"<<endl;
      input >> D.tax;
      if(D.tax>1)
        D.tax /= 100;
    
      return input;
  }

  float netSalary(){
      float netSalary = 0;
      netSalary = salary - (salary * tax);
      return netSalary;    
  }

    string rName(){
      return name;
    }
    float rAge(){
      return age;
    }
    int rID(){
      return ID;
    }
    float rSalary(){
      return salary;
    }
    float rTax(){
      return tax;
    }
};

class Employees{
  Data P[20];
  float Ntax[20];
  int n;

  public:
  Employees(){
    for (int i=0; i<20; i++){
      Ntax[i]=0;
    }
  }

  void read(){
    cout<<"Enter Number of elements of P"<<endl;
    cin>>n;

    for(int i=0; i<n; i++){
      cout<<"Enter Data for P["<<i+1<<"]:"<<endl;
      cin>> P[i];
      Ntax[i] = P[i].netSalary();
    }
  }

  float maxNS(){
    float maxNS=Ntax[0];
    for(int i=1; i<n; i++){
      if(Ntax[i]>maxNS)
        maxNS= Ntax[i];
    }
    return maxNS;
  }

  bool operator>(Employees A){
      return maxNS()>A.maxNS();
  }

  void display(){
    cout << "Name\t"<< "Age\t"<< "ID\t"<< "Salary\t"<< "Tax\t"<< "Net Salary"<< endl;
    cout << "-----------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        cout << P[i].rName() << "\t" << P[i].rAge() << "\t" << P[i].rID() << "\t"<< P[i].rSalary() << "\t" << P[i].rTax() << "\t| "<< P[i].netSalary() << endl;
    }
  }

  friend void compare(Employees A,Employees B);
};

void compare(Employees A,Employees B){
    float totalNS=0;
    float totalNSb=0;
    for (int i = 0; i < A.n; i++) {
      totalNS += A.Ntax[i];
    }
    for (int i = 0; i < B.n; i++) {
      totalNSb += B.Ntax[i];
    }
    if (totalNS>totalNSb)
      cout<<"The first object's net salaries are greater than the second object's"<<endl;
    else 
      cout<<"The second object's net salaries are greater than the first object's"<<endl;
}

int main(){
  Employees employeesA, employeesB;
  employeesA.read();
  employeesB.read();
  employeesA.display();
  employeesB.display();

  employeesA.maxNS();
  employeesB.maxNS();

  if(employeesA>employeesB)
    cout<<"Object Employees A has a greater max NS"<<endl;
  else
  cout<<"Object Employees B has a greater max NS"<<endl;

  compare(employeesA,employeesB);
}