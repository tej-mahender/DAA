#include<iostream>
using namespace std;
int partition_(int arr[],int low,int high) {
	int i = low,j=high;
	int pivot =arr[low];
	while(i<j) {
    	while(arr[i]<=pivot)
        		i++;
    	while(arr[j]>pivot)
        		j--;
    	if(i<j)
        	swap(arr[i],arr[j]);
	}
	swap(arr[low],arr[j]);
	return j;
}
void quicksort(int arr[],int low,int high) {
	int loc;
	if(low<high){
	loc=partition_(arr,low,high);
	quicksort(arr,low,loc-1);
	quicksort(arr,loc+1,high);
	}
}

int main() {
	int n;
	cout<<"Enter size : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements : ";
	for(int i=0;i<n;i++)
       		cin>>a[i];
	quicksort(a,0,n-1);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
       		cout<<a[i]<<" ";
}
