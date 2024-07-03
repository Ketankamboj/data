#include<iostream>
#include<vector>
using namespace std;

int findUnique(vector<int> arr){
    int ans=0;
    for(int i=0 ;i<arr.size(); i++){
        ans = ans^arr[i];
    }
    return ans;
}
int main(){
    int n;
    cout<<"enter number of elements in array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"enter the elements"<<endl;

    for(int i=0; i<arr.size(); i++){
        cout<<"enter element at "<<i<<" : ";
        cin>>arr[i];
    }

    int uniqueElement = findUnique(arr);
    cout<<"unique element is: "<<uniqueElement;
    return 0;
}