#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

string First_Repeated_Word_Brute(string str)
{
    int len = str.length();
    int i = 0;
    vector<string>svec;
    string newstr="";
    for(int i=0;i<len;i++)
    {
        if(str[i]!=' ')
        {
            newstr+=str[i];
        }
        else
        {
            svec.push_back(newstr);
            newstr="";
        }
    }
    svec.push_back(newstr);
    int size=svec.size();
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(svec[i].compare(svec[j])==0)
            {
                return svec[i];
            }
        }
    }
    return "No Repeatition";
}

string First_Repeated_Word_optimal(string str)
{
    unordered_set<string> uset;
    int i = 0;
    string newstr = "";
    int len = str.length();
    while (i < len)
    {
        while (i < len && str[i] != ' ')
        {
            newstr += str[i];
            i++;
        }
        if (uset.find(newstr) != uset.end())
        {
            return newstr;
        }
        uset.insert(newstr);
        i++;
        newstr = "";
    }
    return "Unique Sentence";
}

int main()
{
    string str;
    getline(cin, str);

    cout << First_Repeated_Word_Brute(str);
    return 0;
}