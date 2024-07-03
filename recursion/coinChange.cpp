#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int solve(vector<int>& arr, int target){
    if(target == 0)
    return 0;

    if(target<0)
    return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<arr.size(); i++){
        int ans = solve(arr, target-arr[i]);
        if(ans != INT_MAX)
        mini = min(mini, ans+1);
    }

    return mini;
}

int main(){
    int n,target;
    
    cout<<"enter value of n: ";
    cin>>n;
    vector<int> arr(n);

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }
    cout<<"enter target: ";
    cin>>target;

    int ans = solve(arr,target);
    cout<<"minimum elements required are: "<<ans;
    return 0;
}