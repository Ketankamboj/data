#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,count=0;
    cout<<"enter value of n: ";
    cin>>n;

    if(n==0){
        cout<<"total numbers of primes are: 0";
    }
    else{
        vector<bool> check(n,true);
        check[0]=check[1]=false;
    
        for(int i=2; i<n; i++){
            if(check[i]){
                count++;
    
                int j=2*i;
                while(j<n){
                    check[j] = false;
                    j+=i;
                }
            }
        }
    
        cout<<"total numbers of primes are: "<<count;
    }
    return 0;
}