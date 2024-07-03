#include<iostream>
using namespace std;

int getSum(int n){
    int sum=0;
    for(int i=2; i<=n; i=i+2){
        sum=sum+i;
    }
    return sum;
}

int main(){
    int n;
    cout<<"enter the number: ";
    cin>>n;
    int sum = getSum(n);
    cout<<"sum of even numbers is: "<<sum;
    return 0;
}