#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr;

    //no of elements present in array
    cout<<arr.size()<<endl;

    //no of elements can be stored in array
    cout<<arr.capacity()<<endl;

    //insert element
    arr.push_back(4);
    arr.push_back(5);

    // printing
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    //deleting
    arr.pop_back();

    // printing
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    // more dynamic
    int n;
    cout<<"enter value of n: ";
    cin>>n;

    vector<int> brr(n,-1);

    //no of elements present in array
    cout<<brr.size()<<endl;

    //no of elements can be stored in array
    cout<<brr.capacity()<<endl;

    // printing
    for(int i=0; i<brr.size(); i++){
        cout<<brr[i]<<" ";
    }
    cout<<endl;

    //to check empty
    cout<<arr.empty();
    return 0;
}