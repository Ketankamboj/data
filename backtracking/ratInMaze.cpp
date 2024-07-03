#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int i, int j, int r, int c, int arr[][5],vector<vector<bool> >& visited){
    if( ((i>=0 && i<r) && (j>=0 && j<c)) && (arr[i][j] == 1) && (visited[i][j]==false)){
        return true;
    }
    else{
        return false;
    }
}

void solveMaze(int arr[][5], int r, int c, int srcx, int srcy,vector<vector<bool> >& visited  ,vector<string>& path ,string output){
    if(srcx==r-1 && srcy==c-1){
        //ans found
        path.push_back(output);
        return;
    }

    //down-> i+1,j
    if(isSafe(srcx+1,srcy,r,c,arr,visited)){
        visited[srcx+1][srcy] = true;
        solveMaze(arr,r,c,srcx+1,srcy,visited,path, output+'D');
        // backtrack
        visited[srcx+1][srcy] = false;
    }

    //left-> i,j-1
    if(isSafe(srcx,srcy-1,r,c,arr,visited)){
        visited[srcx][srcy-1] = true;
        solveMaze(arr,r,c,srcx,srcy-1,visited,path, output+'L');
        // backtrack
        visited[srcx][srcy-1] = false;
    }

    //right-> i,j+1
    if(isSafe(srcx,srcy+1,r,c,arr,visited)){
        visited[srcx][srcy+1] = true;
        solveMaze(arr,r,c,srcx,srcy+1,visited,path, output+'R');
        // backtrack
        visited[srcx][srcy+1] = false;
    }

    //up-> i-1,j
    if(isSafe(srcx-1,srcy,r,c,arr,visited)){
        visited[srcx-1][srcy] = true;
        solveMaze(arr,r,c,srcx-1,srcy,visited,path, output+'U');
        // backtrack
        visited[srcx-1][srcy] = false;
    }
}
int main(){
    int r,c;
    cout<<"enter number of rows: ";
    cin>>r;
    cout<<"enter number of column: ";
    cin>>c;
    int arr[5][5];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cout<<"enter element at index ("<<i<<","<<j<<"): ";
            cin>>arr[i][j];
        }
    }

    if(arr[0][0] == 0){
        cout<<"NO Path Exist"<<endl;
        return 0;
    }
    
    vector<vector<bool> > visited(r, vector<bool>(c,false));
    visited[0][0] = true;

    vector<string> path;
    string output = "";
    
    solveMaze(arr,r,c,0,0,visited,path,output);

    cout<<"printing paths: ";
    for(auto i: path){
        cout<< i <<" ";
    }
    cout<<endl;

    if(path.size() == 0){
        cout<<"NO Path Exist"<<endl;
    }
    return 0;
}