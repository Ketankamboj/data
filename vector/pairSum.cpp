#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,num;
    cout<<"enter size of array: ";
    cin>>n;

    cout<<"enter number you want to check: ";
    cin>>num;
    vector<int> arr(n);

    for(int i=0; i<arr.size(); i++){
        cout<<"input the element at index "<<i<<": ";
        cin>>arr[i];
    }

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]+arr[j]==num){
                cout<<"elements are "<<arr[i]<<","<<arr[j]<<endl;
            }
        }
    }
    return 0;
}