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

//searching
bool findNode(node* root, int target){
    if(root == NULL){
        return false;
    }

    if(root->data == target){
        return true;
    }
    if(root->data > target){
        return findNode(root->left, target);
    }
    else{
        return findNode(root->right, target);
    }
}

int main(){
    node* root = NULL;
    takeInput(root);

    bool ans = findNode(root, 155);
    cout<<ans<<endl;
    return 0;
}