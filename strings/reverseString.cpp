#include<iostream>
#include<string.h>
using namespace std;
int main(){
    char arr[10];
    cin.getline(arr,20);
    int j=strlen(arr)-1,i=0;
    while(i<j){
        char t = arr[i];
        arr[i] = arr[j];
        arr[j] = t;
        i++,j--;
    }
    cout<<arr;
    return 0;
}