#include<iostream>
#include<string>
using namespace std;

void permutation(string& str, int i){
    if(i >= str.length()){
        cout<<str<<endl;
        return;
    }

    for(int j=i; j<str.length(); j++){
        //swap
        swap(str[i], str[j]);

        // recursive call
        permutation(str,i+1);

        //backtracking
        swap(str[i], str[j]);
    }
}

int main(){
    string str;
    cout<<"input string: ";
    getline(cin,str);
    int i=0;
    permutation(str,i);
    return 0;
}