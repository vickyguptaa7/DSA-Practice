#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

vector<vector<string>> All_Anagrams_Brute(vector<string>string_list)
{
    int n=string_list.size();
    vector<pair<string,int>> nslist(n);
    for(int i=0;i<n;i++)
    {
        nslist[i].first=string_list[i];
        nslist[i].second=i;
        sort(nslist[i].first.begin(),nslist[i].first.end());
    }

    sort(nslist.begin(),nslist.end());
    
    vector<vector<string>>answer;
    int i=1;
    while(i<=n)
    {
        vector<string>anscol;
        while(i<n&&nslist[i-1].first==nslist[i].first)
        {
            anscol.push_back(string_list[nslist[i-1].second]);
            i++;
        }
        anscol.push_back(string_list[nslist[i-1].second]);
        i++;
        answer.push_back(anscol);
    }
    return answer;
}

vector<vector<string>> All_Anagrams_Optimal(vector<string>string_list)
{
    unordered_map<string,vector<string>>umap;
    for(int i=0;i<string_list.size();i++)
    {
        string newstr;
        newstr=string_list[i];
        sort(newstr.begin(),newstr.end());
        umap[newstr].push_back(string_list[i]);
    }
    vector<vector<string>>answer;

    for(auto x:umap)
    {
        answer.push_back(x.second);
    }
    return answer;
}

int main(){
    int n;
    cin>>n;
    cin.ignore();
    vector<string> string_list;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        string_list.push_back(str);
    }
    vector<vector<string>>answer=All_Anagrams_Brute(string_list);
    for(int i=0;i<answer.size();i++)
    {
        for(int j=0;j<answer[i].size();j++)
        {
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}