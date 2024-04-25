#include<iostream>
using namespace std;
int b[50];
void merge(int a[],int low,int mid,int high) {
  int i=low,j=mid+1,k=low;
  while(i<=mid && j<=high) {
     	if(a[i]<a[j]) {
         		b[k]=a[i];
         		i++;
       	}
     	else {
          		b[k]=a[j];
          		j++;
        	}
      	k++;
  }
if(i<=mid){
    	while(i<=mid){
        		b[k]=a[i];
        		i++;
        		k++;
    	}
}
else{
    	while(j<=high){
        		b[k]=a[j];
        		j++;
        		k++;
    	}
}
	for(k=low;k<=high;k++)
    	a[k]=b[k];
}

void mergesort(int a[],int low,int high){
	if(low<high){
          	 	int mid=(low+high)/2;
           		mergesort(a,low,mid);
           		mergesort(a,mid+1,high);
           		merge(a,low,mid,high);
   	}
}
int main(){
	int n;
	cout<<"Enter size : ";
	cin>>n;
	int a[n];
	cout<<"Enter elements : ";
	for(int i=0;i<n;i++)
       		cin>>a[i];
	mergesort(a,0,n-1);
	cout<<"Sorted Array: ";
	for(int i=0;i<n;i++)
       		cout<<b[i]<<" ";
	return 0;
}
