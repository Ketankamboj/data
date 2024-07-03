#include<iostream>
using namespace std;

int partition(int* arr, int s, int e){
    //choose pivot element
    int pivotIndex = s;
    int pivotElement = arr[s];

    //find right position for pivot element
    int count = 0;
    for(int i=s+1; i<=e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }
    
    int rightIndex = s+count;
    swap(arr[pivotIndex],arr[rightIndex]);
    pivotIndex = rightIndex;

    // left me chothe aur right me bade
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i] <= pivotElement){
            i++;
        }
        while(arr[j]>pivotElement){
            j--;
        }

        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i],arr[j]);
        }
    }
    return pivotIndex;
}

void quick(int* arr , int s, int e){
    //base case
    if(s>=e)
    return;

    //partition logic
    int p = partition(arr,s,e);

    //recursive calls
    //pivot element left
    quick(arr,s,p-1);
    //pivot element right
    quick(arr,p+1,e);
}
int main(){
    int n,arr[10];
    cout<<"enter size of array: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int s=0, e=n-1;
    quick(arr,s,e);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}