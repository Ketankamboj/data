#include<iostream>
using namespace std;
int reverse(int n){
    int num=0,a;
    while(n!=0){
        a=n%10;
        num=num*10+a;
        n=n/10;
    }
    return num;
}
int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    int rev = reverse(n);
    cout<<"the reverse of number is: "<<rev;
    return 0;
}