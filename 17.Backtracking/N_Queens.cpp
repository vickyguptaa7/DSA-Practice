#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

bool isSafeQueen(int row,int col,vector<vector<int>>Board)
{
    for(int i=row;i>=0;i--)//checking vertically
    {
        if(Board[i][col]==1)return false;
    }
    for(int i=row,j=col;j<Board.size()&&i>=0;i--,j++)// checking lower diagonal (/)
    {
        if(Board[i][j]==1)return false;
    }
    for(int i=row,j=col;j>=0&&i>=0;i--,j--)  // checking upper diagonal (\)
    {
        if(Board[i][j]==1)return false;
    }
    return true;
}

bool N_Queens(int row,vector<vector<int>>&Board)
{
    if(row==Board.size())return true;
    for(int col=0;col<Board.size();col++)
    {
        if(isSafeQueen(row,col,Board))
        {
            Board[row][col]=1;
            if(N_Queens(row+1,Board))return true;
            Board[row][col]=0;
        }
    }
    return false;
}

void N_Queen_Optimized_Hash(int row,vector<vector<int>>&Board,vector<bool>ldiag,vector<bool>udiag,vector<bool>vertical)
{
    if(row==Board.size())
    {
        for(int i=0;i<Board.size();i++)
        {
            for(int j=0;j<Board.size();j++)
            {
                cout<<Board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"\n";
        return;
    }
    for(int col=0;col<Board.size();col++)
    {
        if(vertical[col]==1||ldiag[col+row]==1||udiag[Board.size()-1+col-row]==1)continue;
        vertical[col]=1;
        ldiag[col+row]=1;
        udiag[Board.size()-1+col-row]=1;
        Board[row][col]=1;
        N_Queen_Optimized_Hash(row+1,Board,ldiag,udiag,vertical);
        vertical[col]=0;
        ldiag[col+row]=0;
        udiag[Board.size()-1+col-row]=0;
        Board[row][col]=0;
    }
}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<bool>vertical(n,0),ldiag(2*n-1),udaig(2*n-1,0);
    N_Queen_Optimized_Hash(0,board,ldiag,udaig,vertical);
    return 0;
}