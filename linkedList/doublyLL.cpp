#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node (int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

void insertAtHead(Node* &head, Node* &tail, int value){
    if(head == NULL){
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(value);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &head, Node* &tail, int value){
     if(head == NULL){
        Node* temp = new Node(value);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(value);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head,tail,d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAtTail(head,tail,d);
        return;
    }

    Node* n = new Node(d);
    n->next = temp->next;
    temp->next->prev = n;
    temp->next = n;
    n->prev = temp;
}

void deletePosition(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt=1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void getLength(Node* &head){
    Node* temp = head;
    int count = 0;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    cout<<count<<endl;
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
    Node* a = new Node(10);
    Node* b = new Node(11);
    a->prev = NULL;
    a->next = b;
    b->prev = a;
    b->next = NULL;
    Node* head = a;
    Node* tail = b;
    
    insertAtHead(head,tail,9);
    insertAtTail(head,tail,12);
    insertAtPosition(head,tail,3,13);
    deletePosition(head,3);
    getLength(head);
    print(head);
    return 0;
}