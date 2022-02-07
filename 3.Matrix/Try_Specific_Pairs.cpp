#include<iostream>
#include<unordered_set>
using namespace std;

int Specific_Pairs_Brute(int **mat,int n,int m) // arr[a][b] and arr[c][d]  c>a d>b
{   // Max Difference 
    int Max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int p=i+1;p<n;p++)
            {
                for(int q=j;q<m;q++)
                {
                    Max=max(Max,mat[p][q]-mat[i][j]);
                }
            }
        }
    }
    return Max;
}

int Specific_Pairs_Optimal(int **mat,int n,int m)
{
    int Max=0;
    return Max;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    int **mat=new int*[n];
    
    for(int i=0;i<n;i++)
    {
        mat[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<Specific_Pairs_Brute(mat,n,m);
    return 0;
}