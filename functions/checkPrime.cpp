#include<iostream>
using namespace std;
void checkPrime(int n){
    int count=0;
    for(int i=2; i<n; i++){
        if(n%i==0){
            count++;
        }
    }
    if(count==0){
        cout<<"Prime number";
    }
    else{
        cout<<"Not prime number";
    }
}
int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    checkPrime(n);
    return 0;
}