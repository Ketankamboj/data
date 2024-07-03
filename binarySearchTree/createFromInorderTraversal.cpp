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

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL); //seprator

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

node* bstUsingInorder(int inorder[], int s, int e){
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    int element = inorder[mid];

    node* root= new node(element);

    root->left = bstUsingInorder(inorder, s, mid-1);
    root->right = bstUsingInorder(inorder, mid+1, e);

    return root;
}


int main(){
    int inorder[] = {1,2,3,4,5,6,7,8,9};
    int s=0;
    int e = 8;

    node* root = bstUsingInorder(inorder, s,e);

    cout<<"printing the tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}