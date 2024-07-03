#include<iostream>
#include<string>
using namespace std;

void lastocc(string& str, int i, int j){
    if(i>=j)
    return;

    char ch = str[i];
    str[i] = str[j];
    str[j] = ch;

    lastocc(str, i+1,j-1);
}
int main(){
    string str;
    cout<<"enter the string: ";
    getline(cin,str);
    char ch;
    
    int i=0, j=str.size()-1;
    lastocc(str,i,j);
    cout<<"reversed string is: "<<str;
    return 0;
}