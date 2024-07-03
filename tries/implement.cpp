#include<iostream>
using namespace std;

class trie{
    public:
    char data;
    trie* children[26];
    bool isTerminal;

    trie(char d){
        this->data = d;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

void insertWord(trie* root , string word){
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    trie* child;

    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        //not present
        child = new trie(ch);
        root->children[index] = child;
    }

    //recursive call
    insertWord(child, word.substr(1));
}

bool searchWord(trie* root, string word){
    if(word.length() == 0){
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    trie* child;

    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        return false;
    }

    return searchWord(child, word.substr(1));
}

void deleteWord(trie* root, string word){
    if(word.length() == 0){
        root->isTerminal = false;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    trie* child;

    if(root->children[index] != NULL){
        child = root->children[index];
    }
    else{
        cout<<"Given word not exist in trie"<<endl;
        return;
    }

    deleteWord(child, word.substr(1));
}

int main(){
    trie* root = new trie('-');

    insertWord(root, "coding");
    cout<<searchWord(root, "coding")<<endl;
    deleteWord(root, "code");
    cout<<searchWord(root, "coding")<<endl;
    return 0;
}