#include<iostream>
using namespace std;
int BinarySearch(int *arr,int n,int k) {
int low=0,high=n;
 while(low<high) {
      	  int mid=(low+high)/2;
    	if(arr[mid]==k)
        		return mid;
    	else if(arr[mid]<k)
        		low=mid+1;
    	else
        		high=mid-1;
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
	int res=BinarySearch(a,n,key);
	if(res!=-1)
    		cout<<"Element "<<key<<" found at "<<res<<" index";
	else
    		cout<<"Element "<<key<<" not found";
}
