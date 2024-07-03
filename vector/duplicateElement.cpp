#include<iostream>
using namespace std;
#include<vector>
int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    for(int i=0; i<arr.size(); i++){
        for(int j=i+1; j<arr.size(); j++){
            if(arr[i]==arr[j]){
                cout<<arr[i]<<" is duplicate element."<<endl;
            }
        }
    }
    return 0;
}