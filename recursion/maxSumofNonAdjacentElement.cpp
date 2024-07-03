#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void solve(vector<int>& arr, int sum, int maxi, int i){
    if(i>=arr.size()){
        maxi = max(sum,maxi);
        return;
    }

    // include
    solve(arr, sum+arr[i], maxi, i+2);

    //exclude
    solve(arr, sum+arr[i], maxi, i+1);
}

int main(){
    int n,sum=0,maxi=INT_MIN,k=0;

    cout<<"enter value of n: ";
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    solve(arr,sum,maxi,k);

    cout<<"sum of maximum elements are: "<<maxi;
    return 0;
}