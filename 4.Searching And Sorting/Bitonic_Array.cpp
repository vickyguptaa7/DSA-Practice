#include<iostream>
using namespace std;

int Max_Element(int arr[],int n)
{
    int i=0,j=n-1;
    while(j>=i)
    {
        int mid=i+(j-i)/2;
        if(mid>0&&mid<n)
        {
            if(arr[mid]<arr[mid+1])
            {
                i=mid+1;
            }
            else 
            {
                j=mid-1;
            }
        }
        if(mid==0||mid==n-1)return arr[mid];
    }
    return arr[i];
}

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << Max_Element(arr, n) << endl;
    return 0;
}