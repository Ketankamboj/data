#include<iostream>
#include<vector>
using namespace std;

int bs(vector<int>arr, int start, int end, int x){
    int mid=start+(end-start)/2;
    while(start<=end){
        if(arr[mid] == x){
            return mid;
        }
        else if(arr[mid]<x){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid = start+(end-start)/2;
    }
    return -1;
}

int expSearch(vector<int>arr, int x, int n){
    if(arr[0] == x) return 0;
    int i=1;
    while(i<n && arr[i]<=x){
        i=i*2;
    }
    return bs(arr,i/2, min(i,n-1),x);
}

int main(){
    int n,x;

    cout<<"enter size of array: ";
    cin>>n;

    vector<int>arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    cout<<"enter target value: ";
    cin>>x;

    int ans = expSearch(arr,x,n);
    if(ans == -1){
        cout<<"target not found";
    }
    else{
        cout<<"target at index "<<ans;
    }
    return 0;
}