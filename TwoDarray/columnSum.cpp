#include<iostream>
using namespace std;
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

   for(i=0; i<r; i++){
        int Sum1=0;
        for(j=0; j<c; j++){
            Sum1 = Sum1 + arr[j][i];
        }
        cout<<"the sum of column "<<i+1<<" is: ";
        cout<<Sum1<<endl;
    }
    return 0;
}