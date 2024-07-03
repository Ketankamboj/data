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

void preOrder(node* root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node* root){
    if(root == NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL){
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

node* findNode(node* root, int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        return root;
    }
    if(root->data > target){
        return findNode(root->left, target);
    }
    else{
        return findNode(root->right, target);
    }
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

node* deleteIntoBst(node* root, int target){
    if(root == NULL)
        return NULL;

    if(root->data == target){
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        else if(root->left == NULL && root->right != NULL){
            node* child =  root->right;
            delete root;
            return child;
        }
        else if(root->left != NULL && root->right == NULL){
            node* child = root->left;
            delete root;
            return child;
        }
        else{
            //finding inorder predecessor in left sub tree
            int inorderPre = maxVal(root->left);
            //replace root->data with inorder pre
            root->data = inorderPre;
            root->left = deleteIntoBst(root->left, inorderPre);
            return root;
        }
    }
    else if(target > root->data){
        root->right = deleteIntoBst(root->right, target);
    }
    else if(target < root->data){
        root->left = deleteIntoBst(root->left, target);
    }

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

    deleteIntoBst(root, 100);

    cout<<"printing the tree"<<endl;
    levelOrderTraversal(root);
    return 0;
}