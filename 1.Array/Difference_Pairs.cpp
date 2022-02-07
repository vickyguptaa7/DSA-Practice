#include<iostream>
#include<algorithm>
using namespace std;

int Pairs(int arr[],int n,int dif)
{
    sort(arr,arr+n);
    int i=0,j=1;
    int count=0;
    while(j<n)
    {
        if(arr[j]-arr[j]>dif)
        {
            i++;
        }
        else if(arr[j]-arr[i]<dif)
        {
            j++;
        }
        else
        {
            if(i!=j)
            {
                cout<<"["<<arr[i]<<","<<arr[j]<<"] ";
                count++;
            }
            j++;
        }
    }   
    return count;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dif;
    cin>>dif;
    cout<<endl<<Pairs(arr,n,dif)<<endl;
    return 0;
}
// 1 2 3 4 7 