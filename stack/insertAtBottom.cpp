#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int>& s, int target){
    if(s.size() == 0){
        s.push(target);
        return;
    }

    int temp = s.top();
    s.pop();
    insertBottom(s,target);
    s.push(temp);
}

int main(){
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);

    if(s.empty()){
        cout<<"stack is empty."<<endl;
        return 0;
    }

    int target = s.top();
    s.pop();

    insertBottom(s,target);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}