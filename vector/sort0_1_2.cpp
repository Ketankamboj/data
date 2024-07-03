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

    int l=0, m=0, h=arr.size()-1;
    while(m<=h){
        if(arr[m]==0){
            int t = arr[l];
            arr[l] = arr[m];
            arr[m] = t;
            l++;
            m++;
        }
        else if(arr[m]==1){
            m++;
        }
        else{
            int t = arr[m];
            arr[m] = arr[h];
            arr[h] = t;
            h--;
        }
    }

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}