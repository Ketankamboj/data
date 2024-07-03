#include<iostream>
using namespace std;

bool check(int arr[], int i, int n){
    if(i>=n){
        return true;
    }

    if(arr[i]>arr[i+1]){
        return false;
    }

    return check(arr, i+1, n);
}
int main(){
    int arr[10],n,k=0;
    cout<<"enter size of array: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    bool ans = check(arr,k,n);

    if(ans){
        cout<<"sorted";
    }
    else{
        cout<<"not sorted";
    }
    return 0;
}