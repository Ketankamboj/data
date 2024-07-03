#include<iostream>
using namespace std;

class cirQueue{
    public:
    int front;
    int rear;
    int *arr;
    int size;

    cirQueue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){
        if((front == 0) && rear == size-1 && rear == front-1){
            cout<<"queue is full."<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pop(){
        if(front == -1){
            cout<<"queue is empty."<<endl;
        }
        else if(front == rear){
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
    }

    void isEmpty(){
        if(front == -1){
            cout<<"queue is empty."<<endl;
        }
        else{
            cout<<"queue is not empty."<<endl;
        }
    }
};

int main(){
    cirQueue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    return 0;
}