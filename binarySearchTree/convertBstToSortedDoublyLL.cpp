#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void sortedDll(node* root, node* &head){
    //base case
    if(root == NULL)
        return;

    //right subtree to LL
    sortedDll(root->right, head);

    //attach root node
    root->right = head;
    if(head != NULL){
        head->left = root;
    }

    //update head
    head = root;

    //left part
    sortedDll(root->left,head);
}

node* insertIntoBst(node* root, int data){
    //first node 
    if(root == NULL){
        root = new node(data);
        return root;
    }

    //not first node
    if(root->data > data){
        //insert in left
        root->left = insertIntoBst(root->left, data);
    }
    else{
        //insert in right
        root->right = insertIntoBst(root->right, data);
    }
    return root;
}

void takeInput(node*& root){
    int data;
    cin>>data;

    while(data != -1){
       root = insertIntoBst(root,data);
       cin>>data;
    }
}

int main(){
    node* root = NULL;
    takeInput(root);

    node* head = NULL;
    sortedDll(root, head);
    return 0;
}