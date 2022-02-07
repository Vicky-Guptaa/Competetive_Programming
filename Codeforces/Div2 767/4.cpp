#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

bool isPallindrome(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - 1 - i])
            return false;
    }
    return true;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool isTrue = false;
        vector<string> arr(n);
        unordered_set<string> uset;
        unordered_set<string> mset;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            string s = arr[i];
            reverse(s.begin(), s.end());
            if (uset.find(s) != uset.end())
            {
                isTrue = true;
            }
            else
            {
                uset.insert(arr[i]);
            }
            s.pop_back();
            if (uset.find(s) != uset.end() || s.empty() || isPallindrome(arr[i]))
            {
                isTrue = true;
            }
        }
        if (isTrue == false)
            for (int i = n - 1; i >= 0; i--)
            {
                string s = arr[i];
                reverse(s.begin(), s.end());
                s = s.substr(1);
                if (mset.find(s) != mset.end())
                {
                    isTrue = true;
                    break;
                }
                else
                {
                    mset.insert(arr[i]);
                }
            }
        if (isTrue)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}