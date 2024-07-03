#include<iostream>
#include<cmath>
using namespace std;

int bToD(int n){
    int decimal =0,i=0;
    while(n!=0){
        int bit = n%10;
        decimal = decimal+ bit*pow(2, i++);
        n=n/10;
    }
    return decimal;
}


int main(){
    int n;
    cout<<"enter any decimal number: ";
    cin>>n;
    int num = bToD(n);
    cout<<"number in decimal is: "<<num;
    return 0;
}