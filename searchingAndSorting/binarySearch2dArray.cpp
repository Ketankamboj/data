#include<iostream>
using namespace std;
bool binarySearch(int arr[][5], int r, int c, int target){
    int s=0, e=r*c-1, mid = s+(e-s)/2;

    while(s<=e){
        int rowIdx = mid+c;
        int colIdx = mid%c;

        if(arr[rowIdx][colIdx] == target){
            return true;
        }
        else if(arr[rowIdx][colIdx] < target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return false;
}

int main(){
    int r,c,arr[5][5];
    cout<<"enter no of rows: ";
    cin>>r;
    cout<<"enter no of columns: ";
    cin>>c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"enter element at index ("<<i<<","<<j<<"): ";
            cin>>arr[i][j];
        }
    }

    int target;
    cout<<"enter target value: ";
    cin>>target;

    bool ans = binarySearch(arr,r,c,target);
    if(ans){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
    return 0;
}