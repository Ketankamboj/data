#include<iostream>
using namespace std;
int main(){
    int r,c;
    cout<<"enter number of row: ";
    cin>>r;
    cout<<"enter number of column: ";
    cin>>c;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i==0 || i==r-1 || j==0 || j==c-1){
            cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}