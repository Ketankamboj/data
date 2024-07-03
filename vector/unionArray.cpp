#include<iostream>
#include<vector>
#include<limits>
using namespace std;

void Union(vector<int> arr ,vector<int> brr, vector<int> crr){
    //neglecting duplicate element
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<brr.size(); j++){
            if(arr[i]==brr[j]){
                //marking duplicate element
                brr[j] = INT_MIN;
            }
        }
    }


    for(int i=0; i<arr.size(); i++){
        crr.push_back(arr[i]);
    }

    for(int i=0; i<brr.size(); i++){
        if(brr[i] != INT_MIN)
        crr.push_back(brr[i]);
    }

    for(int i=0; i<crr.size(); i++){
        cout<<crr[i]<<" ";
    }
}

int main(){
    int a,b,c;
    cout<<"enter size of first array: ";
    cin>>a;
    cout<<"enter size of second array: ";
    cin>>b;
    //c=a+b;

    vector<int> arr(a);
    vector<int> brr(b);
    vector<int> crr;

    cout<<"enter elements in arr"<<endl;
    for(int i=0; i<arr.size(); i++){
        cout<<"input element at "<<i<<" : ";
        cin>>arr[i];
    }

    cout<<"enter elements in brr"<<endl;
    for(int i=0; i<brr.size(); i++){
        cout<<"input element at "<<i<<" : ";
        cin>>brr[i];
    }

    Union(arr,brr,crr);
    return 0;
}