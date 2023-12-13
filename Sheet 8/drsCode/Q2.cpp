#include<iostream>
#include<math.h>
using namespace std;
class Base{
public:
 double B[30],A[30],x;
	int n;
public:
		double fact(int num)
	{
		 if(num <= 1)
      return(1);
   else
      return(num * fact(num-1));
	}

	double combination(int a,int b){

	int c= fact(a)/(fact(b)*fact(a-b));

	return c;
	
	}
	void read()
	{
		cout<<"Enter variable x: ";
		cin>>x;
	cout<<"Enter the size of the array: ";
		cin>>n;
		for(int i=0;i<n;i++){
				cout<<"Enter ["<<i+1<<"]: ";
				cin>>A[i];
				B[i]=combination(A[i],x);
		}
	}

	double MaxOfB()
	{
		
		double max=-999999;
	  for(int i=0;i<n;i++){
		if(B[i]>max){
	       max=B[i];
		}
	  }
	  return max;
	}
	double MinOfB()
	{
		double min=999999;
	  for(int i=0;i<n;i++){
		if(B[i]<min){
	       min=B[i];
		}
	  }
	  return min;
	}

virtual double Difference(){
	
	return MaxOfB()-MinOfB();
	}
 void display()
	{
	 cout<<"Difference : "<<Difference()<<endl;
	}
};
class Drive1:public virtual Base{
protected:
	double D1[30];
public: 
   void set()
   { 
	   int sum=0;
	   for(int i=0;i<n;i++){
		  sum=0;
		   for(int j=1;j<i+1;j++){
		   if(fmod(A[i],2)==0)
		     sum+=B[i]-A[i];
		   else
		     sum+=B[i]-A[i];
		  }
		   D1[i]=sum;
		 }
   }
   double Difference(){
	   int m=n/2;
	   double diff;
	   if(n%2==0)
		   diff=D1[m];
	   else
		   diff=D1[m]-D1[m+1];
   
   return diff;
   }
};
class Drive2:public virtual Base{
protected:
	double D2[30];
public: 
   void set()
   { 
	   int mult=1;
	   for(int i=0;i<n;i++){
		  mult=1;
		   for(int j=1;j<i+1;j++){
		   if(fmod(A[i],2)==0)
		     mult*=B[i]+A[i];
		   else
		     mult*=B[i]+A[i];
		  }
		   D2[i]=mult;
		 }
   }
   double Difference(){
   
   return D2[0]-D2[n-1];
   }
};
class Drive:public Drive1,public Drive2{
	int D[30];
public:
	void set()
	{
	
		for(int i=0;i<n;i++)
			D[i]=(A[i]*D1[i])+(B[i]*D2[i]);
   }
double Difference(){
	  double sub=0;
	for(int i=0;i<n;i++)
	 {
	  sub-=D[i];
	 }
	 return sub;
	}
}; 
void main()
{

	Drive1 d1;
	Drive2 d2;
	Drive d;
	Base *b1,*b2,b3,*b4;

	d.read();
	d.Drive1::set();
	d.Drive2::set();
	d.set();

	d1=d;
	b3=d1;
	cout<<"First Class "<<endl;
	b3.display();
	b1=&d1;
	cout<<"Second Class "<<endl;
	b1->Difference();
	b1->display();
	d2=d;
	b2=&d2;
	cout<<"Third Class "<<endl;
	b2->Difference();
	d2.display();
	cout<<"Fourth Class"<<endl;
	b4=&d;
	b4->Difference();
	b4->display();
	system("pause");
}