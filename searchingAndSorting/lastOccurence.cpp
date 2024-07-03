#include<iostream>
#include<vector>
using namespace std;

int first(vector<int> arr, int target){
    int start=0, end=arr.size()-1,ans=-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid] == target){
            ans=mid;
            start=mid+1;
        }
        else if(target>arr[mid]){
            start=mid+1;
        }
        else if(target<arr[mid]){
            end=mid-1;
        }
        mid = start + (end-start)/2;
    }
    return ans;
}

int main(){
    int n,target;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"input element at index "<<i<<": ";
        cin>>arr[i];
    }

    cout<<"enter target value: ";
    cin>>target;

    int targetIndex = first(arr,target);

    if(targetIndex == -1){
        cout<<"target element not found."<<endl;
    }
    else{
        cout<<"last occurrence of element at index: "<<targetIndex<<endl;
    }
    return 0;
}