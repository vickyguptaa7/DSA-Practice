#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    int cols=0,cole=m-1,rows=0,rowe=n-1;
    int total=n*m;
    while(total>0)
    {
        for(int i=cols;i<=cole&&total-->0;i++)
        {
            cout<<arr[rows][i]<<" ";
        }
        rows++;
        for(int i=rows;i<=rowe&&total-->0;i++)
        {
            cout<<arr[i][cole]<<" ";
        }
        cole--;
        for(int i=cole;i>=cols&&total-->0;i--)
        {
            cout<<arr[rowe][i]<<" ";
        }
        rowe--;
        for(int i=rowe;i>=rows&&total-->0;i--)
        {
            cout<<arr[i][cols]<<" ";
        }
        cols++;
    }
    cout<<endl;
    return 0;
}