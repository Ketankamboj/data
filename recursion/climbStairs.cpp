#include<iostream>
using namespace std;

int climb(int n){
    if(n==0 || n==1){
        return 1;
    }

    return climb(n-1) + climb(n-2);
}

int main(){
    int n;
    cout<<"enter the stair: ";
    cin>>n;

    int ans  = climb(n);
    cout<<"total ways are: "<<ans;
    return 0;
}