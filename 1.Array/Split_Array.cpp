#include<iostream>
using namespace std;

void Split_Array(int arr[],int n)
{
    int sum_1=0;
    for(int i=0;i<n;i++)
    {
        sum_1+=arr[i];
    }
    if(sum_1%3!=0)
    {
        cout<<-1<<endl;
        return;
    }

    int sum_2=2*(sum_1/3);
    int ind_1=-1,ind_2=-1;
    
    int psum=0;
    for(int i=0;i<n;i++)
    {
        psum+=arr[i];
        if(psum==sum_1/3)
        {
            ind_1=i;
        }
        else if(psum==sum_2)
        {
            ind_2=i;
            break;
        }
    }

    if(ind_1!=-1&&ind_2!=-1) cout<<endl<<"["<<ind_1<<","<<ind_2<<"]"<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    Split_Array(arr,n);

    return 0;
}