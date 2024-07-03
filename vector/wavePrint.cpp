#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>>v{
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    int m=v.size(),n=v[0].size();

    for(int startCol=0; startCol<n; startCol++){
        if(startCol%2==0){
            for(int i=0; i<m; i++){
                cout<<v[i][startCol]<<" ";
            }
        }
        else{
            for(int j=m-1; j>=0; j--){
                cout<<v[j][startCol]<<" ";
            }
        }
    }
    return 0;
}