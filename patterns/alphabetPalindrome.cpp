#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<i+1; j++){
            int ans = j+1+64;
            char ch = ans;
            cout<<ch<<" ";
        }
        for(int j=i; j>=1; j--){
            int ans = j+64;
            char ch = ans;
            cout<<ch<<" ";
        }
        cout<<endl;
    } 
    return 0;
}