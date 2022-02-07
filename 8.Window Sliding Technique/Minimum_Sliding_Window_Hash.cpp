#include<iostream>
#include<unordered_map>
using namespace std;

string Minimum_Substring(string txt,string stxt)
{
    unordered_map<char,int>umap_1,umap_2;
    for(int i=0;i<stxt.length();i++)
    {
        umap_1[stxt[i]]++;
    }
    
    int distinct_count=stxt.length();
    
    int i=0,j=0,minlen=INT_MAX,count=0;
    string res;

    while(i<txt.length())
    {
        while(i<txt.length()&&distinct_count!=count)
        {
            umap_2[txt[i]]++;
            if(umap_2[txt[i]]<=umap_1[txt[i]])
            {
                count++;
            }
            i++;
        }

        while(distinct_count==count)
        {
            if(minlen>i-j)
            {
                res=txt.substr(j,i-j);
                minlen=i-j;
            }
            if(umap_2[txt[j]]==1)
            {
                umap_2.erase(txt[j]);
            }
            else
            {
                umap_2[txt[j]]--;
            }
            if(umap_2[txt[j]]<umap_1[txt[j]])
            count--;
            j++;
        }
    }
    
    return res;
}


int main(){
    string txt,stxt;
    cin>>txt>>stxt;

    cout<<Minimum_Substring(txt,stxt)<<endl;
    return 0;
}