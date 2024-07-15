#include<iostream>
#include<vector>
using namespace std;

//recursion
int solveRec(vector<int> &value, vector<int> &weight, int index, int w){
    if(index == 0){
        if(weight[0] <= w) return value[0];
        else return 0;
    }

    int include;
    if(weight[index] <= w)
        include = value[index] + solveRec(value, weight, index-1, w-weight[index]);

    int exclude = solveRec(value, weight, index-1, w);

    int ans = max(include, exclude);
    return ans;
}

//memoisation
int solveMem(vector<vector<int> > &dp, vector<int> &value, vector<int> &weight, int index, int w){
    if(index == 0){
        if(weight[0] <= w) return value[0];
        else return 0;
    }

    if(dp[index][w] != -1)
        return dp[index][w];

    int include;
    if(weight[index] <= w)
        include = value[index] + solveMem(dp,value, weight, index-1, w-weight[index]);

    int exclude = solveMem(dp, value, weight, index-1, w);

    dp[index][w] = max(include, exclude);
    return dp[index][w];
}

//tabulation
int solveTab(vector<int> &value, vector<int> &weight, int index, int w){
    vector<vector<int> > dp(index+1 , vector<int>(w+1, 0));

    for(int i = weight[0]; i<=w; i++){
        if(weight[0] <= w) dp[0][w] = value[0];
        else dp[0][w] = 0;
    }

    for(int i=1; i<index; i++){
        for(int j=0; j<=w; j++){
            int include;
            if(weight[i] <= j)
                include = value[i] + dp[i-1][j-weight[i]];

            int exclude = dp[i-1][j];

            dp[i][j] = max(include, exclude);
        }
    }
    
    return dp[index-1][w];
}

int main(){
    int n,w;
    cout<<"enter value of n: ";
    cin>>n;
    cout<<"enter max weight: ";
    cin>>w;

    vector<int>value;
    vector<int>weight;

    int ans = solveRec(value, weight, n-1, w);

    vector<vector<int> > dp(n, vector<int>(w+1, -1));
    return 0;
}