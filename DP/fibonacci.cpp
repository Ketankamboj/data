#include<iostream>
#include<vector>
using namespace std;

//top down
int fibo(int n, vector<int> &dp){
    if(n==0 || n==1)
        return n;

    if(dp[n] !=  -1)
        return dp[n];

    dp[n] = fibo(n-1, dp) + fibo(n-2, dp);
    return dp[n];
}

//bottom up
int fiboBottom(int n, vector<int> &dp){
    dp[0] = 0;
    dp[1] = 1;

    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

//space optimized in bottom up
void fiboOptimized(int n, int prev2, int prev1){
    if(n==0){
        cout<<n;
        return;
    }

    for(int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout<<prev1;
}

int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;

    vector<int>dp(n+1);
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }

    int ans = fibo(n, dp);
    fiboOptimized(n, 0, 1);
    cout<<ans<<endl;
    return 0;
}