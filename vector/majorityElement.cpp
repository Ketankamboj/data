#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,count=0,flag=0,i,j;
    cout<<"enter size of array: ";
    cin>>n;
    int num=n/2;
    vector<int> arr(n);
    for(i=0; i<arr.size(); i++){
        cout<<"enter element at index "<<i<<": ";
        cin>>arr[i];
    }

    for(i=0; i<arr.size(); i++){
        for(j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(num<=count){
            flag=1;
            break;
        }
        else{
            flag=0;
            count=0;
        }
    }

    if(flag==1){
        cout<<arr[i]<<" is majority element.";
    }
    else{
        cout<<"No majority element found in array";
    }
    return 0;
}