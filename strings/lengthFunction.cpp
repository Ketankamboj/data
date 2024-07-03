#include<iostream>
#include<string>
using namespace std;
int main(){
    char arr[10];
    cin.getline(arr,20);
    int length=0,i=0;
    while(arr[i]!='\0'){
        i++;
        length++;
    }
    cout<<length;
    return 0;
}