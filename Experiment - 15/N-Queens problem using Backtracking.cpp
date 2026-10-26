//Rajni
//25/DA/052

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(vector<string>& board,int row,int col,int n){
    for(int i=0;i<row;i++){
        if(board[i][col]=='Q') return false;
    }

    int i=row-1,j=col-1;
    while(i>=0 && j>=0){
        if(board[i][j]=='Q') return false;
        i--;
        j--;
    }

    i=row-1,j=col+1;
    while(i>=0 && j<n){
        if(board[i][j]=='Q') return false;
        i--;
        j++;
    }

    return true;
}

bool solve(vector<string>& board,int row,int n){
    if(row==n) return true;

    for(int col=0;col<n;col++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';

            if(solve(board,row+1,n)) return true;

            board[row][col]='.';
        }
    }

    return false;
}

int main(){
    int n;
    cout<<"Enter value of N: ";
    cin>>n;

    vector<string> board(n,string(n,'.'));

    if(solve(board,0,n)){
        cout<<"Solution:\n";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else{
        cout<<"No solution exists\n";
    }

    return 0;
}
