// 1
// 1 2
// 1   3
// 1     4
// 1 2 3 4 5

#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            if(j==0 || i==n-1 || i==j){
                cout<<j+1<<" ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
    return 0;
}