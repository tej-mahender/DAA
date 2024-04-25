#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void knapsack(vector<int>p,vector<int>w,int n,int m) {
    vector<float>x(n,0);
    int i,u=m;
    for(i=0;i<n;i++)   {
        if(w[i]>u)
            break;
        else   {
            x[i]=1;
            u=u-w[i];
        }
    }
    if(i<n)
        x[i]=(float)u/w[i];
    float profit=0;
    for(i=0;i<n;i++)
        profit=profit+(float)p[i]*x[i];
    float weight=0;
    for(i=0;i<n;i++)
        weight=weight+(float)w[i]*x[i];
    cout<<"Solution Vector is: ";
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<"Profit is: "<<profit<<endl;
    cout<<"weight is: "<<weight<<endl;
}
int main() {
    int n,m,val;
    float r;
    cout<<"Enter the no.of objects and weight of Bag:";
    cin>>n>>m;
    vector<int>p;
    vector<int>w;
    vector<float>arr;
    cout<<"Enter the profits:";
    for(int i=0;i<n;i++)  {
        cin>>val;
        p.push_back(val);
    }
    cout<<"Enter the weights:";
    for(int i=0;i<n;i++) {
        cin>>val;
        w.push_back(val);
    }
    for(int i=0;i<n;i++) {
        r=(float)p[i]/w[i];
        arr.push_back(r);
    }
    int i=0;
    int cou=1;
    while(cou!=n-1) {
        r=*max_element(arr.begin(),arr.end());
        auto it=find(arr.begin(),arr.end(),r);
        val=it-arr.begin();
        swap(p[val],p[i]);
        swap(w[val],w[i]);
        swap(arr[val],arr[i]);
        arr[i]=0.00;
        i++;
        cou=count(arr.begin(),arr.end(),0.00);
    }
    knapsack(p,w,n,m);
}
