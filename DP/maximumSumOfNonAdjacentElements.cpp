#include<iostream>
#include<vector>
using namespace std;
//recursion
int solveRec(vector<int> &num, int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return num[0];

    int incl = solveRec(num, n-2) + num[n];
    int excl = solveRec(num, n-1);

    return max(incl, excl);
}

//memoization
int solveMem(vector<int> &num, vector<int> &dp, int n){
    if(n < 0)
        return 0;
    if(n == 0)
        return num[0];

    if(dp[n] != -1)
        return dp[n];

    int incl = solveMem(num,dp, n-2) + num[n];
    int excl = solveMem(num,dp, n-1);

    dp[n] = max(incl, excl);

    return dp[n];
}

//tabulation
int solveTab(vector<int> &num){
    int n = num.size();
    vector<int>dp(n, 0);

    dp[0] = num[0];

    for(int i=1; i<n; i++){
        int inc  = dp[i-2] + num[i];
        int exc = dp[i-1] + 0;
        dp[i] = max(inc, exc);
    }

    return dp[n-1];
}

//space optimization in tabulation
int solveTabSp(vector<int> &num){
    int n = num.size();
    int prev2 = 0;
    int prev1 = num[0];

    for(int i=1; i<n; i++){
        int inc  = prev2 + num[i];
        int exc = prev1 + 0;
        int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }

    return prev1;
}

int main(){
    int n;
    cout<<"enter size of array: ";
    cin>>n;

    vector<int>num(n);
    for(int i=0; i<n; i++){
        cin>>num[i];
    }

    int ans = solveRec(num, n - 1);
    cout<<ans<<endl;

    vector<int>dp(n, -1);
    int ans1 = solveMem(num, dp, n-1);

    int ans2 = solveTab(num);
    return 0;
}