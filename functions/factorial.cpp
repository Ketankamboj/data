#include<iostream>
using namespace std;
int fact(int n){
    int f=1;
    for(int i=0; i<=n; i++){
        f=f*i;
    }
    return f;
}
int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    int factorial = fact(n);
    cout<<"the factorial of number is: "<<factorial;
    return 0;
}