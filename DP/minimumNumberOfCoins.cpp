#include<iostream>
#include<vector>
#include<limits>
using namespace std;

//normal recursion
int solveRec(vector<int>&coins, int target){
    //base case
    if(target == 0)
        return 0;

    if(target < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = solveRec(coins, target-coins[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    return mini;
}

//memoization
int solveMem(vector<int>&coins, int target, vector<int> &dp){
    //base case
    if(target == 0)
        return 0;

    if(target < 0)
        return INT_MAX;

    if(dp[target] != -1)
        return dp[target];

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++){
        int ans = solveRec(coins, target-coins[i]);
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }

    dp[target] = mini;

    return mini;
}

//tabulation
int solveTab(vector<int>&coins, int target){
    vector<int>dp(target+1, INT_MAX);

    dp[0] = 0;

    for(int i=1; i<=target; i++){
        for(int j=0; j<coins.size(); j++){
            if(i - coins[j] >= 0 && dp[i- coins[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i- coins[j]]);
        }
    }

    if(dp[target] == INT_MAX)
        return -1;
    else
        return dp[target];
}

int main(){
    int n;
    cout<<"enter number of elements: ";
    cin>>n;

    vector<int> coins(n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }

    int target;
    cout<<"enter target: ";
    cin>>target;

    // recursive
    int ans = solveRec(coins, target);
    if(ans == INT_MAX)
        cout<<-1;
    else
        cout<<ans;

    //memoization
    vector<int>dp(target+1, -1);
    int ans1 = solveMem(coins, target, dp);
    if(ans1  == INT_MAX)
        cout<<-1;
    else
        cout<<ans1;

    //tabulation
    cout<<solveTab(coins, target);
    return 0;
}