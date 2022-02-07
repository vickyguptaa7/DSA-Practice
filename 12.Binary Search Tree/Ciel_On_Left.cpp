#include<iostream>
#include<vector>
#include<set>
using namespace std;

vector<int> Ciel_To_Left_Brute(int arr[],int n)
{
    vector<int>ans;
    ans.push_back(-1);
    for(int i=1;i<n;i++)
    {
        int Diff=INT_MAX,Ciel=-1;
        for(int j=0;j<i;j++)
        {
            int Calc=arr[j]-arr[i];
            if(Calc>=0&&Calc<Diff)
            {
                Diff=Calc;
                Ciel=arr[j];
            }
        }
        ans.push_back(Ciel);
    }
    return ans;
}

vector<int> Ciel_To_Left_Opt(int arr[],int n)
{
    vector<int>ans;
    ans.push_back(-1);
    set<int>s;
    s.insert(arr[0]);
    for(int i=1;i<n;i++)
    {
        auto it=s.lower_bound(arr[i]);
        if(it==s.end())ans.push_back(-1);
        else ans.push_back(*it);
        s.insert(arr[i]);
    }
    return ans;
}


void Print(vector<int>arr)
{
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    Print(Ciel_To_Left_Opt(arr,n));
    return 0;
}