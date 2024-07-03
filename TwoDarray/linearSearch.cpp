#include<iostream>
using namespace std;
int main(){
    int r,c,arr[5][5],i,j,key;
    cout<<"enter no of rows:";
    cin>>r;
    cout<<"enter no of columns:";
    cin>>c;

    cout<<"enter element to find:";
    cin>>key;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"enter element at index ("<<i<<","<<j<<"): ";
            cin>>arr[i][j];
        }
    }

   for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(arr[i][j] == key){
                cout<<key<<" is present.";
                break;
            }
        }
    }
    return 0;
}