#include<iostream>
#include<cmath>
using namespace std;

int dToB(int n){
    int binary=0,i=0;
    while(n!=0){
        int bit = n%2;
        binary = bit*pow(10, i++) + binary;
        n=n/2;
    }

    return binary;
}


int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    int num = dToB(n);
    cout<<"number in binary is: "<<num;
    return 0;
}