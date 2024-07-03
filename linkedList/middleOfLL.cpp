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

int middleNode(Node* &head, int middle){
    Node* temp = head;
    int cnt=0;
    while(cnt < middle){
        temp = temp->next;
        cnt++;
    }
    return temp->data;
}

int length(Node* &head){
    Node* temp = head;
    int count=0;
    while(temp != NULL){
        count++;
        temp = temp->next; 
    }
    cout<<endl;
    return count;
}

int main(){
    Node* a = new Node(3);
    Node* b = new Node(6);
    Node* c = new Node(9);
    a->next = b;
    b->next = c;
    Node* head = a;
    int len = length(head);

    int middle = len/2;

    int ans = middleNode(head, middle);
    cout<<ans<<endl;
    return 0;
}