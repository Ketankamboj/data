#include<iostream>
#include<string>
using namespace std;
int main(){
    char arr[12];
    //cin>>arr;
    cin.getline(arr,10);
    cout<<arr;
    return 0;
}