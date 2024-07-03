#include<iostream>
#include<string>
using namespace std;
int main(){
    char arr[20];
    cin.getline(arr,20);
    int i=0;
    while(arr[i]!='\0'){
        if(arr[i]>='A' && arr[i]<='Z'){
            arr[i] += 32;
        }
        i++;
    }
    cout<<arr;
    return 0;
}