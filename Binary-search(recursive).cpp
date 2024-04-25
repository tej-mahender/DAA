#include<iostream>
using namespace std;
int BinarySearch(int *arr,int low,int high,int k) {
int mid=(low+high)/2;
if(low<high) {
    	if(arr[mid]== k)
        		return mid;
    	else if(arr[mid]<k)
       	    return BinarySearch(arr,mid+1,high,k);
    	else
        	return BinarySearch(arr,low,mid-1,k);
	}
	return -1;
}
int main() {
	int n,key;
	cout<<"Enter Size: ";
	cin>>n;
	int a[n];
	cout<<"Enter array elements: ";
	for(int i=0;i<n;i++)
    		cin>>a[i];
	cout<<"Enter element to be searched:  ";
	cin>>key;
	int res=BinarySearch(a,0,n,key);
	if(res!=-1)
    		cout<<"Element "<<key<<" found at "<<res<<" index";
	else
    		cout<<"Element "<<key<<" not found";
}
