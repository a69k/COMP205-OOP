#include<iostream>
using namespace std;
class Base{
	protected:
    double B[30][30],x;
	int n;
public:
	void read()
	{
		cout<<"Enter variable x"<<endl;
		cin>>x;
	cout<<"enter the size of the matrix: ";
		cin>>n;
		for(int i=0;i<n-1;i++){
			for(int j=0;j<n;j++){
				cout<<"Enter ["<<i+1<<","<<j+1<<"]: ";
				cin>>B[i][j];
			}
		}
	}
	int gcds(int x,int y)
{
   if(y==0)
      return x;
   else
      return gcds(y,x%y);
}
	double Maxgcds(int m)
	{
		
	  double max=gcds(B[0][m],x);
	  for(int i=1;i<n-1;i++){
		if(gcds(B[i][m],x)>max)
	       max=gcds(B[i][m],x);
	  }
	  return max;
	}
	void set()
	{
	 for(int i=0;i<n;i++){
		 B[n-1][i]=Maxgcds(i);
	 }
	}
	//average of last row 
	virtual float average()
	{
	 int sum=0;
	 float avg=0;
	 for(int i=0;i<n;i++)
		 sum+=B[n-1][i];
	 avg=sum/n;
	 return avg;
	}
	void DisplayAvg()
	{
	  cout<<"Average "<<average()<<endl;
	}
	void display()
{
cout<<"Matrix display"<<endl;
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
cout<<" "<<B[i][j]<<" ";
cout<<endl;
}
}

};
class Drive : public Base{
 double D[30];
public:
	int fact(int num)
	{
		 if(num <= 1)
      return(1);
   else
      return(num * fact(num-1));
	}
	void set()
	{
	 for(int i=0;i<n;i++)
	 {
	  D[i]=fact(B[n-1][i]);
	 }
	}
	float average()
	{
	 int sum=D[0]+D[n-1];
	 return sum/2;
	}
};


void main()
{

	Drive b1;
	Base *b2,b3;
	b1.Base::read();
	b1.Base::set();
	b1.display();
	b3=b1;
	b3.DisplayAvg();
	b2=&b1;
	cout<<"second class "<<endl;
	b1.set();
	b2->average();
	b2->DisplayAvg();
	system("pause");
}