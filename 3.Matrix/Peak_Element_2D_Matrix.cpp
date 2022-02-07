#include<iostream>
using namespace std;

int Peak_Element_For_1D_Array(int **mat,int n,int col)
{
    int Max=INT_MIN,mindex=0;
    for(int i=0;i<n;i++)
    {
        if(Max<mat[i][col])
        {
            Max=mat[i][col];
            mindex=i;
        }
    }
    return mindex;
}

int Peak_Element(int **mat,int n,int m)
{
    int i=0,j=m-1;
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        int row=Peak_Element_For_1D_Array(mat,n,mid);
        if(mid-1>=0&&mat[row][mid]<mat[row][mid-1])
        {
            j=mid-1;
        }
        else if(mid+1<n&&mat[row][mid]<mat[row][mid+1])
        {
            i=mid+1;
        }
        else
        {
            return mat[row][mid];
        }
    }
    return -1;
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

    cout<<Peak_Element(mat,n,m)<<endl;

    return 0;
}