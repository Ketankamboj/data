#include<iostream>
#include<vector>
using namespace std;

int missing(vector<int> arr){
    int s=0, e=arr.size()-1, mid=s+(e-s)/2;

    while(s<=e){
        if(arr[mid] != mid+1){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    
    return s+1;
}

int main(){
    int n;
    cout<<"enter number of  element in array: ";
    cin>>n;

    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int mis = missing(arr);
    cout<<"missing element is: "<<mis;
    return 0;
}