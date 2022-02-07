#include<iostream>
#include<vector>
using namespace std;

vector<int> Factorial(int N)
{
    vector<int> fact;
    fact.push_back(1);
    for(int i=2;i<=N;i++)
    {
        int j=0;
        int carry=0;
        while(j<fact.size())
        {
            fact[j]=fact[j]*i+carry;
            carry=0;
            if(fact[j]>9)
            {
                carry=fact[j]/10;
                fact[j]=fact[j]%10;
                j++;
                if(fact.size()==j)
                {
                    fact.push_back(0);
                }
            }
            else{j++;}

        }
    }
    return fact;
}

int main(){
    int N;
    cin>>N;

    vector<int> Fact=Factorial(N);

    for(int i=Fact.size()-1;i>=0;i--)
    {
        cout<<Fact[i];
    }
    cout<<endl<<Fact.size()<<endl;
    return 0;
}