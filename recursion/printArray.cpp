#include<iostream>
using namespace std;

void printing(int arr[], int i, int n){
    if(i>=n){
        return;
    }

    cout<<arr[i]<<" ";

    printing(arr, i+1, n);
}
int main(){
    int arr[10],n,k=0;
    cout<<"enter size of array: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    printing(arr,k,n);
    return 0;
}