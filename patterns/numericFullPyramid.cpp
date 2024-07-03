//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            cout<<"  ";
        }
        int start=i+1;
        for(int j=0; j<i+1; j++){
            cout<<start<<" ";
            start++;
        }
        int st = 2*i;
        for(int j=0; j<i; j++){
            cout<<st<<" ";
            st--;
        }
        cout<<endl;
    }
    return 0;
}