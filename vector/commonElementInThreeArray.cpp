#include<iostream>
#include<vector>
using namespace std;
void common(vector<int> arr ,vector<int> brr, vector<int> crr){
    int i=0,j=0,k=0;
    while(i<arr.size() && j<brr.size() && k<crr.size()){
        if(arr[i] == brr[j] && brr[j] == crr[k]){
            cout<<arr[i]<<" ";
            i++,j++,k++;
        }
        else if(arr[i]<brr[j]){
            i++;
        }
        else if(brr[j]<crr[k]){
            j++;
        }
        else{
            k++;
        }
    }
}
int main(){
    int a,b,c;
    cout<<"enter size of first array: ";
    cin>>a;
    cout<<"enter size of second array: ";
    cin>>b;
    
    cout<<"enter size of third array: ";
    cin>>c;

    vector<int> arr(a);
    vector<int> brr(b);
    vector<int> crr(c);

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

    cout<<"enter elements in crr"<<endl;
    for(int i=0; i<crr.size(); i++){
        cout<<"input element at "<<i<<" : ";
        cin>>crr[i];
    }

    common(arr,brr,crr);
    return 0;
}