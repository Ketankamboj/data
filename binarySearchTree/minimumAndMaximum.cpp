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

int minVal(node* root){
    node* temp = root;
    if(temp == NULL){
        return 0;
    }

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp->data;
}

int maxVal(node* root){
    node* temp = root;

    if(temp == NULL){
        return 0;
    }

    while(temp->right != NULL){
        temp = temp->right;
    }
    return temp->data;
}

int main(){
    node* root = NULL;
    takeInput(root);

    cout<<"minimum value is: "<<minVal(root)<<endl;
    cout<<"maximum value is: "<<maxVal(root)<<endl;
    return 0;
}