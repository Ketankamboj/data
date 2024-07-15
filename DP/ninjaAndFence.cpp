#include<iostream>
#include<vector>
using namespace std;

//recursion
int solveRec(int n, int k){
    if(n == 1)
        return k;

    if(n == 2)
        return k*k;

    int ans = solveRec(n-2, k) * (k-1) + solveRec(n-1, k) * (k-1);
    return ans;
}

//memoisation
int solveMem(vector<int> &dp, int n, int k){
    if(n == 1)
        return k;

    if(n == 2)
        return k*k;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = solveMem(dp, n-2, k) * (k-1) + solveMem(dp, n-1, k) * (k-1);
    return dp[n];
}

//tabulation
int solveTab(int n, int k){
    vector<int>dp(n+1, 0);

    dp[1] = k;
    dp[2] = k*k;

    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-2] + dp[i-1]) * (k-1); 
    }

    return dp[n];
}

//space optimazation
int solveTabsp(int n, int k){
    int prev2 = k;
    int prev1 = k*k;

    for(int i=3; i<=n; i++){
        int ans = (prev2 + prev1) * (k-1);
        prev2 = prev1;
        prev1 = ans; 
    }

    return prev1;
}

int main(){
    int n,k;
    cout<<"enter number of post: ";
    cin>>n;
    cout<<"enter number of colour: ";
    cin>>k;

    int ans = solveRec(n,k);
    vector<int>dp(n+1, -1);
    return 0;
}