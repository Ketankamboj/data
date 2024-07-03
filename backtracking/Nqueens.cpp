#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<vector<char>>& board, int row, int col, int n){
    //check current cell pe queen rakh sakte haa ya nhi
    //check row
    int i=row;
    int j=col;
    while(j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        j--;
    }

    //check upper left diagonal
    i=row;
    j=col;
    while(i>=0 && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i--;
        j--;
    }

    //check bottom left diagonal
    i=row;
    j=col;
    while(i<n && j>=0){
        if(board[i][j] == 'Q'){
            return false;
        }
        i++;
        j--;
    }
    //no queen found
    return true;
}

void printSolution(vector<vector<char>>& board, int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

void solve(vector<vector<char>>& board, int col, int n){
    if(col>=n){
        printSolution(board,n);
        return;
    }

    for(int row=0; row<n; row++){
        //placing queens
        if(isSafe(board,row,col,n)){
        board[row][col] = 'Q';

        //recursive call
        solve(board,col+1,n);

        //backtrack
        board[row][col] = '-';
        }
    }
}

int main(){
    int n;
    cout<<"enter size of board: ";
    cin>>n;
    vector<vector<char> > board(n, vector<char> (n,'-'));
    int col=0;
    solve(board,col,n);
    return 0;
}