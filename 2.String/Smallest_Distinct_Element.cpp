#include <iostream>
#include <unordered_map>
using namespace std;

string Small_Distinct_Brute(string str)
{
    int len = str.length();
    unordered_map<char, int> umap_1;
    for (int i = 0; i < len; i++)
    {
        umap_1[str[i]]++;
    }
    int distinct = umap_1.size();
    string result;
    int msize = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        int count = 0;
        int varr[256] = {0};
        string substr;
        for (int j = i; j < len; j++)
        {
            if (varr[str[j]] == 0)
            {
                count++;
            }
            varr[str[j]] = 1;
            substr += str[j];
            if (count == distinct)
            {
                break;
            }
        }
        if (substr.length() < msize && count == distinct)
        {
            result = substr;
            msize = substr.length();
        }
    }
    return result;
}

int Count(int arr[])
{
    int distinct = 0;
    for (int i = 0; i < 256; i++)
    {
        if (arr[i] != 0)
            distinct++;
    }
    return distinct;
}

string Small_Distinct_Optimal(string str)
{
    int varr[256] = {0};
    int n = str.length();
    for (int i = 0; i < n; i++)
    {
        varr[str[i]]++;
    }
    int distinct = Count(varr);
    int i = 0, j = 0, msize = INT_MAX;
    string result;
    int farr[256] = {0};
    while (i < n)
    {
        while (i < n&&Count(farr)!=distinct)
        {
            farr[str[i]]++;
            i++;
        }

        while (Count(farr) == distinct)
        {
            if (i-j < msize)
            {
                result = str.substr(j,i-j);
                msize = result.length();
            }
            
            farr[str[j]]--;
            j++;
        }
    }
    return result;
}

int main()
{
    string str;
    getline(cin, str);

    cout << Small_Distinct_Brute(str).length() << endl;
    return 0;
}