#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &num){
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

    vector<int> price(n);
    for(int i=0; i<n; i++){
        cin>>price[i];
    }

    if(n == 1){
        cout<<price[0];
        return 0;
    }

    vector<int> first, second;
    for(int i=0; i<n; i++){
        if(i != n-1)
            first.push_back(price[i]);
        if(i != 0)
            second.push_back(price[i]);
    }

    cout<<max(solve(first), solve(second));
    return 0;
}