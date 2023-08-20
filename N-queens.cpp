#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    void f(int col,vector<string>&board,vector<vector<string>>&ans,int n,vector<int>&leftRow, vector<int>&upperDiagonal,vector<int>&lowerDiagonal){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
        if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[(n-1)+ (col-row)]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            lowerDiagonal[row+col]=1;
            upperDiagonal[(n-1) + (col-row)]=1;
            f(col+1,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
            board[row][col]='_';
            leftRow[row]=0;
            lowerDiagonal[row+col]=0;
            upperDiagonal[(n-1) + (col-row)]=0;
        }
    }
    }
public:

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'_');
        for(int i=0;i<n;i++){
            board[i]=s;
        }
        vector<int>leftRow(n,0);
        vector<int>upperDiagonal(2*n-1,0);
        vector<int>lowerDiagonal(2*n-1,0);
        f(0,board,ans,n,leftRow,upperDiagonal,lowerDiagonal);
        return ans;
    }
};

int main(){
    Solution s1;
    int n;
    cout<<"Enter board size : ";
    cin>>n;
    vector<vector<string>>ans=s1.solveNQueens(n);
    for(auto i:ans){
        for(auto j:i){
            cout<<j;
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    return 0;
}