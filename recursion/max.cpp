#include<iostream>
#include<limits.h>
using namespace std;

void max(int arr[], int i, int n, int& maxi){
    if(i>=n){
        return;
    }

    if(maxi<arr[i]){
        maxi = arr[i];
    }

    max(arr, i+1, n, maxi);
}
int main(){
    int arr[10],n,k=0;
    cout<<"enter size of array: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int maxi = INT_MIN;

    max(arr,k,n,maxi);

    cout<<"the maximum element is : "<<maxi;
    return 0;
}