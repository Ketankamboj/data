#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char arr[10];
    cin.getline(arr,20);
    int j=strlen(arr)-1,i=0,flag=1;
    while(i<j){
        if(arr[i]!=arr[j]){
            flag=0;
            break;
        }
        i++,j--;
    }
    if(flag){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
    return 0;
}