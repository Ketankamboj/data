#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int>& q, int k){
    int n=q.size();
    if(k==0 || k>n)
        return;
    
    stack<int> s;

    int count=0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k)
            break;
    }

    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    count=0;
    while(!q.empty() && n-k !=0){
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n-k)
            break;
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    int k;
    cout<<"enter times to reverse: ";
    cin>>k;

    reverse(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}