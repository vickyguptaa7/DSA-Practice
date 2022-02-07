#include<iostream>
#include<set>
#include<vector>
using namespace std;

void Unique_Subset_Brute(int arr[],int n,set<int>&ans,string str="")
{
    if(n<=0)
    {
        if(str.length()!=0)
        {
            int p=stoi(str);
            ans.insert(p);
        }
        else ans.insert(0);
        return;
    }
    Unique_Subset_Brute(arr+1,n-1,ans,str+to_string(arr[0]));
    Unique_Subset_Brute(arr+1,n-1,ans,str);
}

void Unique_Subset(vector<int>&arr,int ind,vector<int>&ans,vector<vector<int>>&list)
{
    list.push_back(ans);
    for(int i=ind;i<arr.size();i++)
    {
        if(i!=0&&arr[i]==arr[i-1])continue;
        ans.push_back(arr[i]);
        Unique_Subset(arr,i+1,ans,list);
        ans.pop_back();
    }
}

vector<vector<int>> Unique_Subset_Optimal(vector<int> arr)
{
    vector<vector<int>>list;
    vector<int>ans;
    Unique_Subset(arr,0,ans,list);
    return list;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        arr.push_back(num);
    }
    // set<int>ans;
    // Unique_Subset_Brute(arr,n,ans);
    // for(auto x:ans)
    // {
    //     cout<<x<<endl;
    // }
    vector<vector<int>>AnsList=Unique_Subset_Optimal(arr);
    for(int i=0;i<AnsList.size();i++)
    {
        for(int j=0;j<AnsList[i].size();j++)
        {
            cout<<AnsList[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}