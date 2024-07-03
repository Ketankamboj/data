#include<iostream>
#include<string>
using namespace std;

void lastocc(string& str , char& ch, int i, int& ans){
    if(i >= str.size())
    return;

    if(str[i] == ch){
        ans = i;
    }

    lastocc(str, ch, i+1,ans);
}
int main(){
    int i=0;
    string str;
    cout<<"enter the string: ";
    getline(cin,str);
    char ch;
    cout<<"enter the character: ";
    cin>>ch;

    int ans=-1;
    lastocc(str,ch, i,ans);
    cout<<"last occurence of element is: "<<ans;
    return 0;
}