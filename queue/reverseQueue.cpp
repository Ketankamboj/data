#include<iostream>
#include<queue>
#include<stack>
using namespace std;

//recursive approach
void reverse(queue<int>& q){
    if(q.empty()){
        return;
    }

    int t = q.front();
    q.pop();

    reverse(q);

    q.push(t);
}

//stack approach
void reverse(queue<int>& q){
    stack<int> s;

    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main(){
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverse(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}