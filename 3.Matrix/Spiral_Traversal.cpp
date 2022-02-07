#include<iostream>
using namespace std;

void Spiral_Traversal(int **arr,int n,int m)
{
    int cols=0,cole=n-1;
    int rows=0,rowe=m-1;
    int total=n*m;
    int counter=0;
    while(counter<total)
    {
        // top column 
        for(int i=rows;i<=rowe&&counter<total;i++)
        {
            cout<<arr[cols][i]<<" ";
            counter++;
        }
        cols++;
        
        // last row
        for(int i=cols;i<=cole&&counter<total;i++)
        {
            cout<<arr[i][rowe]<<" ";
            counter++;
        }
        rowe--;

        // Last Column
        for(int i=rowe;i>=rows&&counter<total;i--)
        {
            cout<<arr[cole][i]<<" ";
            counter++;
        }
        cole--;

        // First Row
        for(int i=cole;i>=cols&&counter<total;i--)
        {
            cout<<arr[i][rows]<<" ";
            counter++;
        }
        rows++;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];

    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    Spiral_Traversal(arr,n,m);
    return 0;
}