#include<iostream>
#include<cmath>
using namespace std;

int Kth_Grammer(int n,int k)
{
    if(n==1&&k==1)
    {
        return 0;
    }
    int mid=pow(2,n-2);
    if(k>mid)
    {
        return !Kth_Grammer(n-1,k-mid);
    }
    else
    {
       return  Kth_Grammer(n-1,k);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    cout<<Kth_Grammer(n,k)<<endl;
    return 0;
}