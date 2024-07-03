#include<iostream>
#include<limits.h>
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

class nodeData{
    public:
    int size;
    int minVal;
    int maxVal;
    bool validBst;

    nodeData(){

    }

    nodeData(int size, int max, int min, bool valid){
        this->size = size;
        minVal = min;
        maxVal = max;
        validBst = valid;
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

nodeData findLargestBst(node* root, int& ans){
    if(root == NULL){
        nodeData temp(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    nodeData leftAns = findLargestBst(root->left, ans);
    nodeData rightAns = findLargestBst(root->right, ans);

    //checking
    nodeData currNodeAns;

    currNodeAns.size = leftAns.size + rightAns.size + 1;
    currNodeAns.maxVal = max(root->data, rightAns.maxVal);
    currNodeAns.minVal = min(root->data, leftAns.minVal);

    if(leftAns.validBst && rightAns.validBst && (root->data > leftAns.maxVal && root->data < rightAns.minVal)){
        currNodeAns.validBst = true;
    }
    else{
        currNodeAns.validBst = false;
    }

    if(currNodeAns.validBst){
        ans = max(ans, currNodeAns.size);
    }
    return currNodeAns;
}

int main(){
    node* root = NULL;
    takeInput(root);

    return 0;
}