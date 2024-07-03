#include<iostream>
#include<vector>
using namespace std;

int binary(vector<int> arr, int target){
    int start=0,end=arr.size()-1;
    int mid = start + (end-start)/2;

    while(start<=end){
        if(arr[mid] == target){
            return arr[mid];
        }
        else if(target>arr[mid]){
            start = mid+1;
        }
        else{
            end = mid -1;
        }
        mid = start + (end-start)/2;
    }
    return -1;
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

    int targetIndex = binary(arr,target);

    if(targetIndex == -1){
        cout<<"target not found."<<endl;
    }
    else{
        cout<<targetIndex<<endl;
    }
    return 0;
}