#include<iostream>
#include<vector>
using namespace std;

int binary(vector<int>& v, int s, int e, int& key){
    if(s>e)
        return -1;

    int mid = s + (e-s)/2;

    if(v[mid] == key){
        return mid;
    }

    if(v[mid] < key){
        return binary(v, mid+1, e, key);
    }
    else{
        return binary(v, s, mid-1, key);
    }
}

int main(){
    int n,target;
    cout<<"enter size of array: ";
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cout<<"input element at index "<<i<<": ";
        cin>>v[i];
    }

    cout<<"enter the target value: ";
    cin>>target;

    int s=0,e=n-1;

    int ans = binary(v,s,e,target);
    cout<<"target present at index "<<ans;
    return 0;
}