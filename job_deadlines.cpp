#include <algorithm>
#include <iostream>
using namespace std;

struct Job {
    int id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b){
    return (a.profit > b.profit);
}

void printJobScheduling(Job arr[], int n){
    sort(arr, arr + n, comparison);
    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
        slot[i] = false;

    int maxProfit=0;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, arr[i].dead) - 1; j >= 0; j--) {
            if (slot[j] == false) {
                result[j] = i;
                slot[j] = true;
                maxProfit +=arr[i].profit;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (slot[i])
            cout << arr[result[i]].id << " ";
    }

    cout<<endl<<"Profit: "<<maxProfit;

}

int main(){
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;
    Job arr[n];
    for (int i = 0; i < n; ++i) {
        arr[i].id = i+1;
        cout << "Enter details for job " << arr[i].id <<" (Deadline Profit)"<< ": ";
        cin >> arr[i].dead >> arr[i].profit;
    }
    cout << "Sequence of jobs: ";
    printJobScheduling(arr, n);
    return 0;
}
