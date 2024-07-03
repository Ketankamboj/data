#include<iostream>
using namespace std;

class stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;

    stack(int size){
        arr = new int[size];
        this->size = size;
        int top1 = -1;
        int top2 = size;
    }

    void push1(int data){
        if(top2-top1 == 1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1] = data;
        }
    }

    void push2(int data){
        if(top2-top1 == 1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top2--;
            arr[top2] = data;
        }
    }

    void pop1(){
        if(top1 == -1){
            cout<<"stack underflow in stack1"<<endl;
        }
        else{
            top1--;
        }
    }

    void pop2(){
        if(top2 == size){
            cout<<"stack underflow in stack2"<<endl;
        }
        else{
            top2++;
        }
    }
};

int main(){
    stack s(6);

    s.push1(1);
    s.push1(2);
    s.push2(3);
    return 0;
}