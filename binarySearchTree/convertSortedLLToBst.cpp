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


node* sortedTree(node* head, int n){
    //base
    if(n<=0 || head == NULL)
        return NULL;

    node* leftTree = sortedTree(head, n-1-n/2);

    node* root = head;
    root->left = leftTree;

    head = head->right;

    //right part
    root->right = sortedTree(head, n/2);
    return root;
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
    sortedTree(head, 8);
    return 0;
}