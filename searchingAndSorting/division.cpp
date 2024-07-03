#include<iostream>
#include<vector>
using namespace std;
int divi(int dividend, int divisor){
    int s=0,e=dividend, mid=s+(e-s)/2, ans=0;

    while(s<=e){
        if(abs(mid*divisor) == abs(dividend)){
            ans = mid;
            break;
        }
        else if(abs(mid*divisor) < abs(dividend)){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid= s+(e-s)/2;
    }
    if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
        return ans;
    }
    else{
        return -ans;
    }
}
int main(){
    int dividend;
    cout<<"enter dividend: ";
    cin>>dividend;

    int divisor;
    cout<<"enter divisor: ";
    cin>>divisor;

    int res = divi(dividend,divisor);

    int precision;
    cout<<"input how many digits you want after decimal: ";
    cin>>precision;

    double step = 0.1;
    double finalAns = res;

    for(int i=0; i<precision; i++){
        for(double j=finalAns; j*divisor<=dividend; j=j+step){
            finalAns=j;
        }
        step/=10;
    }

    cout<<"quotient of the number is: "<<finalAns;
    return 0;
}