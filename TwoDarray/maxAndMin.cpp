#include<iostream>
#include<limits>
using namespace std;

int getMax(int arr[][5], int r, int c){
    int max = INT_MIN;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(max<arr[i][j]){
                max = arr[i][j];
            }
        }
    }
    return max;
}

int getMin(int arr[][5], int r, int c){
    int min = INT_MAX;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(min>arr[i][j]){
                min = arr[i][j];
            }
        }
    }
    return min;
}


int main(){
    int r,c,arr[5][5],i,j;
    cout<<"enter no of rows:";
    cin>>r;
    cout<<"enter no of columns:";
    cin>>c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"enter element at index ("<<i<<","<<j<<"): ";
            cin>>arr[i][j];
        }
    }

    cout<<"maximum element is: "<<getMax(arr,r,c)<<endl;
    cout<<"minimum element is: "<<getMin(arr,r,c);
    return 0;
}