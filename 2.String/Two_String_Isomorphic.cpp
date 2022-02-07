#include<iostream>
#include<unordered_map>
using namespace std;

string isIsomorphic_Brute(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();
    if(n1!=n2)return "Not";
    for(int i=0;i<n1;i++)
    {
        for(int j=0;j<n1;j++)
        {
            if(str1[i]==str1[j]||str2[i]==str2[j])
            {
                if(str2[i]!=str2[j]||str1[i]!=str1[j])
                return "No";
            }
        }
    }
    return "Yes";
}

string isIsomorphic_Optimal(string str1,string str2)
{
    int n1=str1.length();
    int n2=str2.length();
    if(n1!=n2)return "Not";
    unordered_map<char,int>umap_1,umap_2;
    for(int i=0;i<n1;i++)
    {
        umap_1[str1[i]]++;
        umap_2[str2[i]]++;
        if(umap_1[str1[i]]!=umap_2[str2[i]])
        return "No";
    }
    return "Yes";
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    
    cout<<isIsomorphic_Optimal(str1,str2)<<endl;
    return 0;
}