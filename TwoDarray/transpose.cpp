#include<iostream>
using namespace std;

void transpose(int arr[][5], int r, int c, int trans[][5]){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
           trans[i][j] = arr[j][i];
        }
    }
}

int main(){
    int r,c,arr[5][5],trans[5][5];
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

    transpose(arr, r, c, trans);

     for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
           cout<<trans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}