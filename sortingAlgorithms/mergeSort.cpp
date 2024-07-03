#include<iostream>
using namespace std;

void mergefn(int* arr, int s, int e){
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int* left = new int[len1];
    int* right = new int[len2];

    //copy value
    int k=s;
    for(int i=0; i<len1; i++){
        left[i] = arr[k];
        k++;
    }

    k=mid+1;
    for(int i=0; i<len2; i++){
        right[i] = arr[k];
        k++;
    }
    
    //merge both array
    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while(leftIndex<len1 && rightIndex<len2){
        if(left[leftIndex] < right[rightIndex]){
            arr[mainArrayIndex] = left[leftIndex];
            leftIndex++;
        }
        else{
            arr[mainArrayIndex] = right[rightIndex];
            rightIndex++;
        }
        mainArrayIndex++;
    }

    //copy for left
    while(leftIndex<len1){
        arr[mainArrayIndex++] = left[leftIndex++];
    }

    //copy for right
    while(rightIndex<len2){
        arr[mainArrayIndex++] = right[rightIndex++];
    }
}

void merge(int* arr, int s, int e){
    //base case
    //s==e -> single element
    //s>=e -> invalid array
    if(s>=e)
    return;

    int mid = s + (e-s)/2;

    //left part sorting
    merge(arr,s,mid);

    //right par sorting
    merge(arr,mid+1,e);

    //now merge two sorted array
    mergefn(arr,s,e);
}

int main(){
    int n,arr[10];
    cout<<"enter size of array: ";
    cin>>n;

    for(int i=0; i<n; i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    int s=0,e=n-1;
    merge(arr,s,e);

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}