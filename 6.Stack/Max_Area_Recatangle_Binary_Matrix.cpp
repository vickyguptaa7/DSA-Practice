#include<iostream>
#include<stack>
using namespace std;

int Max_Area_Histogram(int arr[],int n)
{
    stack<int> st;
    int *ans=new int[n];

    // Next Smaller To Left
    for(int i=0;i<n;i++)
    {
        while(!st.empty()&&arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())ans[i]=-1;
        else ans[i]=st.top();
        st.push(i);
    }

    // Empty Stack 
    while(!st.empty())st.pop();

    // Next Smaller To Right And Width Calc
    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty()&&arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())ans[i]=n-ans[i]-1;
        else ans[i]=st.top()-ans[i]-1;
        st.push(i);
    }

    int maxArea=0;
    for(int i=0;i<n;i++)
    {
        ans[i]*=arr[i];
        maxArea=max(maxArea,ans[i]);
    }
    delete[] ans;
    return maxArea;
}

int Max_Area_Recatangle_Binary_Matrix(int **darr,int n,int m)
{
    int *oarr=new int[m];
    for(int i=0;i<m;i++)oarr[i]=0;
    int maxArea=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(darr[i][j]==1)oarr[j]++;
            else oarr[j]=0;
        }
        maxArea=max(maxArea,Max_Area_Histogram(oarr,m));
    }
    delete[] oarr;
    return maxArea;
}

int main(){
    int n,m;
    cin>>n>>m;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[m];
        for(int j=0;j<m;j++)
        cin>>arr[i][j];
    }

    cout<<Max_Area_Recatangle_Binary_Matrix(arr,n,m)<<endl;
    return 0;
}