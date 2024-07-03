#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void solve(vector<int>& v, int n, int k){
    queue<int>q;

    //process first window of size k
    for(int i=0; i<k; i++){
        if(v[i] < 0){
            q.push(i);
        }
    }

    //remaining window ko process kro
    for(int i=k; i<n; i++){
        // answer dedo purani window kaa
        if(q.empty()){
            cout<<0<<" ";
        }
        else{
            cout<<v[q.front()]<<" ";
        }

        //out of window elements ko remove kro
        while(!q.empty() && i-q.front() >= k){
            q.pop();
        }

        //check current element for insertion
        if(v[i] < 0){
            q.push(i);
        }
    }

    //answer for last window
    if(q.empty()){
        cout<<0<<" ";
    }
    else{
        cout<<v[q.front()]<<" ";
    }
}

int main(){
    vector<int>v;
    v.push_back(12);
    v.push_back(-1);
    v.push_back(-7);
    v.push_back(8);
    v.push_back(-15);
    v.push_back(30);
    v.push_back(16);
    v.push_back(28);

    int size = v.size();
    int k=3;

    solve(v,size,k);
    return 0;
}