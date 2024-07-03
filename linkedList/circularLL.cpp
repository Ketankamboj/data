#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertNode(Node* &tail, int element, int value){
    if(tail == NULL){
        Node* temp = new Node(value);
        tail = temp;
        temp->next = temp;
    }
    else{
        Node* curr = tail;
        while(curr->data != element){
            curr = curr->next;
        }

        Node* temp = new Node(value);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int value){
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }
    else{
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev = curr;
            curr = curr->next;
        }

        //1 node present
        if(curr == prev){
            tail = NULL;
        }

        //>=2 node present
        else if(tail == curr){
            tail = prev;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node* tail){
    if(tail == NULL){
        cout<<"List is empty";
        return;
    }

    Node* temp = tail;
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);
    cout<<endl;
}

int main(){
    Node* tail = NULL;

    insertNode(tail,5,3);
    insertNode(tail,3,5);
    insertNode(tail,5,7);
    insertNode(tail,5,6);
    deleteNode(tail,7);
    
    print(tail);
    return 0;
}