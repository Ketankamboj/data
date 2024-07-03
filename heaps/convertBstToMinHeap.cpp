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

void inorderTraversal(node* root, vector<int>& inorder){
    if(root == NULL)
        return;

    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void minHeap(node*& root, vector<int> inorder, int index){
    if(root == NULL)
        return;

    root->data = inorder[index++];

    minHeap(root->left, inorder, index);
    minHeap(root->right, inorder, index);
}

int main(){
    node* root = NULL;
    vector<int> inorder;
    inorderTraversal(root,inorder);

    minHeap(root, inorder, 0);
    return 0;
}