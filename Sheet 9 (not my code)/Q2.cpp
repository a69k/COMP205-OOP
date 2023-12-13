#include<iostream>
using namespace std;
template <class T>
class Matrix {
protected :
  T M[10][10];
  T n,m;
public :
void read(){
cout<<"Enter rows"<<endl;
cin>>n;
cout<<"Enter number of columns"<<endl;
cin>>m;
for(int i=0;i<n;i++){
 for(int j=0;j<m;j++){
	 cout<<"Enter element M["<<i+1<<","<<j+1<<"]: ";
  cin>>M[i][j];
 }}}
void display() {
cout<<"Matrix display : "<<endl;
for(int i=0;i<n;i++){
  for(int j=0;j<m;j++)
     cout<<" "<<M[i][j]<<" ";
  cout<<endl;
}}

Matrix<T> prod(Matrix<T> m2){
Matrix<T> m1;
m1.n=n;
m1.m=m2.m;
if(m!=m2.n)
cout<<"Matrix can not be multipled"<<endl;
else{
for(int i=0;i<n;i++){
   for(int j=0;j<m2.m;j++){
    m1.M[i][j]=0;
   for(int k=0;k<m2.n;k++)
    m1.M[i][j]+=M[i][k]*m2.M[k][j];
   }}}
return m1;
}
T DiagonalSum(){
	T sum=0;
for(int i=0;i<n;i++){
for(int j=0;j<m;j++){
 if(i==j)
	 sum+=M[i][j];
}}
return sum;
}
T max(int index);
T min(int index);
};
template <typename T>
T Matrix<T>::max(int index) {
    T Maxelement = M[0][index];
    for (int i = 1; i < m; i++) {
        if (M[i][index] > Maxelement) {
            Maxelement = M[i][index];
        }
    }
    return Maxelement;
}
template <typename T>
T Matrix<T>::min(int index) {
    T Minelement = M[0][index];
    for (int i = 1; i < m; i++) {
        if (M[i][index] < Minelement) {
            Minelement = M[i][index];
        }
    }
    return Minelement;
}
void main()
{
	 Matrix<int> Mat1, Mat2, Mat3;
	 Mat1.read();
	 Mat2.read();
    
    Mat3 = Mat1.prod(Mat2);

    cout << "Result of matrix multiplication:\n";
    Mat3.display();

    cout << "Sum of diagonal elements: " << Mat1.DiagonalSum() << '\n';

    int index;
    cout << "Enter a column index to find max and min elements: ";
    cin >> index;

    cout << "Max element in column " << index << ": " << Mat1.max(index) << endl;
    cout << "Min element in column " << index << ": " << Mat2.min(index) << endl;
	
 system("pause");
}