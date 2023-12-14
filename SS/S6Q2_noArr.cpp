#include <iostream>
#include <cmath>
using namespace std;

class Data{
  string name;
  float age, salary,tax;
  int ID;
public:
	friend istream &operator>>(istream &input, Data &D) {
      cout<<"Enter name:"<<endl;
      input >> D.name;
      cout<<"Enter age:"<<endl;
      input >>D.age;
      cout<<"Enter ID:"<<endl;
      input>> D.ID;
      cout<<"Enter salary:"<<endl;
      input >> D.salary;
      cout<<"Enter income tax:"<<endl;
      input >> D.tax;
        if(D.tax>1)
          D.tax /= 100;
		return input;
      }

  float netSalary(){
    float netSalary=0.0;
    netSalary = salary - (tax*salary);
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

	friend ostream &operator <<(ostream &out, Data &D){
		cout<<"Name: "<<D.rName()<<endl;
		cout<<"Age: "<<D.rAge()<<endl;
		cout<<"ID: "<<D.rID()<<endl;
		cout<<"Salary: "<<D.rSalary()<<endl;
		cout<<"Tax: "<<D.rTax()<<endl;
	}
};
class Employees{
  Data P[20];
  float Ntax[20];
  int n;

public:
  void read(){
    cout<<"Enter Number of Elements (n):"<<endl;
    cin>>n;
    for (int i=0; i<n;i++){
      cout<<"Enter Employee {"<<i+1<<"} Name:\n";
      cin>> P[i];
      Ntax[i] = P[i].netSalary();
    }
  }
  void display(){
    for (int i=0; i<n; i++){
      cout<<"Name\t"<<"Age\t"<<"ID\t"<<"Salary\t"<<"Tax\t"<<"Net Salary"<<endl;
      cout<<"---\t---\t---\t---\t---\t---\n";
      cout<<P[i].rName()<<"\t"<<P[i].rAge()<<"\t"<<P[i].rID()<<"\t"<<P[i].rSalary()<<"\t"<<P[i].rTax()<<P[i].netSalary()<<endl;
    }
  }
  float maxNS(){
    float maxNS= P[0].netSalary();
    for(int i=1; i<n; i++){
      if(P[i].netSalary() > maxNS)
        maxNS = P[i].netSalary();
    }
    return maxNS;
  }
 bool operator >(Employees A){
    return maxNS()>A.maxNS();
 }
 friend void compareAndDisplayMax(Employees A, Employees B);
};

void compareAndDisplayMax(Employees A,Employees B){
  (A.maxNS()>B.maxNS()) ? A.display() : B.display();
}

int main(){
  Employees A,B;
  Data X;

  cin>>X;
  cout<<X;

  A.read();
  B.read();

  (A>B)? cout<<A.maxNS(): cout<<B.maxNS();
  compareAndDisplayMax(A,B);

}