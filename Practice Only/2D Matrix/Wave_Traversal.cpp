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
    int total=m*n;
    int rows=0,cols=0,rowe=n-1,cole=m-1;
    while(cols<=cole)
    {
        for(int i=rows;i<=rowe&&cols<=cole;i++)
        {
            cout<<arr[i][cols]<<" ";
        }
        cols++;
        for(int i=rowe;i>=rows&&cols<=cole;i--)
        {
            cout<<arr[i][cols]<<" ";
        }
        cols++;
    }
    cout<<endl;
    return 0;
}