#include<iostream>
using namespace std;
int max1=0,min1=0,max2=0,min2=0;
void min_max_dc(int *a,int i,int j,int &max1,int &min1){
  if(i==j)
    max1=min1=a[i];
  else if(i==j-1) {
      if(a[i]<a[j]){
        max1=a[j];
        min1=a[i];
      }
      else{
            max1=a[j];
           min1=a[i];
      }
  }
    else{
          int  mid=(i+j)/2;
         min_max_dc(a,i,mid,max1,min1);
         min_max_dc(a,mid+1,j,max2,min2);
    if(max1<max2)
        max1=max2;
    if(min1>min2)
        min1=min2;

      }

}
int main()
{
    int n,key;
    cout<<"Enter Size: ";
    cin>>n;
    int a[n];
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
        cin>>a[i];
    min_max_dc(a,0,n-1,max1,min1);
    cout<<"Max element: "<<max1<<endl;
    cout<<"Min element: "<<min1<<endl;
}
