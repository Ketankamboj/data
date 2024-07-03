#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int>& q){
    int n = q.size();
    if(n==0)
        return;
    
    int k = n/2;
    queue<int>q1;

    int count=0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        q1.push(temp);
        count++;

        if(count == k)
            break;
    }

    while(!q.empty() && !q1.empty()){
        int first = q1.front();
        q1.pop();
        q.push(first);
    
        int second = q.front();
        q.pop();
        q.push(second);
    }

    if(n&1){
        int element = q.front();
        q.pop();
        q.push(element);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);

    interleave(q);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}