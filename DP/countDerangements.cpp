#include<iostream>
#include<vector>
using namespace std;

//noremal recursion
int solveRec(int n){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    int ans = (n-1) * (solveRec(n-1) + solveRec(n-2));
    return ans;
}

//memoization
int solveMem(int n, vector<int> &dp){
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;

    if(dp[n] != -2)
        return dp[n];

    dp[n] = (n-1) * (solveMem(n-1 , dp) + solveMem(n-2, dp));

    return dp[n];
}

//tabulation
int solveTab(int n){
    vector<int>dp(n+1,0);

    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++){
        int first = dp[i-1];
        int second = dp[i-2];

        int ans = (i-1) * (first + second);
        dp[i] = ans;
    }

    return dp[n];
}

//space optimization
int solveTabsp(int n){

    int prev2 = 0;
    int prev1 = 1;

    for(int i=3; i<=n; i++){
        int first = prev1;
        int second = prev2;

        int ans = (i-1) * (first + second);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;

    int ans = solveRec(n);

    vector<int>dp(n+1, -1);
    int ans1 = solveMem(n, dp);

    return 0;
}