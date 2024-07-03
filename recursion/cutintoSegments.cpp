#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int solve(int n, int x, int y, int z){
    if(n == 0)
    return 0;

    if(n < 0)
    return INT_MIN;

    int a = solve(n-x, x,y, z) + 1;

    int b = solve(n-y, x, y, z) + 1;

    int c = solve(n-z, x, y, z) + 1;

    int ans = max(a , max(b,c));
    return ans;
}

int main(){
    int n,x,y,z;

    cout<<"enter size of rod: ";
    cin>>n;

    cout<<"enter first length: ";
    cin>>x;

    cout<<"enter second length: ";
    cin>>y;

    cout<<"enter third length: ";
    cin>>z;

    int ans = solve(n,x,y,z);

    if(ans < 0)
    ans=0;
    
    cout<<"maximum elements required are: "<<ans;
    return 0;
}