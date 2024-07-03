#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int start=0,end=arr.size()-1,i=0;
    while(i!=end){
        if(arr[i]<0){
            int t = arr[i];
            arr[i] = arr[start];
            arr[start] = arr[i];
            i++;
            start++;
        }
        else{
            int t = arr[i];
            arr[i] = arr[end];
            arr[end] = t;
            end--;
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}