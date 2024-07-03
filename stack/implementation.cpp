#include<iostream>
using namespace std;

class stack{
    public:
    
    int* arr;
    int size;
    int top;

    stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data){
        if(size-top > 1){
            top++;
            arr[top] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top < 0){
            cout<<"Stack Underflow"<<endl;
        }
        else{
            top--;
        }
    }

    int getTop(){
        if(top < 0){
            cout<<"No element in stack"<<endl;
        }
        return arr[top];
    }

    int getSize(){
            return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    //printing stack
    while(!s.isEmpty()){
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;

    cout<<"size of stack is: "<<s.getSize()<<endl;
    cout<<"top of stack is: "<<s.getTop()<<endl;
    return 0;
}