#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int>ans;
    
    if(n<=9&&n>=0)
    {
        cout<<n+10<<endl;
    }
    if(n>=10)
    {
        for(int i=9;i>=2;i--)
        {
            while(n%i==0)
            {
                n/=i;
                ans.push_back(i);
            }
        }
        if(n>10)
        {
            cout<<"Not Possible"<<endl;
        }
        else
        {
            for(int i=ans.size()-1;i>=0;i--)
            {
                cout<<ans[i];
            }
            cout<<endl;
        }
    }
    return 0;
}