#include<iostream>
#include<limits.h>
using namespace std;
int main(){
    int size, arr[5], max=INT_MIN;
    cout<<"enter size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"input element at index "<<i<<" : ";
        cin>>arr[i];
    }

    for(int i=0; i<size; i++){
        if(max<arr[i])
        max=arr[i];
    }
    cout<<"the maximum number in array is: "<<max;
    return 0;
}