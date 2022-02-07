#include<iostream>
using namespace std;

int HCF_Brute(int num1,int num2)
{
    int hcf=1,factor=2;
    for(int i=2;i<=min(num1,num2);i++)
    {
        if(num1%i==0&&num2%i==0)
        {
            hcf*=i;
            num1/=i;
            num2/=i;
            i--;
        }
    }
    return hcf;
}

int HCF_Optimal_Recursive(int num1,int num2)
{
    if(num2==0)
    return num1;

    return HCF_Optimal_Recursive(num2,num1%num2);
}

int HCF_Optimal_Iterative(int num1,int num2)
{
    while (num2!=0)
    {
        int rem=num1%num2;
        num1=num2;
        num2=rem;
    }
    return num1;
}

int LCM_Optimal_Iterative(int num1,int num2)
{
    int product=num1*num2;
    while (num2!=0)
    {
        int rem=num1%num2;
        num1=num2;
        num2=rem;
    }
    return product/num1;
}
 
int main(){
    int num1,num2;
    cin>>num1>>num2;


    cout<<LCM_Optimal_Iterative(num1,num2)<<endl;
    return 0;
}