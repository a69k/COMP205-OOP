#include<iostream>
using namespace std;
template <typename T>
void read(T arr[],T n)
	{
	
	 cout<<"Enter array values"<<endl;
	 for(int i=0;i<n;i++)
	 {
	   cin>>arr[i];
	 }
	}
template <typename T>
void display(T arr[],T n)
	{
	 
	  cout<<"New Shape of Array elements "<<endl;
	  for(int i=0;i<n;i++)
	  {
	   cout<<arr[i]<<" ";
	  }
	 cout<<endl;
	}
template <typename T>
void swapp(T &a,T &b)
	{
	 T temp = a;
    a = b;
    b = temp;
	}
template <typename T>
void merge(T arr[], int first, int mid, int last)
{
 T n1 = mid - first + 1;
 T n2 = last - mid;
T L[100], R[100];
 for (int i = 0; i <= n1; i++)
 L[i] = arr[first+i];
 for (int j =0; j <= n2; j++)
 R[j] = arr[mid+1+j];

T i = 0, j = 0, k = first;
 while (i < n1 && j < n2)
 {
 if (L[i] <= R[j])
 {
 arr[k] = L[i];
 i++;
 }
 else
 {
 arr[k] = R[j];
 j++;
 }
 k++;
 }
 while (i < n1)
 {
 arr[k] = L[i];
 i++;
 k++;
 }
 while (j < n2)
 {
 arr[k] = R[j];
 j++;
 k++;
 }
}
template <typename T>
void mergeSort(T arr[], int first, int last)
{
 if (first < last)
 {
 int mid = (last+first)/2;
 mergeSort(arr, first, mid);
 mergeSort(arr, mid+1, last);
 merge(arr,first, mid, last);
 }
}
template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] >= pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
template <typename T>
int search(T arr[],T n,T num)
 {
	 
    for(int i=0;i<n;i++)
	{	  
	   if(arr[i] ==num )
      	     return i;
	}
           return -1;  
 }
void main()
{
	int n=5,a[10];
	read(a,n);
	mergeSort(a,0,n-1);
	display(a,n);
	int num;
	cout<<"Enter number to search for "<<endl;
	cin>>num;
	cout<<"Searched number : "<<search(a,n,num)<<endl;
	quickSort(a,0,n-1);
	display(a,n);
 system("pause");
}