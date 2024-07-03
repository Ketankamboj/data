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
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }

    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}