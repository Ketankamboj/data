#include<iostream>
using namespace std;
int main(){
    int r,c,arr[4][4];
    cout<<"enter number of rows: ";
    cin>>r;
    cout<<"enter number of columns: ";
    cin>>c;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"enter element at index ("<<i<<","<<j<<"): ";
            cin>>arr[i][j];
        }
    }

    int toprow=0,bottomrow=r-1, leftcol=0, rightcol=c-1, totalelements=0;
    while(totalelements < r*c){
        for(int j=leftcol; j<=rightcol; j++){
            cout<<arr[toprow][j]<<" ";
            totalelements++;
        }
        toprow++;
        for(int j=toprow; j<=bottomrow; j++){
            cout<<arr[j][rightcol]<<" ";
            totalelements++;
        }
        rightcol--;
        for(int j=rightcol; j>=leftcol; j--){
            cout<<arr[bottomrow][j]<<" ";
            totalelements++;
        }
        bottomrow--;
        for(int j=bottomrow; j>=toprow; j--){
            cout<<arr[j][leftcol]<<" ";
            totalelements++;
        }
        leftcol++;
    }
    return 0;
}