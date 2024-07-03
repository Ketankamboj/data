#include<iostream>
using namespace std;

bool find(int arr[],int size, int key){
    for(int i=0; i<size; i++){
        if(key == arr[i]){
        return true;
        }
    }
    return false;
}
int main(){
    int size, arr[5], key;
    cout<<"enter size of array: ";
    cin>>size;

    for(int i=0; i<size; i++){
        cout<<"input element at index "<<i<<" : ";
        cin>>arr[i];
    }

    cout<<"enter the element to be searched: ";
    cin>>key;

    if(find(arr,size,key)){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}