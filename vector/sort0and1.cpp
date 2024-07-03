#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array:";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int start=0;
    int end=arr.size() - 1;
    int i=0;
    while(i!=end){
        if(arr[i]==0){
            int t = arr[start];
            arr[start] = arr[i];
            arr[i] = t;
            start++;
            i++;
        }

        if(arr[i]==1){
            int t = arr[end];
            arr[end] = arr[i];
            arr[i] = t;
            end--;
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}