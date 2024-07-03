#include<iostream>
using namespace std;

class queue{
    public:
    
    int front;
    int rear;
    int *arr;
    int size;

    queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data){
        if(rear == size){
            cout<<"queue is full."<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    void pop(){
        if(front == rear){
            cout<<"queue is empty."<<endl;
        }
        else{
            front++;

            if(front == rear){
                front=0;
                rear=0;
            }
        }
    }

    void isEmpty(){
        if(front == rear){
            cout<<"queue is empty."<<endl;
        }
        else{
            cout<<"queue is not empty."<<endl;
        }
    }

    void getFront(){
        if(front == rear){
            cout<<"queue is empty."<<endl;
        }
        else{
            cout<<"front element of queue is: "<<arr[front]<<endl;
        }
    }

    void getSize(){
            int s = rear-front;
            cout<<"size of queue is: "<<s<<endl;
    }
};

int main(){
    queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    return 0;
}