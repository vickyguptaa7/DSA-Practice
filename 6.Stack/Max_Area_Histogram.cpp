#include<iostream>
#include<stack>
using namespace std;

int Max_Area_Histogram_Brute(int arr[],int n)
{
    int maxArea=0;
    for(int i=0;i<n;i++)
    {
        int rc=0,lc=0;
        for(int j=i-1;j>=0;j--){if(arr[i]<=arr[j])rc++;else break;}
        for(int j=i+1;j<n;j++){if(arr[i]<=arr[j])rc++;else break;}
        maxArea=max(maxArea,(rc+lc+1)*arr[i]);
    }
    return maxArea;
}

int Max_Area_Histogram(int arr[],int n)
{
    stack<int> st;
    int *nsli=new int[n];
    for(int i=0;i<n;i++) // Nearest Smallest To Left Index
    {
        while(!st.empty()&&arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())nsli[i]=-1;
        else nsli[i]=st.top();
        st.push(i);
    }

    while(!st.empty())st.pop();// Empty The Stack Before Doing Next Operations

    int *nsri=new int[n];
    for(int i=n-1;i>=0;i--) // Nearest Smallest To Right Index
    {
        while(!st.empty()&&arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        if(st.empty())nsri[i]=n;
        else nsri[i]=st.top();
        st.push(i);
    }

    int *width=new int[n];
    for(int i=0;i<n;i++)
    {
        width[i]=nsri[i]-nsli[i]-1;
    }

    int *widthArea=new int[n];
    for(int i=0;i<n;i++)
    {
        widthArea[i]=width[i]*arr[i];
    }

    int MaxArea=0;
    for(int i=0;i<n;i++)
    {
        MaxArea=max(MaxArea,widthArea[i]);
    }
    return MaxArea;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<Max_Area_Histogram(arr,n)<<endl;
    return 0;
}