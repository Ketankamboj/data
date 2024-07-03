#include<iostream>
using namespace std;
int main(){
    int size, arr[5], count0=0, count1=0;
    cout<<"enter size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"input element at index "<<i<<" : ";
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        if(arr[i]==0)
        count0++;
        if(arr[i]==1)
        count1++;
    }
    cout<<"the count of 0 is: "<<count0<<endl;
    cout<<"the count of 1 is: "<<count1;
    return 0;
}