#include<iostream>
#include<string>
using namespace std;

int find(string& str, char& ch, int i){
    if(i>=str.length()){
        return -1;
    }

    if(ch == str[i]){
        return i;
    }

    return find(str,ch,i+1);
}

int main(){
    string str;
    cout<<"input string: ";
    getline(cin,str);

    char ch;
    cout<<"input character to search: ";
    cin>>ch;

    int i=0;
    int ans = find(str,ch,i);

    if(ans==-1){
        cout<<"key not found";
    }
    else{
        cout<<"key found at index: "<<ans<<endl;
    }
    return 0;
}