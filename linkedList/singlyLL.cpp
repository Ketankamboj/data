#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node (int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node(){
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
    }
};

//insertion at head
void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

//insertion at tail
void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

//insert in middle
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){
        insertAtHead(head,d);
        return;
    }
    
    Node* temp = head;
    int cn=1;
    while(cn < position-1){
        temp = temp->next;
        cn++;
    }
    if(temp->next == NULL){
        insertAtTail(tail,d);
    }

    Node* node2 = new Node(d);
    node2->next = temp->next;
    temp->next = node2;
}

// deleting a node
void deletePosition(Node* &head, int position){
    if(position == 1){
        Node* temp = head;
        head = head->next;
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
        
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

//printing
void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    Node *node1 = new Node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,12);
    insertAtTail(tail,13);
    deletePosition(head,3);
    cout<<tail->data<<" "<<tail->next<<endl;
    print(head);
    return 0;
}