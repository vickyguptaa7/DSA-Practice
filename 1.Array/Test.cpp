// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
void Swap(int a1[],int a2[],int i,int j)
{
    int temp=a1[i];
    a1[i]=a2[j];
    a2[j]=temp;
}
void Mergeee(int arr[],int i,int mid,int n)
{
    int p=mid-i+1,q=n-mid;
    int arr1[p],arr2[q];

    for(int j=0;j<p;j++)
    {
        arr1[j]=arr[i+j];
    }
    for(int j=0;j<q;j++)
    {
        arr2[j]=arr[mid+1+j];
    }

    int x=0,y=0,z=i;
    while(p>x&&q>y)
    {
        if(arr1[x]>arr2[y])
        {
            arr[z]=arr2[y];
            y++;z++;
        }
        else
        {
            arr[z]=arr1[x];
            x++;z++;
        }
    }
    while(p>x)
    {
        arr[z]=arr1[x];
            x++;z++;
    }
    while(q>y)
    {
        arr[z]=arr2[y];
            y++;z++;
    }
}

void Merge_Sort(int arr[],int i,int n)
{
    if(n>i)
    {
        int mid=(i+n)/2;
        Merge_Sort(arr,i,mid);
        Merge_Sort(arr,mid+1,n);

        Mergeee(arr,i,mid,n);
        
    }
}

void merge(int arr1[],int arr2[],int n,int m)
{
    int x=0,y=0,k=n-1;
    while(k>x)
    {
        if(arr1[x]<=arr2[y])
        {
            x++;
        }
        else
        {
             Swap(arr1,arr2,k,y);
             k--;
             y++;
        }
    }
    Merge_Sort(arr1,0,n);
    Merge_Sort(arr2,0,m);
}


};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends