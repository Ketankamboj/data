#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    for(int i=0; i<n-1; i++){
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}