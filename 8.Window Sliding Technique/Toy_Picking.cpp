#include <iostream>
using namespace std;

int unique_element(int arr[])
{
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            count++;
    }
    return count;
}

int Max_Toy(string str, int len, int k)
{
    int carr[26] = {0};
    int i = 0, j = 0;
    int maxlen=-1;
    while (j < len)
    {
        carr[str[j] - 'a']++;
        if (unique_element(carr) < k)
        {
            j++;
        }
        else if (unique_element(carr) == k)
        {
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        else if (unique_element(carr) > k)
        {
            while (unique_element(carr) > k)
            {
                carr[str[i] - 'a']--; i++;
            }
            j++;
        }
    }
    return maxlen;
}

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int k;
    cin >> k;
    cout << Max_Toy(str, len, k) << endl;
    return 0;
}