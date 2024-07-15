#include<iostream>
#include<limits>
#include<vector>
using namespace std;

//recursion
int solve(int len, int x, int y, int z){
    if(len == 0)
        return 0;

    if(len < 0)
        return INT_MIN;

    int a = solve(len-x, x,y,z) + 1;
    int b = solve(len-y, x,y,z) + 1;
    int c = solve(len-z, x,y,z) + 1;

    return max(a, max(b,c));
}

//memoization
int solveMem(int len, int x, int y, int z, vector<int> &dp){
    if(len == 0)
        return 0;

    if(len < 0)
        return INT_MIN;

    if(dp[len] != -1)
        return dp[len];

    int a = solveMem(len-x, x,y,z,dp) + 1;
    int b = solveMem(len-y, x,y,z,dp) + 1;
    int c = solveMem(len-z, x,y,z,dp) + 1;

    dp[len] = max(a, max(b,c));
    return dp[len];
}

//tabulation
int solve(int len, int x, int y, int z){
    vector<int> dp(len+1, INT_MIN);
    dp[0] = 0;

    for(int i=1; i<=len; i++){
        if(i-x >= 0)
            dp[i] = max(dp[i], dp[i-x] + 1);
        if(i-y >= 0)
            dp[i] = max(dp[i], dp[i-y] + 1);
        if(i-z >= 0)
            dp[i] = max(dp[i], dp[i-z] + 1);
    }
    if(dp[len] < 0)
        return 0;
    else 
        return dp[len];
}

int main(){
    int len, p1, p2, p3;
    cout<<"enter length of rod: ";
    cin>>len;
    cout<<"enter part1: ";
    cin>>p1;
    cout<<"enter part2: ";
    cin>>p2;
    cout<<"enter part3: ";
    cin>>p3;

    int ans = solve(len, p1, p2, p3);

    vector<int>dp(len+1, -1);
    int ans2 = solveMem(len, p1, p2, p3, dp);

    if(ans < 0)
        cout<<0;
    else
        cout<<ans;
    return 0;
}