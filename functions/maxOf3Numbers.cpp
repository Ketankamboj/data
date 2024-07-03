#include<iostream>
using namespace std;

int findMax(int a, int b, int c){
    if(a>b && a>c){
        return a;
    }
    else if(b>a && b>c){
        return b;
    }
    else{
        return c;
    }
}

int main(){
    int a,b,c;
    cout<<"enter value of a: ";
    cin>>a;

    cout<<"enter value of b: ";
    cin>>b;

    cout<<"enter value of c: ";
    cin>>c;

    int max = findMax(a,b,c);
    cout<<"max of three numbers is: "<<max;
    return 0;
}