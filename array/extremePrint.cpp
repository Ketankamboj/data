#include<iostream>
using namespace std;
int main(){
    int size, arr[5];
    cout<<"enter size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"input element at index "<<i<<" : ";
        cin>>arr[i];
    }

    int i=0, j=size-1;
    while(i<j){
        if(i==j)
        cout<<arr[i]<<" ";

        else{
            cout<<arr[i]<<" ";
            cout<<arr[j]<<" ";
        }
        i++;
        j--;
    }
    return 0;
}