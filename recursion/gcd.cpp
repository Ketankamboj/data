#include<iostream>
using namespace std;

int hcf(int a, int b){
    if(a==0)
    return b;
    if(b==0)
    return a;

    if(a>b)
    return hcf(a-b,b); 
    else
    return hcf(b-a,a);
}

int lcm(int a, int b){
    return (a*b)/hcf(a,b);
}

int main(){
    int a, b;
    cout<<"enter first value: ";
    cin>>a;
    cout<<"enter second value: ";
    cin>>b;

    int ans = hcf(a,b);
    int ans1 = lcm(a,b);

    cout<<"tne hcf of two numbers are: "<<ans<<endl;
    cout<<"tne lcm of two numbers are: "<<ans1;
    return 0;
}