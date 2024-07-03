#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<long long int> arr, long long t, long long mid){
    long long int wood =0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i]>mid){
            wood += arr[i]-mid;
        }
    }
    return wood>=t;
}

long long int maxSaw(vector<long long int> arr,long long int t){
    long long int start=0,end=*max_element(arr.begin(),arr.end()),ans=-1;

    while(start<=end){
        long long int mid = start +(end-start)/2;
        if(isPossible(arr,t,mid)){
            ans=mid;
            start = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    long long int t,n;

    cout<<"enter size of array: ";
    cin>>n;
    
    cout<<"enter height of tree you want: ";
    cin>>t;

    vector<long long int>arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    long long int ans = maxSaw(arr,t);
    cout<<"Height of saw blade will be"<<ans;
    return 0;
}