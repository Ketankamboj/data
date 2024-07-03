#include<iostream>
#include<queue>
using namespace std;
int main(){
    //max heap created
    priority_queue<int> pq;

    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);
    
    cout<<"top element: "<<pq.top()<<endl;
    pq.pop();

    cout<<"top element: "<<pq.top()<<endl;

    cout<<"size: "<<pq.size()<<endl;

    if(pq.empty()){
        cout<<"max heap is empty."<<endl;
    }
    else{
        cout<<"max heap is empty."<<endl;
    }

    //min heap

    priority_queue<int, vector<int>, greater<int> > p;

    p.push(3);
    p.push(6);
    p.push(9);
    p.push(4);
    p.push(8);

    cout<<"top element: "<<p.top()<<endl;
    p.pop();

    cout<<"top element: "<<p.top()<<endl;

    cout<<"size: "<<p.size()<<endl;
    return 0;
}