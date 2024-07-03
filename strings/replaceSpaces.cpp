#include<iostream>
#include<string>
using namespace std;
int main(){
    char arr[10];
    cin.getline(arr,20);
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i]==' '){
            arr[i] = '@';
        }
        i++;
    }
    cout<<arr;
    return 0;
}