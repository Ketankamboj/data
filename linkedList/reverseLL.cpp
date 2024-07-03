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
};

void reverse(Node* &head){

    if(head == NULL || head->next == NULL){
        cout<<head<<endl;
        return;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next; 
    }
    cout<<endl;
}

int main(){
    Node* a = new Node(3);
    Node* b = new Node(6);
    Node* c = new Node(9);
    a->next = b;
    b->next = c;
    Node* head = a;
    print(head);
    reverse(head);
    print(head);
    return 0;
}