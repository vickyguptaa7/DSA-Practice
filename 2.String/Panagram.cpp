#include <iostream>
using namespace std;

string missingPanagram(string str)
{

    string ans;
    int j = 0;
    for (int i = 0; i < 26; i++)
    {
        if (i >= j && j < str.length() && (str[j] != 97 + i && str[j] != 65 + i))
            ans += 97 + i;
        else if(j<str.length()&&(str[j] == 97 + i || str[j] == 65 + i)) 
        j++;
        else if(str[j]<97+i)
            ans+=97+i;
    }
    char c=ans[ans.length()-1];
    return ans;
}

int main()
{
    string str;
    cin >> str;
    cout << missingPanagram(str) << endl;
    return 0;
}